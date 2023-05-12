#!/usr/bin/env python
import rclpy
from dffw.server import LayerRunner, ServerNode

SERVER_NAME = 'server_'

def main():
    rclpy.init()
    nodeid = -1
    nodeName = 'temp'
    node = rclpy.create_node(nodeName)
    node_list = node.get_node_names()
    for n in node_list:
        if SERVER_NAME in n:
            nid = int(n.replace(SERVER_NAME,''))
            if nid > nodeid:
                nodeid = nid
    nodeid+=1
    node.destroy_node()


    nodeName = SERVER_NAME+str(nodeid)
    # node = rclpy.create_node(nodeName)
    node = ServerNode(nodeName)
    
    rclpy.spin(node)

    node.get_logger().info('Shutting down...')
    node.destroy_node()

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()


if __name__ == '__main__':
    main()