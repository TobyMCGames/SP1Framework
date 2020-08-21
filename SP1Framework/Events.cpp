#include "Events.h"

Events::Events():
	isActive(false)
{
}

Events::~Events()
{
}

void Events::toggle()
{
	if (isActive == false)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}
}

bool Events::getActive()
{
	return isActive;
}
