#include "ros/ros.h"

int main (int argc, char **argv) {
    // Initiate a new ROS node named "test_node_2"
	ros::init(argc, argv, "test_node_2");
    //create a node handle: it is reference assigned to a new node
	ros::NodeHandle nh;
    //Rate is a class the is used to define frequency for a loop.
	ros::Rate loop_rate(10);

    ROS_INFO("Test node has been started");

    while(ros::ok()){
        ROS_INFO("Hello from the other side");
        loop_rate.sleep();
    }
}