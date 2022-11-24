#include "ros/ros.h"
#include "first_project/GPS_data.h"

// Topic messages callback
void GPSCallback(const first_project::GPS_data &gps)
{
    ROS_INFO("I received longitude: %.6f", gps.longitude);
    ROS_INFO("I received latitude: %.6f", gps.latitude);
    ROS_INFO("I received bearing: %.6f", gps.heading);
}

int main (int argc, char **argv) {
    // Initiate a new ROS node named "gps_publisher_node"
	ros::init(argc, argv, "gps_subscriber_node");
    //create a node handle: it is reference assigned to a new node
	ros::NodeHandle nh;

	//GPSCallback: is the name of the callback function that will be executed each time a message is received.
    ros::Subscriber sub = nh.subscribe("gps_topic", 1000, GPSCallback);

    // Enter a loop, pumping callbacks
    ros::spin();
}