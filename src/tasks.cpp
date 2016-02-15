#include "tasks.hpp"

Task::Task(int t, int p, float c, int t2, int dist) : task(t), points(p), certainty(c), time(t2)
{
	calc(dist);
}

Task::Task(FILE* confin)
{
	fscanf(confin, "%i ", &task);
	fscanf(confin, "%i ", &points);
	fscanf(confin, "%f ", &certainty);
	fscanf(confin, "%i ", &time);
	int dist;
	fscanf(confin, "%i ", &dist);
	calc(dist);
}

void Task::calc(int dist)
{
	value = points*certainty/time/dist;
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
		if(tasklist[i].value > hval){bestT = tasklist[i].task;}
	}
	return bestT;
}
