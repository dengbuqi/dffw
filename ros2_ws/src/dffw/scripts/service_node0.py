#!/usr/bin/env python
import rclpy
from dffw.ff import LayerRunner
from dffw.common import Layer


def main():
    rclpy.init()
    layer = Layer(784, 500) # [784, 500, 500]
    layerrunner = LayerRunner(layer, 0)

    layerrunner.run()

    layerrunner.destroy()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()


if __name__ == '__main__':
    main()