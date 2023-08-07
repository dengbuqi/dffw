from dffw_msgs.msg import *
from dffw.dataconvert import *
from dffw.common import *
from dffw.utils import create_negative_image
import rclpy
import torch
from tqdm import tqdm
import os

from torchvision.datasets import MNIST, CIFAR10
from torchvision.transforms import Compose, ToTensor, Normalize, Lambda, ToPILImage
from torch.utils.data import DataLoader
import torch.nn as nn 
# from torch.nn import Linear

import matplotlib.pyplot as plt
MODEL_WEIGHT_ROOT_PATH = '/root/weight'
def create_supervised_train_data(train_dataset, dataset_name):
    n_train_samples = len(train_dataset)
    if not os.path.exists(f'/workspace/data/{dataset_name}.pt'):
        random_pairs = np.random.randint(n_train_samples, size=[n_train_samples, 2])
        random_pairs = [(row[0], row[1]) for row in random_pairs]
        # Transform the data
        print(f'Transform the <{dataset_name}> data')
        transformed_dataset = [
            create_negative_image(train_dataset[pair[0]][0].squeeze(), train_dataset[pair[1]][0].squeeze())
            for pair in tqdm(random_pairs)]

        # Save the transformed images to a folder
        torch.save(transformed_dataset, f'/workspace/data/{dataset_name}.pt')

class ConcatDataset(torch.utils.data.Dataset):
    def __init__(self, *datasets):
        self.datasets = datasets

    def __getitem__(self, i):
        return tuple(d[i] for d in self.datasets)

    def __len__(self):
        return min(len(d) for d in self.datasets)

def MNIST_loaders(train_batch_size=50000, test_batch_size=10000, supervised=True):
    transform = Compose([
            ToTensor(),
            Normalize((0.1307,), (0.3081,)),
            Lambda(lambda x: torch.flatten(x))])

    to_t = Compose([ToTensor()])
    trans_f = Compose([Lambda(lambda x: torch.flatten(x))])
    
    test_loader = DataLoader(
                MNIST('/workspace/data/', 
                train=False,
                download=True,
                transform=transform),
                batch_size=test_batch_size, 
                shuffle=False)
    if supervised:
        train_loader = DataLoader(
                MNIST('/workspace/data/', train=True,
                download=True,
                transform=transform),
                batch_size=train_batch_size, 
                shuffle=True)
    else:
        pos_dataset = MNIST('/workspace/data/', 
                            train=True, 
                            download=True, 
                            transform=transform)
        to_d = MNIST('/workspace/data/', 
                            train=True, 
                            download=True, 
                            transform=to_t)
        create_supervised_train_data(to_d, 
                                    'MNIST')
        neg_dataset = torch.load('/workspace/data/MNIST.pt')
        neg_dataset = [trans_f(neg) for neg in neg_dataset]
        train_loader = DataLoader(
                        ConcatDataset(pos_dataset, neg_dataset),
                        batch_size=train_batch_size, 
                        shuffle=True)
        
    return train_loader, test_loader

def CIFAR10_loaders(train_batch_size=50000, test_batch_size=10000, supervised=True):
    transform = Compose([
        ToTensor(),
        Lambda(lambda x: torch.flatten(x))
        ])
    to_t = Compose([ToTensor()])
    trans_f = Compose([
        Lambda(lambda x: torch.flatten(x))
        ])
    test_loader = DataLoader(
                CIFAR10('/workspace/data/', 
                train=False,
                download=True,
                transform=transform),
                batch_size=test_batch_size, 
                shuffle=False)
    
    if supervised:
        train_loader = DataLoader(
                CIFAR10('/workspace/data/', train=True,
                download=True,
                transform=transform),
                batch_size=train_batch_size, 
                shuffle=True)
    else:
        pos_dataset = CIFAR10('/workspace/data/', 
                            train=True,
                            download=True,
                            transform=transform)
        to_d = CIFAR10('/workspace/data/', 
                            train=True, 
                            download=True, 
                            transform=to_t)
        create_supervised_train_data(to_d, 
                                    'CIFAR10')
        neg_dataset = torch.load('/workspace/data/CIFAR10.pt')
        neg_dataset = [trans_f(neg) for neg in neg_dataset]
        train_loader = DataLoader(
                        ConcatDataset(pos_dataset, neg_dataset),
                        batch_size=train_batch_size, 
                        shuffle=True)
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
                 batch_size=-1,
                 is_cuda = False
                 ):
        '''
        data_set = 'MNIST', 'CIFAR10'
        train_type = 'one_shot' | epochs_shot | batch_shot
        '''
        torch.manual_seed(1234)
        self.epochs=epochs
        self.train_type=train_type
        self.batch_size=batch_size
        self.node = node
        self.model_layers = model_layers
        self.supervised = self.node.mj2dis.model_json['supervised'] == 'True'
        self.lable_num = len(self.node.mj2dis.model_json['labels'])
        self.is_cuda = is_cuda
        self.data_set = data_set
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
            train_loader, test_loader = Data_loaders(supervised=self.supervised)
            if self.supervised:
                self.x, self.y = next(iter(train_loader))
                self.x_pos, self.x_neg = gen_train_data(self.x, self.y, self.lable_num)
            else:
                (self.x_pos, self.y), self.x_neg = next(iter(train_loader))
            self.x_te, self.y_te = next(iter(test_loader))
        else:
            self.train_loader, self.test_loader = Data_loaders(batch_size,
                                                               batch_size,
                                                               supervised=self.supervised)
        
        self.Tpub = self.node.create_publisher(
                                            eval(self.model_layers[0]['trainInp']['type'][0]), 
                                            self.model_layers[0]['trainInp']['name'][0], 
                                            10)
        
        if self.supervised:
            self.Tsub = self.node.create_subscription(
                                                eval(self.model_layers[-1]['trainOut']['type'][0]), 
                                                self.model_layers[-1]['trainOut']['name'][0],
                                                self.traincallback,
                                                10)
        else:
            # get unsupervised train goodness
            self.Tsub = []
            for ml in self.model_layers:
                if ml['goodness']:
                    # self.node.get_logger().info(ml['inferenceOut']['name'][0])
                    self.Tsub.append(
                        self.node.create_subscription(
                                            eval(ml['trainOut']['type'][0]), 
                                            ml['trainOut']['name'][0],
                                            self.traincallback,
                                            10)
                    )
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
        if not self.supervised:
            # generate supervised lastlayer
            self.save_path = f"{MODEL_WEIGHT_ROOT_PATH}/{self.node.mj2dis.model_json['model_name']}/local_model/local_model.pth"
            layers = []
            for m in self.node.mj2dis.local_model:
                from_inp, module, args = m
                inp = ', '.join(map(str,args))
                if module in ['nn.Sigmoid', 'nn.ReLU']:
                    layers.append(eval(f'{module}()'))
                else:
                    layers.append(eval(f'{module}({inp})'))
            
            self.last_layer = nn.Sequential(*layers)
            if self.is_cuda:
                self.last_layer.cuda()
            if os.path.exists(self.save_path):
                if False:
                    self.last_layer.load_state_dict(torch.load(self.save_path))
            else:
                if not os.path.isdir(os.path.dirname(self.save_path)):
                    os.makedirs(os.path.dirname(self.save_path))
            self.opt = torch.optim.Adam(self.last_layer.parameters(), lr=0.0001)

            self.loss_func = torch.nn.CrossEntropyLoss(reduction="mean")
            self.labels = None
            self.preds = None  
            self.loss_val = 0

    def traincallback(self, msg):
        if self.supervised:
            # h_pos, h_neg = TFmsg2tensor(msg)
            self.train_time += 1
            # self.node.get_logger().info(f'Train {self.train_time} times!')
            self.runlabel = False
        else:
            # train unsupervised lastlayer
            h_pos, _ = TFmsg2tensor(msg)
            if self.is_cuda:
                h_pos = h_pos.cuda()
            self.goodness.append(h_pos)
            if len(self.goodness) == len(self.Tsub):
                if self.is_cuda:
                    self.labels = self.labels.cuda()
                goodness = torch.cat( self.goodness,1 )
                self.last_layer.train()
                if self.train_type=='one_shot':
                    tbar = tqdm(range(self.epochs))
                    for i in tbar:
                        preds = self.last_layer(goodness)
                        loss = self.loss_func(preds, self.labels)
                        self.opt.zero_grad()
                        loss.backward()
                        self.loss_val = loss.item()
                        allocated_memory = torch.cuda.memory_allocated()
                        max_allocated_memory = torch.cuda.max_memory_allocated()
                        tbar.set_postfix_str(f'loss={loss.item():.4f}, AM: {allocated_memory / 1024 ** 2} MB, MAM: {max_allocated_memory / 1024 ** 2} MB')
                        self.opt.step()
                else:
                    preds = self.last_layer(goodness)
                    loss = self.loss_func(preds, self.labels)
                    self.opt.zero_grad()
                    loss.backward()
                    self.loss_val = loss.item()
                    self.opt.step()
                # h_pos, h_neg = TFmsg2tensor(msg)
                self.train_time += 1
                self.goodness = []
                # self.node.get_logger().info(f'Train {self.train_time} times!')
                self.runlabel = False
        self.save()
        
    def forwardcallback(self, msg):
        if self.supervised:
            _,good = IFmsg2tensor(msg)
            self.goodness.append(good)
            if len(self.goodness) == len(self.Fsub):
                self.goodness_per_label += [sum(self.goodness).unsqueeze(1)]
                self.goodness = []
                self.runlabel = False
        else:
            representation_ouputs,_ = IFmsg2tensor(msg)
            if self.is_cuda:
                representation_ouputs = representation_ouputs.cuda()
            self.goodness.append(representation_ouputs)
            if len(self.goodness) == len(self.Fsub):
                # for g in self.goodness:
                #     print(g.shape)
                goodness = torch.cat( self.goodness,1 )
                self.last_layer.eval()
                self.preds = self.last_layer(goodness)
                self.goodness = []
                self.runlabel = False

    def train(self, x_pos, x_neg):
        self.runlabel = True
        msg = TrainForward()
        msg = TFtensor2msg(x_pos, x_neg)
        self.Tpub.publish(msg)
        while (rclpy.ok() and self.runlabel):
            rclpy.spin_once(self.node)

    # def train_unsupervised(self, x_pos, x_neg, y):
    #     self.labels = y
    #     self.opt.zero_grad()
    #     preds = self.last_layer(x_pos)
    #     loss = self.loss_func(preds, y)
    #     loss.backward()
    #     self.opt.step()

    def predict_once(self, h):
        self.runlabel = True
        msg = InferanceForward()
        msg = IFtensor2msg(h, torch.zeros([0]))
        self.Fpub.publish(msg)
        while (rclpy.ok() and self.runlabel):
            rclpy.spin_once(self.node)

    def predict(self, x):
        if self.supervised:
            for label in range(self.lable_num):
                # self.node.get_logger().info(f'generate {label}')
                h = overlay_y_on_x(x, label, self.lable_num)
                self.goodness = []
                self.predict_once(h)
            self.goodness_per_label = torch.cat(self.goodness_per_label, 1)
            g = self.goodness_per_label.argmax(1)
            if self.is_cuda:
                return g.cuda()
            else:
                return g
        else:
            if self.is_cuda:
                x=x.cuda()
            self.predict_once(x)
            return self.preds.argmax(1)
    def save(self):
        try:
            torch.save(self.last_layer.state_dict(), self.save_path)
        except Exception as e:
            print(e)
        # save weight to local TBD: to master

    def run(self):
        # train model
        self.node.get_logger().info('Train model starting!')
        if self.train_type=='one_shot':
            if self.supervised:
                self.train(self.x_pos, self.x_neg)
            else:
                self.labels = self.y
                self.train(self.x_pos, self.x_neg)
        elif self.train_type=='batch_shot':
            tbar = tqdm(self.train_loader)
            tbar.set_description(f'Batch_shot')
            if self.supervised:
                for x,y in tbar:
                    x_pos, x_neg = gen_train_data(x, y, self.lable_num)
                    self.train(x_pos, x_neg)
            else:
                for (x_pos, y) , x_neg in tbar:
                    self.labels = y
                    self.train(x_pos, x_neg)
                    print(f'loss={self.loss_val}')
        else:
            for e in range(self.epochs):
                tbar = tqdm(self.train_loader)
                tbar.set_description(f'Epoch {e+1}/{self.epochs}')
                if self.supervised:
                    for x,y in tbar:
                        x_pos, x_neg = gen_train_data(x, y, self.lable_num)
                        self.train(x_pos, x_neg)
                else:
                    for (x_pos, y) , x_neg in tbar:
                        self.labels = y
                        self.train(x_pos, x_neg)
                        print(f'loss={self.loss_val}')

        self.node.get_logger().info('Predict test data starting!')
        allocated_memory = torch.cuda.memory_allocated()
        max_allocated_memory = torch.cuda.max_memory_allocated()
        print(f'AM: {allocated_memory / 1024 ** 2} MB, MAM: {max_allocated_memory / 1024 ** 2} MB')
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
        if self.is_cuda:
            y_tes = y_tes.cuda()
        self.node.get_logger().info(f'test error: {1.0 - results.eq(y_tes).float().mean().item()}')

        self.node.get_logger().info('Save 100 prediction results!')
        for i in range(100):
            if self.data_set == 'MNIST':
                shape = (28,28)
            else:
                shape = (3,32,32)
            save_visualize_sample(i, shape, x_tes[i], y_tes[i], results[i]
                                  , labels=self.node.mj2dis.model_json['labels'])
        self.node.get_logger().info('Training Finished!')
        

