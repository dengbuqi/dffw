import torch
from dffw_msgs.msg import PytorchTensorFloat32, TrainForward, InferanceForward 
import numpy as np

def float32msg2tensor(msg):
    ls = list(msg.data)
    return torch.tensor(msg.data).view(tuple(msg.shape))

def float32tensor2msg(tensor):
    msg = PytorchTensorFloat32()
    msg.shape = tensor.shape
    msg.data = tensor.view(-1).tolist()
    return msg

def TFmsg2tensor(msg):
    return torch.tensor(msg.h_pos_data).view(tuple(msg.h_pos_shape)), torch.tensor(msg.h_neg_data).view(tuple(msg.h_neg_shape))

def TFtensor2msg(h_pos, h_neg):
    msg = TrainForward()
    msg.h_pos_shape = h_pos.shape
    msg.h_pos_data = h_pos.view(-1).tolist()
    msg.h_neg_shape = h_neg.shape
    msg.h_neg_data = h_neg.view(-1).tolist()
    return msg

def IFmsg2tensor(msg):
    return torch.tensor(msg.h_data).view(tuple(msg.h_shape)), torch.tensor(msg.goodness_data).view(tuple(msg.goodness_shape))

def IFtensor2msg(h, goodness):
    msg = InferanceForward()
    msg.h_shape = h.shape
    msg.h_data = h.view(-1).tolist()
    msg.goodness_shape = goodness.shape
    msg.goodness_data = goodness.view(-1).tolist()
    return msg
