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
inline const char* stateToString(State state){
	switch(state){
		case ATTACK: return "ATTACK";
		case DEFENCE: return "DEFENCE";
		case SPY: return "SPY";
		default: return "UNKOWN";
	}
}
inline const char* eventToString(Event event){
	switch(event){
		case ATTACKED: return "ATTACKED";
		case NOTHING: return "NOTHING";
		case FIND_ENEMY: return "FIND_ENEMY";
        case STOP: return "STOP";
	}
}
inline Event stringToEvent(const char* event){
	if (event == "ATTACKED")
	{
		return ATTACKED;
	}
    else if (event == "NOTHING")
    {
    	return NOTHING;
    }
    else if (event == "FIND_ENEMY")
    {
    	return FIND_ENEMY;
    }
    else
    	return STOP;
}
class StateMachine
{
public:
	StateMachine(){}
	// StateMachine(State initState = UNKOWN): state(initState), event(NOTHING) {}
	~StateMachine(){}
	void attack(){ std::cout << "I am attacking!!!\n"; }
	void defend(){ std::cout << "I am defending!!!\n"; }
	void spy(){ std::cout << "I am spying on the enemy!!!\n"; }
	void doNothing(){ std::cout << "I am doing nothing!!!\n"; }
	void switchFromAttack(Event event);
	void switchFromDefence(Event event);
	void switchFromSpy(Event event);
	void switchFromUnkown(Event event);
    void handler();
    void set_event(const char* event){ this->event = stringToEvent(event); }
    const char* get_state(){ return stateToString(state); } 
    const char* get_event(){ return eventToString(event); }
    bool start();
private:
    static State state;
    static Event event;
};

}
