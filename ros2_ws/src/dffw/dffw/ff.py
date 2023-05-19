from dffw_msgs.msg import *
from dffw.dataconvert import *
from dffw.common import *
import rclpy
import torch
from tqdm import tqdm

from torchvision.datasets import MNIST, CIFAR10
from torchvision.transforms import Compose, ToTensor, Normalize, Lambda, ToPILImage
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt

def MNIST_loaders(train_batch_size=50000, test_batch_size=10000):

    transform = Compose([
        ToTensor(),
        Normalize((0.1307,), (0.3081,)),
        Lambda(lambda x: torch.flatten(x))])

    train_loader = DataLoader(
              MNIST('/workspace/data/', train=True,
              download=True,
              transform=transform),
              batch_size=train_batch_size, 
              shuffle=True)

    test_loader = DataLoader(
              MNIST('/workspace/data/', 
              train=False,
              download=True,
              transform=transform),
              batch_size=test_batch_size, 
              shuffle=False)

    return train_loader, test_loader


def CIFAR10_loaders(train_batch_size=50000, test_batch_size=10000):
    transform = Compose([
        ToTensor(),
        Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

    train_loader = DataLoader(
              CIFAR10('/workspace/data/', train=True,
              download=True,
              transform=transform),
              batch_size=train_batch_size, 
              shuffle=True)

    test_loader = DataLoader(
              CIFAR10('/workspace/data/', 
              train=False,
              download=True,
              transform=transform),
              batch_size=test_batch_size, 
              shuffle=False)

    return train_loader, test_loader

def overlay_y_on_x(x, y, lable_num):
    """Replace the first 10 pixels of data [x] with one-hot-encoded label [y]
    """
    x_ = x.clone()
    sp = x.shape
    x_ = x_.view(sp[0], -1)
    x_[:, :lable_num] *= 0.0
    x_[range(x.shape[0]), y] = x.max()
    return x_.view(*sp)

def save_visualize_sample(i, shape, data, gt, pred='', path='/root/output', labels=None):
    reshaped = data.reshape(*shape)
    gt = gt.item()
    if labels is not None:
        try:
            gt = labels[gt]
            pred = labels[pred]
        except Exception as e:
            print('labels error', e)

    plt.figure(figsize = (4, 4))
    plt.title(f'GT:{gt} | Prediction:{pred}')
    if len(shape) == 2:
        plt.imshow(reshaped, cmap="gray")
    if len(shape) == 3:
        plt.imshow(reshaped.permute(1, 2, 0))
    plt.savefig(f'{path}/{i}.png')
    plt.close()

def gen_train_data(x,y,lable_num):
    x_pos = overlay_y_on_x(x, y, lable_num)
    rnd = torch.randperm(x.size(0))
    x_neg = overlay_y_on_x(x, y[rnd], lable_num)
    return x_pos, x_neg


class MasterRunner(object):
    def __init__(self, 
                 node, 
                 model_layers, 
                 data_set,
                 epochs=1000, 
                 train_type='one_shot',  
                 batch_size=-1
                 ):
        '''
        data_set = 'MNIST', 'CIFAR10'
        train_type = 'one_shot' | epochs_shot
        '''
        torch.manual_seed(1234)
        self.epochs=epochs
        self.train_type=train_type 
        self.batch_size=batch_size
        self.node = node
        self.model_layers = model_layers
        self.lable_num = len(self.node.mj2dis.model_json['labels'])
        if data_set == 'MNIST':
            # train_loader, test_loader = MNIST_loaders()
            Data_loaders = MNIST_loaders
            self.shape = (28,28)
        elif data_set == 'CIFAR10':
            # train_loader, test_loader = CIFAR10_loaders()
            Data_loaders = CIFAR10_loaders
            self.shape = (3,32,32)

        else:
            raise ValueError

        if self.train_type=='one_shot':
            train_loader, test_loader = Data_loaders()
            self.x, self.y = next(iter(train_loader))
            self.x_pos, self.x_neg = gen_train_data(self.x, self.y,self.lable_num)
            self.x_te, self.y_te = next(iter(test_loader))
        else:
            self.train_loader, self.test_loader = Data_loaders(batch_size,batch_size)
        
        self.Tpub = self.node.create_publisher(
                                            eval(self.model_layers[0]['trainInp']['type'][0]), 
                                            self.model_layers[0]['trainInp']['name'][0], 
                                            10)
        self.Tsub = self.node.create_subscription(
                                            eval(self.model_layers[-1]['trainOut']['type'][0]), 
                                            self.model_layers[-1]['trainOut']['name'][0],
                                            self.traincallback,
                                            10)
        
        self.Fpub = self.node.create_publisher(
                                            eval(self.model_layers[0]['inferenceInp']['type'][0]), 
                                            self.model_layers[0]['inferenceInp']['name'][0], 
                                            10)
        self.Fsub = []
        for ml in self.model_layers:
            if ml['goodness']:
                # self.node.get_logger().info(ml['inferenceOut']['name'][0])
                self.Fsub.append(
                            self.node.create_subscription(
                                                eval(ml['inferenceOut']['type'][0]), 
                                                ml['inferenceOut']['name'][0],
                                                self.forwardcallback,
                                                10)
                )
        self.goodness = []
        self.goodness_per_label = []
        self.runlabel = True
        self.train_time = 0

    def traincallback(self, msg):
        # h_pos, h_neg = TFmsg2tensor(msg)
        self.train_time += 1
        # self.node.get_logger().info(f'Train {self.train_time} times!')
        self.runlabel = False
    
    def forwardcallback(self, msg):
        _,good = IFmsg2tensor(msg)
        self.goodness.append(good)
        if len(self.goodness) == len(self.Fsub):
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
        for label in range(self.lable_num):
            # self.node.get_logger().info(f'generate {label}')
            h = overlay_y_on_x(x, label, self.lable_num)
            self.predict_once(h)
        self.goodness_per_label = torch.cat(self.goodness_per_label, 1)
        return self.goodness_per_label.argmax(1)
    
    def run(self):
        # train model
        self.node.get_logger().info('Train model starting!')
        if self.train_type=='one_shot':
            self.train(self.x_pos, self.x_neg)
        else:
            
            for e in range(self.epochs):
                tbar = tqdm(self.train_loader)
                tbar.set_description(f'Epoch {e+1}/{self.epochs}')
                for x,y in tbar:
                    x_pos, x_neg = gen_train_data(x, y, self.lable_num)
                    self.train(x_pos, x_neg)
        
        self.node.get_logger().info('Predict test data starting!')
        if self.train_type=='one_shot':
            x_tes, y_tes = self.x_te, self.y_te 
            results = self.predict(self.x_te)
            # self.node.get_logger().info(f'test error: {1.0 - results.eq(self.y_te).float().mean().item()}')
            self.goodness_per_label = []
        else:
            results = []
            x_tes = []
            y_tes = []
            tbar = tqdm(self.test_loader)
            for x_te,y_te in tbar:
                x_tes +=x_te 
                y_tes +=y_te 
                results += self.predict(x_te)
                self.goodness_per_label = []
            x_tes = torch.stack(x_tes)
            y_tes = torch.stack(y_tes)
            results = torch.stack(results)
        self.node.get_logger().info(f'test error: {1.0 - results.eq(y_tes).float().mean().item()}')

        self.node.get_logger().info('Save 100 prediction results!')
        for i in range(100):
            save_visualize_sample(i, x_tes[i].shape, x_tes[i], y_tes[i], results[i]
                                  , labels=self.node.mj2dis.model_json['labels'])
        self.node.get_logger().info('Training Finished!')
        

