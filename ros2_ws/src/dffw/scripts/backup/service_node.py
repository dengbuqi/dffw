#!/usr/bin/env python
import torch
import rclpy
from rclpy.node import Node
from dffw.msg import PytorchTensorFloat32  
from dffw.dataconvert import float32msg2tensor, float32tensor2msg

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(PytorchTensorFloat32, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        data = torch.rand([5000, 28*28])
        msg = float32tensor2msg(data)
        self.publisher_.publish(msg)
        self.get_logger().info(f'{self.i}:Publishing: datashape:{msg.shape}')
        self.get_logger().info(f'{self.i}:Publishing: data:{msg.data[:3]}')
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()