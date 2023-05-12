#!/usr/bin/env python
import rclpy
# from dffw.ff import MasterRunner

from dffw.master import MasterNode

def main(args=None):
    rclpy.init()
    
    # layerrunner = MasterRunner()

    # layerrunner.run()

    # layerrunner.destroy()

    node = MasterNode(layer_infor_json_path='/root/ros2_ws/src/dffw/dffw/layersInfo.json')
    node.distribute_model('/root/ros2_ws/src/dffw/dffw/model.json')
    node.run()
    rclpy.spin(node)

    node.get_logger().info('Shutting down...')
    node.destroy_node()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()



if __name__ == '__main__':
    main()