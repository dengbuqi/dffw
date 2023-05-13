from dffw_msgs.msg import *
from dffw.dataconvert import *
from dffw.common import *
import rclpy
import torch

from torchvision.datasets import MNIST
from torchvision.transforms import Compose, ToTensor, Normalize, Lambda
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

def overlay_y_on_x(x, y):
    """Replace the first 10 pixels of data [x] with one-hot-encoded label [y]
    """
    x_ = x.clone()
    x_[:, :10] *= 0.0
    x_[range(x.shape[0]), y] = x.max()
    return x_

def save_visualize_sample(i, data, gt,name='', path='/root/output'):
    reshaped = data.reshape(28, 28)
    gt = gt.item()
    plt.figure(figsize = (4, 4))
    plt.title(f'GT:{gt} | Prediction:{name}')
    plt.imshow(reshaped, cmap="gray")
    plt.savefig(f'{path}/{i}.png')
    plt.close()
class MasterRunner(object):
    def __init__(self, node, model_layers):
        torch.manual_seed(1234)
        self.node = node
        self.model_layers = model_layers
        train_loader, test_loader = MNIST_loaders()
        self.x, self.y = next(iter(train_loader))
        self.x_pos = overlay_y_on_x(self.x, self.y)
        rnd = torch.randperm(self.x.size(0))
        self.x_neg = overlay_y_on_x(self.x, self.y[rnd])
        self.x_te, self.y_te = next(iter(test_loader))

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
            self.node.get_logger().info(ml['inferenceOut']['name'][0])
            self.Fsub.append(
                        self.node.create_subscription(
                                            eval(ml['inferenceOut']['type'][0]), 
                                            ml['inferenceOut']['name'][0],
                                            self.forwardcallback,
                                            10)
        )
        self.train_time = 0
        self.goodness = []
        self.goodness_per_label = []
        self.runlabel = True

    def traincallback(self, msg):
        # h_pos, h_neg = TFmsg2tensor(msg)
        self.train_time += 1
        self.node.get_logger().info(f'Train {self.train_time} times!')
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
        for label in range(10):
            self.node.get_logger().info(f'generate {label}')
            h = overlay_y_on_x(x, label)
            self.predict_once(h)
        self.goodness_per_label = torch.cat(self.goodness_per_label, 1)
        return self.goodness_per_label.argmax(1)
    
    def run(self):
        # train model
        # self.node.get_logger().info('Train model starting!')
        # self.train(self.x_pos, self.x_neg)
        self.node.get_logger().info('Predict text data starting!')
        result = self.predict(self.x_te)
        self.node.get_logger().info(f'test error: {1.0 - result.eq(self.y_te).float().mean().item()}')
        self.goodness_per_label = None
        for i in range(100):
            save_visualize_sample(i, self.x_te[i], self.y_te[i], result[i])

