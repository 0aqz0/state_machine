#include <ros/ros.h>
#include "state_machine/stateMachine.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "state_machine");
    decision::StateMachine stm; 

    ros::spin();
}