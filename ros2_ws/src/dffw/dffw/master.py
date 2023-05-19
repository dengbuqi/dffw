import json
from dffw_msgs.msg import *
from dffw_msgs.srv import *
from dffw.dataconvert import *
from dffw.common import *
from dffw.ff import MasterRunner

import json
from rclpy.node import Node
import rclpy

SERVER_NAME = 'server_'

def read_json(file_path):
    with open(file_path, 'r') as file:
        try:
            data = json.load(file)
            return data
        except Exception as e:
            self.get_logger().info(f"Error reading Json file: {e}")

class ModelJson2Distribution(object):
    def __init__(self, layersInfo_json_path='layersInfo.json'):
        self.layersInfo = read_json(layersInfo_json_path)
        self.nodes = []
        self.model_json = None

    def read_model(self, model_json_path='model.json'):
        model_json = read_json(model_json_path)
        model_rebuilt = []
        model_distribute = []
        idx = 0
        in_ch = model_json["in_channel"]
        model_name = model_json["model_name"]
        goodness_layers = model_json["goodness_layers"]
        
        for m in model_json["model"]:
            from_inp, module, args = m
            if not isinstance(from_inp, list):
                if from_inp == -1:
                    from_inp = idx-1
                    if from_inp == -1:
                        args_new = [in_ch]+args
                    else:
                        args_new = [model_rebuilt[from_inp][2][1]]+args
                    model_rebuilt.append([from_inp, module, args_new])
                    idx +=1
                else:
                    args_new = [model_rebuilt[from_inp][2][1]]+args
                    model_rebuilt.append([from_inp, module, args_new])
                    idx +=1
            else:
                c = []
                for f_i in from_inp:
                    c.append(model_rebuilt[f_i][2][1])
                args_new = args+[c]
                model_rebuilt.append([from_inp, module, args_new])

        for idx, m in enumerate(model_rebuilt): 
            from_inp, module, args = m
            if from_inp == -1: # To avoid sub/pub name problem, no '-'
                from_inp = 'in'
            in_out = {}
            for k, v in self.layersInfo[module].items():
                name = []
                tp = []
                for v_k, v_v in v.items(): # TBD: mismatch between each layer problem: inp/out problem
                    # 'l_' is avoid sub/pub name problem, no '-'
                    if 'Inp' in k:
                        if from_inp == 'in':
                            name.append(f'{model_name}/l_{from_inp}/{k}/{v_k}')
                        else:
                            k_t = k.replace('Inp', 'Out')
                            v_k_t = 'y'
                            name.append(f'{model_name}/l_{from_inp}/{k_t}/{v_k_t}')
                    if 'Out' in k:
                        name.append(f'{model_name}/l_{idx}/{k}/{v_k}')
                    tp.append(v_v)
                in_out[k] = {}
                in_out[k]['name'] = name
                in_out[k]['type'] = tp
            m_d = {
                'model_name': model_json['model_name'],
                'layer_id': idx,
                'goodness': True if idx in goodness_layers else False,
                'from_inp': from_inp, 
                'module': module, 
                'args':args
            }
            model_distribute.append({**m_d, **in_out})
        # for m in model_distribute:
        #     self.get_logger().info(m)
        self.model_json = model_json
        return model_distribute
        

def get_server(all_server_list, server_key_word=SERVER_NAME):
    return [sn for sn in all_server_list  if server_key_word in sn]

class MasterNode(Node):
    def __init__(self, master_name='Master', layer_infor_json_path='layersInfo.json'):
        super().__init__(master_name)
        self.server_list = get_server(self.get_node_names())
        self.mj2dis = ModelJson2Distribution(layer_infor_json_path)
        self.model_layers = []
        self.model_distribution = []
        self.dataset = ''
        self.runner = None
        self.get_logger().info('Master Successfully Created!')

    def _send_layer(self, server_name, layer_info):
        req = Str.Request()
        req.msg = layer_info
        self.get_logger().info(f'/{server_name}/create_layer')
        cli = self.create_client(Str, f'/{server_name}/create_layer')
        while not cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        future = cli.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            response = future.result()
            msg = response.msg
            self.get_logger().info('Msg: '+msg.split('|')[0])
        else:
            self.get_logger().info('Service call failed')

    def distribute_model(self, 
                         model_json_path, 
                         epochs=1000, 
                         train_type='one_shot',  
                         batch_size=-1):
        '''
            train_type = 'one_shot' | 'epochs_shot'
        '''
        self.model_layers = self.mj2dis.read_model(model_json_path)
        self.dataset = self.mj2dis.model_json['dataset']
        self.server_list = get_server(self.get_node_names()) # update node number 
        mod = len(self.server_list)
        if train_type == 'one_shot':
            ep = {'train_type':train_type,
                  'epochs': epochs}
        else:
            ep = {'train_type':train_type,
                  'epochs': 1}

        for idx, layer_info in enumerate(self.model_layers):  #TBD: better distribution strategy
            layer_info = {**ep, **layer_info}
            self._send_layer(self.server_list[idx%mod], json.dumps(layer_info))
        
        self.runner = MasterRunner(self, 
                                   self.model_layers, 
                                   self.dataset, 
                                   epochs=epochs, 
                                   train_type=train_type,  
                                   batch_size=batch_size)

    def run(self):
        self.runner.run()