#include "ros/ros.h"
#include "std_msgs/String.h"

#include <thread>
#include <string>
#include <map>
#include <mutex>

#include <test_data_node/TestData.h>

#define RATE (100)
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

    float i = 0;
    while( ros::ok() )
    {
        i += 0.01;

        uint64_t time = ros::Time::now().toNSec();

        test_data.waves[0].slow = sin(i);
        test_data.waves[0].fast = sin(i*2);
        test_data.waves[0].offset = sin(i*4) + 3;
        test_data.waves[0].AMPLITUDED = sin(i*4) * 5;

        test_data.waves[1].slow = cos(i);
        test_data.waves[1].fast = cos(i*2);
        test_data.waves[1].offset = cos(i*4) + 3;
        test_data.waves[1].AMPLITUDED = cos(i*4) * 5;

        test_data_pub.publish(test_data);
        ros::spinOnce();
        rate.sleep();
    }

	return 0;
}
