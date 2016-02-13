#Version 2016.2.13

all: mission

mission:
	g++ --std=c++11 -ggdb ./tasks.cpp ./mission.cpp -o mission
