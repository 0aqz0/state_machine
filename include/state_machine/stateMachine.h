#include <ros/ros.h>
#include "std_msgs/String.h"
#include <iostream>


namespace decision{
enum State
{
	ATTACK  = 0,      // attack
    DEFENCE = 1,      // defence
    SPY     = 2,      // spy on enemy
    UNKOWN  = 3,      // unkown
};
enum Event
{
	ATTACKED   = 0,    // be attacked           ------------defence
	NOTHING    = 1,    // nothing happened      ------------unkown
	FIND_ENEMY = 2,	   // find enemy            ------------spy on enemy
	STOP       = 3,    // attack or defence stop
};

class StateMachine
{
public:
	StateMachine(State initState = UNKOWN) : state(initState), event(NOTHING){}
	~StateMachine(){}
	void attack(){ std::cout << "I am attacking!!!\n"; }
	void defend(){ std::cout << "I am defending!!!\n"; }
	void spy(){ std::cout << "I am spying on the enemy!!!\n"; }
	void doNothing(){ std::cout << "I am doing nothing!!!\n"; }
	void switchFromAttack(Event event);
	void switchFromDefence(Event event);
	void switchFromSpy(Event event);
	void switchFromUnkown(Event event);
    void handler(Event event);
    void set_event(Event event);
    State get_state(){ return state; }
    bool start();
private:
    State state;
    Event event;
};

// class StateMachine
// {
// public:
// 	StateMachine(State initState = UNKOWN) : state(initState), event(NOTHING){
// 		state_pub = nh_.advertise<std_msgs::String>("stateMachine/state", 1);
//         event_sub = nh_.subscribe("stateMachine/event", 10, eventCallback);
//         ros::Rate loop_rate(10);
//         while(ros::ok()){
//         	std_msgs::String msg;
//         	msg.data = "unkown";
//         	state_pub.publish(msg);
//         	ros::spinOnce();
//         	loop_rate.sleep();
//         }
// 	}
// 	~StateMachine(){}
// 	void attack(){ std::cout << "I am attacking!!!\n"; }
// 	void defend(){ std::cout << "I am defending!!!\n"; }
// 	void spy(){ std::cout << "I am spying on the enemy!!!\n"; }
// 	void doNothing(){ std::cout << "I am doing nothing!!!\n"; }
// 	void switchFromAttack(Event event);
// 	void switchFromDefence(Event event);
// 	void switchFromSpy(Event event);
// 	void switchFromUnkown(Event event);
//     void handler(Event event);
//     void set_event(std::string event);
//     State get_state(){ return state; }
//     bool start();
// private:
//     State state;
//     Event event;
//     std::string eventStr[4] = {"ATTACKED", "NOTHING", "FIND_ENEMY", "STOP"};
//     std::string stateStr[4] = {"ATTACK", "DEFENCE", "SPY", "UNKOWN"};
//     ros::NodeHandle nh_;
//     ros::Publisher state_pub;
//     ros::Subscriber event_sub;
//     void eventCallback(const std_msgs::String::ConstPtr& event){
//     	// set_event(event.data);
//     } 
// };
}
