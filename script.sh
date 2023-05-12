
docker pull pytorch/pytorch:latest # docker pull pytorch/pytorch:1.13.1-cuda11.6-cudnn8-runtime
docker run --gpus all -it --rm -v /home/deng/data/dffw/pytorch_forward_forward:/workspace pytorch/pytorch:latest
# https://docs.ros.org/en/eloquent/Installation/Linux-Install-Debians.html
apt update
apt upgrade
apt install locales -y
locale-gen en_US en_US.UTF-8
update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
apt install software-properties-common -y
add-apt-repository universe
apt update && apt install curl -y
curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null
apt update
apt upgrade
# ARG DEBIAN_FRONTEND=noninteractive 
# ENV TZ=Asia/Seoul
apt install ros-eloquent-desktop -y
source /opt/ros/eloquent/setup.bash
echo "source /opt/ros/eloquent/setup.bash" >> ~/.bashrc
# echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
echo "export _colcon_cd_root=~/ros2_install" >> ~/.bashrc
echo "source /workspace/ros2_ws/install/setup.bash" >> ~/.bashrc
# echo "export PYTHONPATH=/custom/path/to/modules"
pip install -U argcomplete matplotlib tqdm colcon-common-extensions lark
# apt remove ros-eloquent-* && sudo apt autoremove