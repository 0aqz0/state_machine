# state_machine
a state-machine ROS package

## Guide

1. download the repo:
```bash
git clone git@github.com:0aqz0/state_machine.git
```

2. catkin_make in your workspace
```bash
catkin_make
```

3. source in your workspace
```bash
source devel/setup.bash
```

4. run the state_machine_node
```bash
roscore
rosrun state_machine state_machine_node
```

5. echo the topics about state and event
```
rostopic echo state_machine/state
rostopic echo state_machine/event
```
