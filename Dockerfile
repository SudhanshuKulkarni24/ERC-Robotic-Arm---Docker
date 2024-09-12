# Use an official ROS Noetic image
FROM ros:noetic-ros-core

# Install necessary dependencies and tools, including joy and rosserial_python
RUN apt-get update && apt-get install -y \
    build-essential \
    ros-noetic-catkin \
    ros-noetic-joy \
    ros-noetic-rosserial-python \
    python3-rosdep \
    python3-rosinstall \
    python3-rosinstall-generator \
    python3-wstool \
    python3-roslaunch \
    && rm -rf /var/lib/apt/lists/*

# Initialize rosdep
RUN rosdep init && rosdep update

# Set the workspace environment
ENV CATKIN_WS=/root/catkin_ws
WORKDIR $CATKIN_WS/src

# Copy the erc_robotic_arm package into the catkin workspace
COPY . /root/catkin_ws/src/erc_robotic_arm

# Go to the workspace root and build the workspace
WORKDIR $CATKIN_WS
RUN /bin/bash -c "source /opt/ros/noetic/setup.bash && catkin_make"

# Source the workspace setup.bash in every new shell
RUN echo "source $CATKIN_WS/devel/setup.bash" >> ~/.bashrc


