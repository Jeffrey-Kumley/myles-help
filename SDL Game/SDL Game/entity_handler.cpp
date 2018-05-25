#include "kit.h"

Entity Entities[1000];

Entity * CreateEntity(const char * name, const char * entityFrame)
{
	for (int i = 0; i < 1000; ++i)
	{
		if (Entities[i].initialized == false)
		{
			Entities[i].Initalize();
			Entities[i].index = i;
			Entities[i].name = name;
			Entities[i].entityFrame = entityFrame;
			Entities[i].player.active = true;
			return &Entities[i];
		}
	}
	return nullptr;
}