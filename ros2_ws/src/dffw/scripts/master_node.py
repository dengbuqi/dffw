#!/usr/bin/env python
import rclpy
# from dffw.ff import MasterRunner
import argparse
from dffw.master import MasterNode

def main(parser):

    rclpy.init()

    node = MasterNode(layer_infor_json_path=parser.layer_json)
    node.distribute_model(parser.model_json, 
                          parser.epochs, 
                          parser.train_type,
                          parser.batch_size)
    node.run()
    rclpy.spin(node)

    node.get_logger().info('Shutting down...')
    node.destroy_node()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Distributed Forward-Forward Algorithm master')
    parser.add_argument("-l", "--layer_json", type=str,
                        default='/root/ros2_ws/src/dffw/dffw/layersInfo.json')
    parser.add_argument("-m", "--model_json", type=str,
                        default='/root/ros2_ws/src/dffw/dffw/model.json')
    parser.add_argument("-e", "--epochs", type=int, 
                        default=1000)
    parser.add_argument("-t", "--train_type", type=str, 
                        default='one_shot', 
                        help='train_type = one_shot | epochs_shot')
    parser.add_argument("-b", "--batch_size", type=int, 
                        default=-1)

    main(parser.parse_args())