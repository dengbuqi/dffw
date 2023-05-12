# dffw image

FROM nvidia/cuda:12.1.0-runtime-ubuntu22.04
WORKDIR /root
ARG DEBIAN_FRONTEND=noninteractive 
ENV TZ=Asia/Seoul

RUN apt-get update && apt-get install --no-install-recommends -y zip htop screen libgl1-mesa-glx software-properties-common python3.10-dev python3.10-distutils locales curl

RUN locale-gen en_US en_US.UTF-8
RUN update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
RUN export LANG=en_US.UTF-8
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

RUN update-alternatives --install /usr/bin/python python /usr/bin/python3.10 1
ADD https://bootstrap.pypa.io/get-pip.py get-pip.py
RUN python get-pip.py
RUN pip install --no-cache -U argcomplete matplotlib tqdm colcon-common-extensions lark torch torchvision torchaudio --extra-index-url \
https://download.pytorch.org/whl/cu117
RUN apt-get update && apt-get install ros-humble-desktop ros-dev-tools -y 
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
RUN echo "export _colcon_cd_root=~/ros2_install" >> ~/.bashrc
