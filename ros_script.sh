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

ros2 run dffw master_node.py --model_json /root/ros2_ws/src/dffw/dffw/model.json --batch_size 2000 --train_type one_shot --epochs 1000 --is_cuda

ros2 run dffw master_node.py --model_json /root/ros2_ws/src/dffw/dffw/model2.json --batch_size 2000 --train_type one_shot --epochs 5000 --is_cuda
ros2 run dffw service_node0.py --is_cuda