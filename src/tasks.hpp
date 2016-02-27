#ifndef TASKS_H__
#define TASKS_H__

/*
#include "gate.hpp"
#include "buoys.hpp"
#include "lgate.hpp"
#include "bins.hpp"
#include "torpedo.hpp"
#include "pinger.hpp"
*/

#include <stdio.h>
#include <vector>

/*
	0 = Gate
	1 = Buoy
	2 = LGate
	3 = Bins
	4 = Torpedos
	5 = Pingers
*/

struct Task
{
	Task(FILE* confin);
	Task(int t, int p, float c, int t2, int d);

	int task;
	int points;
	float certainty;
	int time;
	int dist;
	
	float value;
	void calc(int d);
	
	int runtask();
};

struct Tasks
{
	Tasks(FILE* confin);
	
	int numtasks;
	std::vector<Task> tasklist;

	void update(FILE* distin);
	int best();
};

#endif
