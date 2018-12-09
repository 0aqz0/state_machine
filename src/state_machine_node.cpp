#include <ros/ros.h>
#include <ros/console.h>
#include "std_msgs/String.h"
#include "state_machine/stateMachine.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "state_machine");
    decision::StateMachine stm;
    stm.start(); 
    
    ros::NodeHandle n;
    ros::Publisher state_pub = n.advertise<std_msgs::String>("state_machine/state", 1000);
    ros::Publisher event_pub = n.advertise<std_msgs::String>("state_machine/event", 1000);
    ros::Rate loop_rate(10);
    while(ros::ok()){
    	// ROS_INFO("HELLO");
    	std_msgs::String msg;
    	msg.data = stm.get_state();
    	state_pub.publish(msg);
        msg.data = stm.get_event();
        event_pub.publish(msg);
        
    	ros::spinOnce();
    	loop_rate.sleep();
    }
    ros::spin();
}