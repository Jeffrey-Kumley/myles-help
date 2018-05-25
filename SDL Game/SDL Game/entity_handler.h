#pragma once

#include "kit.h"

class Entity
{
public:

	const char * name = "NULL";
	const char * entityFrame = "none";
	int index = -1;
	int initialized = false;

	PlayerCMPT player;
	TransformCMPT transform;

	void Initalize()
	{
		initialized = true;

		transform.x = 0;
		transform.y = 0;

		player.transform = &transform;

		if (Debug)
			cout << "Initalized Entity \"" << name << "\" with frame \"" << entityFrame << "\"" << endl;
	}

	void Update()
	{
		player.Update();

		if (KEYISDOWN(VK_1))
			cout << "x from entity: " << transform.x << endl;
	}
};