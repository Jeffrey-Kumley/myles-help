#pragma once

#include "kit.h"

class PlayerCMPT
{
public:

	TransformCMPT * transform;

	bool active = false;

	void Update()
	{
		if (active)
		{
			if (KEYISDOWN(VK_2))
				std::cout << "x from player: " << transform->x << endl;

			if (KEYISDOWN(VK_A) PRESSED)
				cout << endl;
			if (KEYISDOWN(VK_D) PRESSED)
				cout << "'D' pressed" << endl;
			if (KEYISDOWN(VK_W) PRESSED)
				cout << "'W' pressed" << endl;
			if (KEYISDOWN(VK_S) PRESSED)
				cout << "'S' pressed" << endl;
		}
	}
};