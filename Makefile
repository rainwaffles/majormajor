#Version 2016.2.15

all: mission

mission:
	g++ --std=c++11 -ggdb ./src/tasks.cpp ./src/mission.cpp -o mission

clean:
	rm -f ./mission
