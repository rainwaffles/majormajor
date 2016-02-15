#ifndef TASKS_H__
#define TASKS_H__

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

//IDK what to name all these things

struct Task
{
	Task(FILE* confin);
	Task(int t, int p, float c, int t2, int dist);

	int task;
	int points;
	float certainty;
	int time;

	float value;
	void calc(int dist);
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
