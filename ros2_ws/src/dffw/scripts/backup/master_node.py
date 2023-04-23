#!/usr/bin/env python
import torch
import rclpy
from rclpy.node import Node
from dffw.msg import PytorchTensorFloat32  
from dffw.dataconvert import float32msg2tensor, float32tensor2msg

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            PytorchTensorFloat32,
            'topic',
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        tensor = float32msg2tensor(msg)
        # self.get_logger().info(f'I heard: tensorshape {tensor.shape} {tensor.type()}')
        # self.get_logger().info(f'I heard: data:{tensor[0,0]}')

def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()