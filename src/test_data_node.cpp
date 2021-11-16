#include "ros/ros.h"
#include "std_msgs/String.h"

#include <thread>
#include <string>
#include <map>
#include <mutex>

#include <test_data_node/TestData.h>

#define RATE (30)
#include <math.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_data");

    ros::NodeHandle nh;
    ros::Rate rate(RATE);
	ros::Publisher test_data_pub =
        nh.advertise<test_data_node::TestData>("TestData", 1);

    test_data_node::TestData test_data;
    test_data.waves.push_back( test_data_node::SinWaves() );
    test_data.waves.push_back( test_data_node::SinWaves() );

    while( ros::ok() )
    {
        uint64_t time = ros::Time::now().toNSec();

        test_data.waves[0].slow = sin(time * 0.01);
        test_data.waves[0].fast = sin(time * 0.05);
        test_data.waves[0].offset = sin(time * 0.05) + 3;
        test_data.waves[0].AMPLITUDED = sin(time * 0.05) * 5;

        test_data.waves[1].slow = cos(time * 0.03);
        test_data.waves[1].fast = cos(time * 0.06);
        test_data.waves[1].offset = cos(time * 0.07) + 3;
        test_data.waves[1].AMPLITUDED = cos(time * 0.1) * 5;

        test_data_pub.publish(test_data);
        ros::spinOnce();
        rate.sleep();
    }

	return 0;
}
