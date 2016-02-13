#Version 2016.2.13

all: mc

mc:
	g++ --std=c++11 -ggdb ./tasks.cpp ./missioncontrol.cpp -o missioncontrol
