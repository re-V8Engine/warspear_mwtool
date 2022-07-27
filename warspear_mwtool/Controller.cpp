#include "stdafx.h"

Controller::Controller(vector<PrimaryInstance*> instances)
{
	primary = instances[0];
	auto it = instances.begin();
	it++;
	for (auto instance = it; instance != instances.end(); instance++)
	{
		second.push_back(*instance);
	}
}

void Controller::Follower()
{
	short actualX = primary->getLocalPlayer()->destinatonX;
	short actualY = primary->getLocalPlayer()->destinatonY;

	if(actualX != prevX || actualY != prevY)
	{
		prevX = actualX;
		prevY = actualY;
		for (auto instance : second)
		{
			if (instance != 0)
			{
				instance->Click(prevX, prevY);
			}

		}

	}
	
}
