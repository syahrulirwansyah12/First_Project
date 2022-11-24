#!/usr/bin/env python

import rospy
from first_project.msg import GPS_data
import random

#create a new publisher. we specify the topic name, then type of message then the queue size
pub = rospy.Publisher('gps_topic', GPS_data, queue_size=10)

#we need to initialize the node
rospy.init_node('gps_publisher_node', anonymous=True)

#set the loop rate
rate = rospy.Rate(1) # 1hz
#keep publishing until a Ctrl-C is pressed
i = 0
while not rospy.is_shutdown():
    GPS = GPS_data()
    GPS.longitude = 24.33 + (random.random()*2)
    GPS.latitude = 33.41 + (random.random()*2)
    GPS.heading = (random.random()*2)
    rospy.loginfo("I publish:")
    rospy.loginfo(GPS)
    pub.publish(GPS)
    rate.sleep()
    i=i+1