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
	bool quit = false;
	while(!quit)
	{
		//If it's in the middle of something, wait
		//Otherwise query modeling to get distances and update
		//If it's close enough, launch into task
	}
	delete t;
	return 0;
}
