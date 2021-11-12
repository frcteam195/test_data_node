#include "ros/ros.h"
#include "std_msgs/String.h"

#include <thread>
#include <string>
#include <map>
#include <mutex>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_data");
	ros::NodeHandle n;

	ros::spin();
	return 0;
}
