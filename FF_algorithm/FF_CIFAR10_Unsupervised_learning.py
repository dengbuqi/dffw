# https://github.com/mohammadpz/pytorch_forward_forward
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
from tqdm import tqdm
from torch.optim import Adam
from torchvision.datasets import CIFAR10
from torchvision.transforms import Compose, ToTensor, Normalize, Lambda
from torch.utils.data import DataLoader
from common import *
from utils import *

def create_supervised_train_data(train_dataset, dataset_name):
    n_train_samples = len(train_dataset)
    if not os.path.exists(f'./data/{dataset_name}.pt'):
        random_pairs = np.random.randint(n_train_samples, size=[n_train_samples, 2])
        random_pairs = [(row[0], row[1]) for row in random_pairs]
        # Transform the data
        print(f'Transform the <{dataset_name}> data')
        transformed_dataset = [
            create_negative_image(train_dataset[pair[0]][0].squeeze(), train_dataset[pair[1]][0].squeeze())
            for pair in tqdm(random_pairs)]

        # Save the transformed images to a folder
        torch.save(transformed_dataset, f'./data/{dataset_name}.pt')

class ConcatDataset(torch.utils.data.Dataset):
    def __init__(self, *datasets):
        self.datasets = datasets

    def __getitem__(self, i):
        return tuple(d[i] for d in self.datasets)

    def __len__(self):
        return min(len(d) for d in self.datasets)
    
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
                CIFAR10('./data/', 
                train=False,
                download=True,
                transform=transform),
                batch_size=test_batch_size, 
                shuffle=False)
    
    if supervised:
        train_loader = DataLoader(
                CIFAR10('./data/', train=True,
                download=True,
                transform=transform),
                batch_size=train_batch_size, 
                shuffle=True)
    else:
        pos_dataset = CIFAR10('./data/', 
                            train=True,
                            download=True,
                            transform=transform)
        to_d = CIFAR10('./data/', 
                            train=True, 
                            download=True, 
                            transform=to_t)
        create_supervised_train_data(to_d, 
                                    'CIFAR10')
        neg_dataset = torch.load('./data/CIFAR10.pt')
        neg_dataset = [trans_f(neg) for neg in neg_dataset]
        train_loader = DataLoader(
                        ConcatDataset(pos_dataset, neg_dataset),
                        batch_size=train_batch_size, 
                        shuffle=True)
    return train_loader, test_loader


class Net(torch.nn.Module):

    def __init__(self, un_dims, su_dims):
        super().__init__()
        self.unsupervised_layers = []
        for d in range(len(un_dims) - 1):
            self.unsupervised_layers += [Linear_dffw(un_dims[d], un_dims[d + 1]).cuda()]
        su_layers_list = [Nor(4000,4000)]
        for d in range(len(su_dims) - 1):
            su_layers_list += [nn.Linear(su_dims[d], su_dims[d + 1])]
        su_layers_list += [nn.Softmax(dim=1)]
        self.supervised_layers = nn.Sequential(*su_layers_list).cuda()
        self.opt = torch.optim.Adam(self.supervised_layers.parameters(), lr=0.0001)
        self.loss_func = torch.nn.CrossEntropyLoss(reduction="mean")

    def predict(self, x):
        h = x
        all_h = []
        for layer in self.unsupervised_layers:
            h = layer.forward_ff(h)
            all_h.append(h)
        self.supervised_layers.eval()
        return self.supervised_layers(torch.cat(all_h,1))

    def train(self, x_pos, y_pos, x_neg, epochs=5000):
        all_h_pos = []
        h_pos, h_neg = x_pos, x_neg
        for i, layer in enumerate(self.unsupervised_layers):
            h_pos, h_neg = layer.train_ff(h_pos, h_neg, epochs)
            all_h_pos.append(h_pos)
        tbar = tqdm(range(epochs))
        self.supervised_layers.train()
        for e in tbar:
            tbar.set_description(f'{e+1}/{epochs}')
            preds = self.supervised_layers(torch.cat(all_h_pos,1))
            loss = self.loss_func(preds, y_pos)
            self.opt.zero_grad()
            loss.backward()
            tbar.set_postfix_str(f'loss={loss.item():0.4f}')
            self.opt.step()  

# def visualize_sample(data, name='', idx=0):
#     reshaped = data[idx].cpu().reshape(28, 28)
#     plt.figure(figsize = (4, 4))
#     plt.title(name)
#     plt.imshow(reshaped, cmap="gray")
#     plt.show()
    
    
if __name__ == "__main__":
    torch.manual_seed(1234)
    train_loader, test_loader = CIFAR10_loaders(supervised=False)

    net = Net([3072, 2000, 2000], [4000, 1000, 10])

    (x_pos, y_pos), x_neg = next(iter(train_loader))
    net.train(x_pos.cuda(), y_pos.cuda(), x_neg.cuda(), 5000)

    x_te, y_te = next(iter(test_loader))
    x_te, y_te = x_te.cuda(), y_te.cuda()
    preds = net.predict(x_te).argmax(1)
    print('test error:', 1.0 - preds.eq(y_te).float().mean().item())
