#include "ros/ros.h"

int main (int argc, char **argv) {
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "test_node");
    //create a node handle: it is reference assigned to a new node
	ros::NodeHandle nh;


    ROS_INFO("Hello from test node");
    ROS_WARN("This is a warning");
    ROS_ERROR("This is an error");

    ros::Duration(1.0).sleep(); // Sleep for the rest of the cycle, to enforce the loop rate

    ROS_INFO("This is the end of the program");
}