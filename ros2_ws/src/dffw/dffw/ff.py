from dffw_msgs.msg import TrainForward, InferanceForward
from dffw.dataconvert import TFmsg2tensor, TFtensor2msg, IFmsg2tensor, IFtensor2msg
import rclpy
import torch
from torchvision.datasets import MNIST
from torchvision.transforms import Compose, ToTensor, Normalize, Lambda
from torch.utils.data import DataLoader

class LayerRunner(object):
    def __init__(self, layer, 
                       nodeid=0,
                       num_epochs=1000,
                       is_cuda=True):
        self.node = rclpy.create_node(f'layer_{nodeid}')
        self.Tsub = self.node.create_subscription(
                                            TrainForward,
                                            f'train_ff_{nodeid}',
                                            self.traincallback,
                                            10)
        
        self.Tpub = self.node.create_publisher(
                                            TrainForward, 
                                            f'train_ff_{nodeid+1}', 
                                            10)
        self.Fsub = self.node.create_subscription(
                                            InferanceForward,
                                            f'forward_ff_{nodeid}',
                                            self.forwardcallback,
                                            10)
        
        self.Fpub = self.node.create_publisher(
                                            InferanceForward, 
                                            f'forward_ff_{nodeid+1}', 
                                            10)
        self.layer = layer
        if is_cuda:
            self.layer = self.layer.cuda()
        self.num_epochs = num_epochs
        self.is_cuda = is_cuda

    def traincallback(self, msg):
        h_pos, h_neg = TFmsg2tensor(msg)
        if self.is_cuda:
            h_pos = h_pos.cuda()
            h_neg = h_neg.cuda()
        h_pos, h_neg = self.layer.train(h_pos, h_neg, self.num_epochs)
        msg = TrainForward()
        msg = TFtensor2msg(h_pos, h_neg)
        self.Tpub.publish(msg)
    
    def forwardcallback(self, msg):
        h,_ = IFmsg2tensor(msg)
        if self.is_cuda:
            h = h.cuda()
        h = self.layer.forward(h)
        goodness = h.pow(2).mean(1)
        if self.is_cuda:
            h = h.cpu()
            goodness = goodness.cpu()
        msg = InferanceForward()
        msg =  IFtensor2msg(h, goodness)
        self.Fpub.publish(msg)

    def run(self):
        rclpy.spin(self.node)
    
    def destroy(self):
        self.node.destroy_node()

def MNIST_loaders(train_batch_size=50000, test_batch_size=10000):

    transform = Compose([
        ToTensor(),
        Normalize((0.1307,), (0.3081,)),
        Lambda(lambda x: torch.flatten(x))])

    train_loader = DataLoader(
        MNIST('/workspace/data/', train=True,
              download=True,
              transform=transform),
        batch_size=train_batch_size, shuffle=True)

    test_loader = DataLoader(
        MNIST('/workspace/data/', train=False,
              download=True,
              transform=transform),
        batch_size=test_batch_size, shuffle=False)

    return train_loader, test_loader


def overlay_y_on_x(x, y):
    """Replace the first 10 pixels of data [x] with one-hot-encoded label [y]
    """
    x_ = x.clone()
    x_[:, :10] *= 0.0
    x_[range(x.shape[0]), y] = x.max()
    return x_

class MasterRunner(object):
    def __init__(self):
        torch.manual_seed(1234)
        train_loader, test_loader = MNIST_loaders()
        self.x, self.y = next(iter(train_loader))
        self.x_pos = overlay_y_on_x(self.x, self.y)
        rnd = torch.randperm(self.x.size(0))
        self.x_neg = overlay_y_on_x(self.x, self.y[rnd])
        self.x_te, self.y_te = next(iter(test_loader))


        self.node = rclpy.create_node(f'master')
        self.Tsub = self.node.create_subscription(
                                            TrainForward,
                                            f'train_ff_2',
                                            self.traincallback,
                                            10)
        
        self.Tpub = self.node.create_publisher(
                                            TrainForward, 
                                            f'train_ff_0', 
                                            10)
        
        self.Fpub = self.node.create_publisher(
                                            InferanceForward, 
                                            f'forward_ff_0', 
                                            10)


        self.Fsub1 = self.node.create_subscription(
                                            InferanceForward,
                                            f'forward_ff_1',
                                            self.forwardcallback,
                                            10)
        
 
        self.Fsub2 = self.node.create_subscription(
                                            InferanceForward,
                                            f'forward_ff_2',
                                            self.forwardcallback,
                                            10)
        
        self.train_time = 0

        self.goodness = []
        self.goodness_per_label = []
        self.runlabel = True

    def traincallback(self, msg):
        # h_pos, h_neg = TFmsg2tensor(msg)
        self.train_time += 1
        print(f'Train {self.train_time} times!')
        self.runlabel = False
    
    def forwardcallback(self, msg):
        _,good = IFmsg2tensor(msg)
        self.goodness.append(good)
        if len(self.goodness) == 2:
            self.goodness_per_label += [sum(self.goodness).unsqueeze(1)]
            self.goodness = []
            self.runlabel = False

    
    def train(self, x_pos, x_neg):
        self.runlabel = True
        msg = TrainForward()
        msg = TFtensor2msg(x_pos, x_neg)
        self.Tpub.publish(msg)
        while (rclpy.ok() and self.runlabel):
            rclpy.spin_once(self.node)

    def predict_once(self, h):
        self.runlabel = True
        msg = InferanceForward()
        msg = IFtensor2msg(h, torch.zeros([0]))
        self.Fpub.publish(msg)
        while (rclpy.ok() and self.runlabel):
            rclpy.spin_once(self.node)

    def predict(self, x):
        for label in range(10):
            print('generate', label)
            h = overlay_y_on_x(x, label)
            self.predict_once(h)
        self.goodness_per_label = torch.cat(self.goodness_per_label, 1)
        return self.goodness_per_label.argmax(1)
    
    def run(self):
        # train model
        print('Train model starting!')
        self.train(self.x_pos, self.x_neg)

        # print('Predict train data starting!')
        # print(f'train error:', 1.0 - self.predict(self.x).eq(self.y).float().mean().item())
        # self.goodness_per_label = None

        print('Predict text data starting!')
        print(f'test error:', 1.0 - self.predict(self.x_te).eq(self.y_te).float().mean().item())
        self.goodness_per_label = None


    def destroy(self):
        self.node.destroy_node()
