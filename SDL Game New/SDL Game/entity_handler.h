#pragma once

#include "kit.h"

class Entity
{
public:

	const char * name = "NULL";
	const char * entityFrame = "none";
	int index = -1;

	PlayerCMPT player;
	TransformCMPT transform;

	void Initalize()
	{
		transform.x = 0;
		transform.y = 0;

		player.transform = &transform;

		if (Debug)
			cout << "Initalized Entity \"" << name << "\" with frame \"" << entityFrame << "\"" << endl;
	}

	void Update()
	{
		if (KEYISDOWN(VK_SPACE) PRESSED)
		{
			player.Update();
			transform.Write();
			cout << "x from entity: " << transform.x << endl;
		}
	}
};