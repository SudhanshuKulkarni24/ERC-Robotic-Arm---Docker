#!/usr/bin/env python3

import rospy
#from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Point32
#xAxis1 = 0
#yAxis1 = 0


def callback(data):
    xAxis1 = data.axes[0] # axes[0]  //controls Linear Actuators
    yAxis1 = data.axes[1] # axes[1]
    motor3=data.axes[3]
    gripper=data.axes[4]
    msg = Point32()  # Create a message instance
    grip=Point32()
    msg.x = int(xAxis1*255)
    msg.y = int(yAxis1*255) 
    msg.z = int(motor3*255) 
    grip.x=int(gripper*180)
    pub.publish(msg)
    pub2.publish(grip)


    

if __name__ == '__main__':
    rospy.init_node("joy_control", anonymous=True)
    pub = rospy.Publisher("/control1", Point32, queue_size=1)
    pub2 = rospy.Publisher("/gripper", Point32, queue_size=1)
    rospy.Subscriber("/joy0", Joy, callback)
    rospy.spin()
       