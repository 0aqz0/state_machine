namespace decision{
enum State
{
	ATTACK = 0;    // attack
    DEFENCE = 1;   // defence
    SPY = 2;       // spy 
    UNKOWN = 3;    // unkown
}
enum Event
{
	ATTACKED = 0;  // be attacked
	ATTACKING = 1; // attacking
	NOTHING = 2;   // nothing	
};
class StateMachine
{
public:
	StateMachine(State initState);
	~StateMachine();
private:
    State state;
    Event event;
}
}
