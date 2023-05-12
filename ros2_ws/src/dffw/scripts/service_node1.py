#!/usr/bin/env python
import rclpy
from dffw.ff import LayerRunner
from dffw.common import *


def main():
    rclpy.init()
    nodeid = 0
    node = rclpy.create_node(f'server_{nodeid}')
    layer = Linear_dffw(500, 500) # [784, 500, 500]
    layerrunner = LayerRunner(node, layer, nodeid)

    layerrunner.run()

    layerrunner.destroy()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()


if __name__ == '__main__':
    main()