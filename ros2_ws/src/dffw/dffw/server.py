from dffw_msgs.msg import *
from dffw_msgs.srv import *
from dffw.dataconvert import *
from dffw.common import *
import json
from rclpy.node import Node
import os

SERVER_NAME = 'server_'
MODEL_WEIGHT_ROOT_PATH = '/root/weight'
def create_layer(layer_info):
    args = layer_info['args']
    module = layer_info['module']
    inp = ', '.join(map(str,args))
    return  eval(f'{module}({inp})')

class LayerRunner(object):
    def __init__(self, node,
                       layer_info, 
                       num_epochs=1000,
                       is_cuda=True):
        self.node = node
        self.layer_info = json.loads(layer_info)
        self.save_path = f"{MODEL_WEIGHT_ROOT_PATH}/{self.layer_info['model_name']}/{self.layer_info['layer_id']}/{self.layer_info['module']}.pth"
        self.layer = create_layer(self.layer_info)
        if is_cuda:
            self.layer = self.layer.cuda()
        if os.path.exists(self.save_path):
            self.layer.load_state_dict(torch.load(self.save_path))
        else:
            if not os.path.isdir(os.path.dirname(self.save_path)):
                os.makedirs(os.path.dirname(self.save_path))
        self.num_epochs = num_epochs
        self.is_cuda = is_cuda

        self.Tsub = self.node.create_subscription(
                                            eval(self.layer_info['trainInp']['type'][0]),
                                            self.layer_info['trainInp']['name'][0],
                                            self.traincallback,
                                            10)
        
        self.Tpub = self.node.create_publisher(
                                            eval(self.layer_info['trainOut']['type'][0]), 
                                            self.layer_info['trainOut']['name'][0], 
                                            10)
        self.Fsub = self.node.create_subscription(
                                            eval(self.layer_info['inferenceInp']['type'][0]),
                                            self.layer_info['inferenceInp']['name'][0],
                                            self.forwardcallback,
                                            10)
        
        self.Fpub = self.node.create_publisher(
                                            eval(self.layer_info['inferenceOut']['type'][0]), 
                                            self.layer_info['inferenceOut']['name'][0],
                                            10)
   
    def model_name(self):
        return self.layer_info['model_name']
    
    def traincallback(self, msg):
        h_pos, h_neg = TFmsg2tensor(msg) #TBD: change to a universal method
        if self.is_cuda:
            h_pos = h_pos.cuda()
            h_neg = h_neg.cuda()
        h_pos, h_neg = self.layer.train(h_pos, h_neg, self.num_epochs)
        torch.save(self.layer.state_dict(), self.save_path)
        msg = TrainForward()
        msg = TFtensor2msg(h_pos, h_neg) #TBD: change to a universal method
        self.Tpub.publish(msg)
    
    def forwardcallback(self, msg):
        h,_ = IFmsg2tensor(msg) #TBD: change to a universal method
        if self.is_cuda:
            h = h.cuda()
        h = self.layer.forward(h)
        goodness = h.pow(2).mean(1)
        if self.is_cuda:
            h = h.cpu()
            goodness = goodness.cpu()
        msg = InferanceForward()
        msg =  IFtensor2msg(h, goodness) #TBD: change to a universal method
        self.Fpub.publish(msg)

    # def run(self):
    #     rclpy.spin(self.node)
    def save(self):
        pass
        # save weight to master

    def destroy(self):
        self.node.destroy_subscription(self.Tsub)
        self.node.destroy_subscription(self.Fsub)
        self.node.destroy_publisher(self.Tpub)
        self.node.destroy_publisher(self.Fpub)
        del self.layer

class ServerNode(Node):
    def __init__(self, server_name=SERVER_NAME):
        super().__init__(server_name)
        self.layer_runners = []

        self.create_sevice = self.create_service(
            Str,  
            f'{self.get_name()}/create_layer',  
            self.create_service_callback
        )
        self.delete_sevice = self.create_service(
            Str,  
            f'{self.get_name()}/delete_layer',  
            self.delete_service_callback
        )
        self.get_logger().info('Server Successfully Created!')

    def create_service_callback(self, request, response):
        self.get_logger().info('create_service_callback called!')
        response.msg = f'failed|'
        if request.msg:
            try:
                layer_info = request.msg
                layer_runner = LayerRunner(self, 
                                        layer_info)
                self.layer_runners.append({'model_name':layer_runner.model_name(),
                                        'layer_runner': layer_runner})
                response.msg = f'success|{layer_info}'
                self.get_logger().info(f'{layer_runner.layer_info["model_name"]}/{layer_runner.layer_info["module"]}/{layer_runner.layer_info["args"]} created!')
                return response
            except Exception as e:
                response.msg = f'fail|{layer_info}|{e}'
                return response
        

    def delete_service_callback(self, request, response):
        self.get_logger().info('delete_service_callback called!')
        response.msg = f'failed|'
        if request.msg:
            try:
                delete_model_name = request.msg
                for l in self.layer_runners:
                    if delete_model_name == l['model_name']:
                        runner = l['layer_runner']
                        runner.destroy()
                response.msg = f'success|{delete_model_name}'
                return response
            except Exception as e:
                response.msg = f'failed|{delete_model_name}|e'
                return response
        