#include "kit.h"

Entity Entities[1000];

Entity * CreateEntity(const char * name, const char * entityFrame)
{
	for (int i = 0; i < 1000; ++i)
	{
		if (Entities[i].name == "NULL")
		{
			Entities[i].index = i;
			Entities[i].name = name;

			if (entityFrame == "player")
			{
				Entities[i].entityFrame = "player";

				Entities[i].player.active = true;
			}

			Entities[i].Initalize();
			
			return &Entities[i];
		}
	}
	return nullptr;
}