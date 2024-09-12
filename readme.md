
Install Docker based on the instructions on https://docs.docker.com/get-started/get-docker/

Getting the ros noetic image
```bash
docker pull ros:noetic-robot
```

Build the Docker image
```bash
docker build -t erc_robotic_arm_image .
```

Run the Docker container
```bash
docker run -it erc_robotic_arm_image /bin/bash
cd src/erc_robotic_arm/launch/
chmod +x control.launch
roslaunch control.launch --device=/dev/input/js0 --device=/dev/ttyACM0
```
Change the value of the two device attribute based on the port names of your device to which the joystick and Arduino is connected to.

