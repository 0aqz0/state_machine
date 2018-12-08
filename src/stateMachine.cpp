#include "stateMachine.h"
#include <thread>

namespace decision{

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

void StateMachine::set_event(Event event){
    this->event = event;  
}

void StateMachine::handler(Event event){
	while(true){
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
	    }
    }
}

bool StateMachine::start(){
    std::thread new_thread(handler);
    new_thread.detach();
    return true;
}

}