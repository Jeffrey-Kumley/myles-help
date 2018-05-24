#include "kit.h"

Entity Entities[1000];

Entity * CreateEntity(const char * name, const char * entityFrame)
{
	Entity entity;
	entity.name = name;
	
	if (entityFrame == "player")
	{
		entity.entityFrame = "player";
		
	}

	entity.Initalize();

	for (int i = 0; i < 1000; ++i)
	{
		if (Entities[i].name == "NULL")
		{
			entity.index = i;

			Entities[i] = entity;
			
			entity.player.active = true;
		}
	}

	return &entity;
}