#include "tasks.hpp"

Task::Task(int t, int p, float c, int t2, int d) : task(t), points(p), certainty(c), time(t2), dist(d)
{
	calc(dist);
}

Task::Task(FILE* confin)
{
	fscanf(confin, "%i ", &task);
	fscanf(confin, "%i ", &points);
	fscanf(confin, "%f ", &certainty);
	fscanf(confin, "%i ", &time);
	fscanf(confin, "%i ", &dist);
	calc(dist);
}

void Task::calc(int d)
{
	dist = d;
	value = points*certainty/(time+dist);
}

int Task::runtask()
{
	switch(task)
	{
	
	}
}

Tasks::Tasks(FILE* confin)
{
	fscanf(confin, "%i ", &numtasks);
	for(int i = 0; i < numtasks; i++)
	{
		tasklist.push_back(Task(confin));
	}
}

void Tasks::update(FILE* distin)
{
	for(int i = 0; i < numtasks; i++)
	{
		int dist;
		fscanf(distin, "%i ", &dist);
		tasklist[i].calc(dist);
	}
}

int Tasks::best()
{
	float hval = 0;
	int bestT;
	for(int i = 0; i < numtasks; i++)
	{
		if(tasklist[i].value > hval){bestT = i;}
	}
	return bestT;
}
