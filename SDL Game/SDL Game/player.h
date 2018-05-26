#pragma once

#include "kit.h"

class PlayerCMPT
{
public:

	TransformCMPT * transform;

	bool active = false;

	void Update()
	{
		cout << "Transform: " << transform << endl;

		if (KEYISDOWN(VK_A))
			--transform->x;
		else if (KEYISDOWN(VK_D))
			++transform->x;
		if (KEYISDOWN(VK_W))
			++transform->y;
		else if (KEYISDOWN(VK_S))
			--transform->y;

		if (transform != nullptr)
			std::cout << "x from player: " << transform->x << endl;
	}
};