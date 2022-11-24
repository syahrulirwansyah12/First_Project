#!/usr/bin/env python
import rospy
from first_project.msg import GPS_data

def gps_callback(gps_message):
    rospy.loginfo("new GPS data received: (%.2f, %.2f ,%.2f)", 
        gps_message.longitude,gps_message.latitude,
        gps_message.heading)
    
rospy.init_node('gps_subscriber_node', anonymous=True)

rospy.Subscriber("gps_topic", GPS_data, gps_callback)

# spin() simply keeps python from exiting until this node is stopped
rospy.spin()
