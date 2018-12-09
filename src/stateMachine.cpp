#include "state_machine/stateMachine.h"
#include <ros/console.h>
#include <time.h>
#include <thread>

namespace decision{

State StateMachine::state(UNKOWN);
Event StateMachine::event(NOTHING);

void StateMachine::switchFromAttack(Event event){
	if (event == STOP)
	{
		state = SPY;
    	std::cout << "Switch from attack to spy\n";
	}
}

void StateMachine::switchFromDefence(Event event){
    if (event == STOP)
    {
    	state = SPY;
    	std::cout << "Switch from defence to spy\n";
    }
}

void StateMachine::switchFromSpy(Event event){
    if (event == FIND_ENEMY)
    {
    	state = ATTACK;
    	std::cout << "Switch from spy to attack!\n";
    }
    else if (event == ATTACKED)
    {
    	state = DEFENCE;
    	std::cout << "Switch from spy to defence\n";
    }
}

void StateMachine::switchFromUnkown(Event event){
    if (event == NOTHING)
    {
    	state = SPY;
    	std::cout << "Switch from unkown to spy\n";
    }
    else if (event == ATTACKED)
    {
    	state = DEFENCE;
    	std::cout << "Switch from unkown to defence\n";    
    }
}

void StateMachine::handler(){
	while(true){
		time_t seconds;
		seconds = time(NULL);
		int count = 0;
        if (seconds%10==0)
        {
        	switch(count){
        		case 0: event = ATTACKED; count++; 
        		    break;
        		case 1: event = NOTHING; count++; 
        		    break;
        		case 2: event = FIND_ENEMY; count++; 
        		    break;
        		case 3: event = STOP; count = 0; 
        		    break;
        		default:
        		    break;
        	}
        	std::cout << count << "\n";
        	ROS_INFO("HELLO");
        }
        
	    switch(state){
	    	case ATTACK:
	    	    switchFromAttack(event);
	    	    break;
	    	case DEFENCE:
	    	    switchFromDefence(event);
	    	    break;
	    	case SPY:
	    	    switchFromSpy(event);
	    	    break;
	    	case UNKOWN:
	    	    switchFromUnkown(event);
	    	    break;
	    	default:
	    	    break;
	    }
    }
}

bool StateMachine::start(){
    std::thread new_thread(&StateMachine::handler, StateMachine());
    new_thread.detach();
    // handler();
    return true;
}

}