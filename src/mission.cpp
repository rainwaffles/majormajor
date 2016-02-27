#include "tasks.hpp"
#include <stdio.h>

Tasks* t;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		//Default config file
		t = new Tasks(fopen("./default.conf", "r"));
	}
	else
	{
		t = new Tasks(fopen(argv[1], "r"));
	}
	FILE* missionin = fopen("./missionin", "r");
	FILE* missionout = fopen("./missionout", "w");
	
	//Set up modeling stuff: fprintf(missionout, "s m ???");
	
	bool quit = false;
	int tasknum = -1;
	while(!quit)
	{
		//If it's in the middle of something, wait
		//Otherwise query modeling to get distances and update
		//If it's close enough, launch into task
		if(tasknum < 0)
		{
			fprintf(missionout, "q m s ");
			//Get distances, update, set direction
		}
		else
		{
			int status = t->tasklist[tasknum].runtask();
			if(status != 0){t->tasklist[tasknum].certainty = 0.001;}
			else{t->tasklist.erase(tasknum); tasknum = -1;}
		}
	}
	delete t;
	return 0;
}
