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
	ATTACKING  = 1,    // attacking             ------------attack
	NOTHING    = 2,    // nothing happened      ------------unkown
	FIND_ENEMY = 3,	   // find enemy            ------------spy on enemy
};
class StateMachine
{
public:
	StateMachine(State initState);
	~StateMachine();
private:
    State state;
    Event event;
};
}
