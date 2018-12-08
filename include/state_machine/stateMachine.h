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
	StateMachine(State initState) : state(UNKOWN), event(NOTHING){}
	~StateMachine();
	void attack(){ std::cout << "I am attacking!!!\n"; }
	void defend(){ std::cout << "I am defending!!!\n"; }
	void spy(){ std::cout << "I am spying on the enemy!!!\n"; }
	void doNothing(){ std::cout << "I am doing nothing!!!\n"; }
	void switchFromAttack(Event event);
	void switchFromDefence(Event event);
	void switchFromSpy(Event event);
	void switchFromUnkown(Event event);
    void handler(Event event);
    void set_event(Event event){ this->event = event; }
private:
    State state;
    Event event;
};
}
