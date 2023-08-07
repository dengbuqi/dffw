import torch
import torch.nn as nn
from tqdm import tqdm
from torch.optim import Adam
from torch.nn.functional import normalize
from torch.nn.common_types import _size_1_t, _size_2_t, _size_3_t
from typing import Optional, List, Tuple, Union

class Linear_dffw(nn.Linear):
    def __init__(self, in_features, out_features, act=torch.nn.ReLU(),
                 bias=True, device=None, dtype=None):
        super().__init__(in_features, out_features, bias, device, dtype)
        self.act = act
        self.opt = Adam(self.parameters(), lr=0.03)
        self.threshold = 2.0
        # self.epochs = 1000

    def forward_ff(self, x):
        x_direction = x / (x.norm(2, 1, keepdim=True) + 1e-4)
        return self.act(
            torch.mm(x_direction, self.weight.T) +
            self.bias.unsqueeze(0))

    def train_ff(self, x_pos, x_neg, epochs, train_type='one_shot'):
        if train_type == 'one_shot' or train_type == 'batch_shot':
            tbar = tqdm(range(epochs))
        else:
            tbar = range(epochs)

        for i in tbar:
            g_pos = self.forward_ff(x_pos).pow(2).mean(1)
            g_neg = self.forward_ff(x_neg).pow(2).mean(1)
            # The following loss pushes pos (neg) samples to
            # values larger (smaller) than the self.threshold.
            loss = torch.log(1 + torch.exp(torch.cat([
                -g_pos + self.threshold,
                g_neg - self.threshold]))).mean()
            self.opt.zero_grad()
            # this backward just compute the derivative and hence
            # is not considered backpropagation.
            loss.backward()

            if train_type == 'one_shot' or train_type == 'batch_shot':
                allocated_memory = torch.cuda.memory_allocated()
                max_allocated_memory = torch.cuda.max_memory_allocated()
                tbar.set_postfix_str(f'loss={loss.item():.4f} AM: {allocated_memory / 1024 ** 2} MB, MAM: {max_allocated_memory / 1024 ** 2} MB')
            else:
                print(f'loss={loss.item():.4f}')
            self.opt.step()
            p, n = self.forward_ff(x_pos).detach(), self.forward_ff(x_neg).detach()
        return p, n
    
class Conv2d_dffw(nn.Conv2d):
    def __init__(
        self,
        in_channels: int,
        out_channels: int,
        kernel_size: _size_2_t,
        stride: _size_2_t = 1,
        padding: Union[str, _size_2_t] = 0,
        dilation: _size_2_t = 1,
        groups: int = 1,
        bias: bool = True,
        padding_mode: str = 'zeros',  # TODO: refine this type
        device=None,
        dtype=None
    ) -> None:
        super().__init__(in_channels, out_channels, kernel_size, stride, padding, dilation, groups, bias, padding_mode, device, dtype)
        self.act = torch.nn.ReLU()
        self.opt = Adam(self.parameters(), lr=0.001)
        self.threshold = 2.0
        self.pool = nn.MaxPool2d(2, 2)
        # self.epochs = 1000

    def forward_ff(self, x):
        return self.pool(self.act(self.forward(x)))
        
    def train_ff(self, x_pos, x_neg, epochs, train_type='one_shot'):
        if train_type == 'one_shot' or train_type == 'batch_shot':
            tbar = tqdm(range(epochs))
        else:
            tbar = range(epochs)
        for i in tbar:
            g_pos = self.forward_ff(x_pos).pow(2).mean([1,2,3])
            g_neg = self.forward_ff(x_neg).pow(2).mean([1,2,3])
            # The following loss pushes pos (neg) samples to
            # values larger (smaller) than the self.threshold.
            loss = torch.log(1 + torch.exp(torch.cat([
                -g_pos + self.threshold,
                g_neg - self.threshold]))).mean()
            self.opt.zero_grad()
            # this backward just compute the derivative and hence
            # is not considered backpropagation.
            loss.backward()
            if train_type == 'one_shot' or train_type == 'batch_shot':
                tbar.set_postfix_str(f'loss={loss.item():.4f}')
            else:
                print(f'loss={loss.item():.4f}')
            self.opt.step()
        return self.forward_ff(x_pos).detach(), self.forward_ff(x_neg).detach()
        
class Flatton_dffw(nn.Module):
    def __init__(self, in_channel, out_channel, start_dim=0, end_dim=- 1):
        super().__init__()
        self.in_channel, self.out_channel = in_channel, out_channel
        self.start_dim = start_dim
        self.end_dim = end_dim

    def forward_ff(self, x):
        return torch.flatten(x, 
                             start_dim = self.start_dim, 
                             end_dim = self.end_dim)

    def train_ff(self, x_pos, x_neg, epochs, train_type='one_shot'):
        return self.forward_ff(x_pos), self.forward_ff(x_neg)
        
    def forward(self, x):
        return torch.flatten(x, 
                             start_dim = self.start_dim, 
                             end_dim = self.end_dim)



# local
class Nor(nn.Module):
    def __init__(self, in_channel, out_channel):
        super().__init__()
    
    def forward_ff(self, x):
        return normalize(x)

    def train_ff(self, x_pos, x_neg, epochs, train_type='one_shot'):
        return normalize(x_pos), normalize(x_neg)
        
    def forward(self, x):
        return normalize(x)

class SF(nn.Module):
    def __init__(self, in_channel, out_channel):
        super().__init__()
        self.softmax = nn.Softmax(dim=1)

    def forward_ff(self, x):
        return self.softmax(x)

    def train_ff(self, x_pos, x_neg, epochs, train_type='one_shot'):
        return self.softmax(x_pos), self.softmax(x_neg)
        
    def forward(self, x):
        return self.softmax(x)