# create workspace
mkdir -p ros2_ws/src
cd ros2_ws/src

# https://roboticsbackend.com/ros2-package-for-both-python-and-cpp-nodes/
colcon build
colcon build --packages-select dffw
colcon build --packages-select dffw_msgs

  . ros2_ws/install/setup.bash
ros2 run dffw service_node0.py
ros2 run dffw service_node1.py
ros2 run dffw master_node.py
