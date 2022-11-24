#include "ros/ros.h"
#include "first_project/GPS_data.h"

int main (int argc, char **argv) {
    // Initiate a new ROS node named "gps_publisher_node"
	ros::init(argc, argv, "gps_publisher_node");
    //create a node handle: it is reference assigned to a new node
	ros::NodeHandle nh;
    //Rate is a class the is used to define frequency for a loop. Here we send a message each two seconds.
	ros::Rate loop_rate(10);
    //create a publisher with a topic "gps_topic" that will send a String message
	ros::Publisher pub = nh.advertise<first_project::GPS_data>("gps_topic", 1000);

    ROS_INFO("Test node has been started");

    int i = 0;
    while(ros::ok()){
        first_project::GPS_data gps;
        gps.longitude = 24.33 + (double)(i);
        gps.latitude = 33.41 + (double)(i);
        gps.heading = 3.51 + (double)(i);

        ROS_INFO("I publish longitude: %.6f", gps.longitude);
        ROS_INFO("I publish latitude: %.6f", gps.latitude);
        ROS_INFO("I publish bearing: %.6f", gps.heading);

        pub.publish(gps);
        loop_rate.sleep();
        i++;
    }
}