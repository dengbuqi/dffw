#!/usr/bin/env python
import rclpy
from dffw.ff import MasterRunner


def main(args=None):
    rclpy.init()
    
    layerrunner = MasterRunner()

    layerrunner.run()

    layerrunner.destroy()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()



if __name__ == '__main__':
    main()