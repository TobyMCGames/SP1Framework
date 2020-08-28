#include "Doors.h"

Doors::Doors()
{
	c.X = 0;
	c.Y = 0;
	doortype = 0;
	Activated = true;
	color = 0xB0;
}

Doors::~Doors()
{
}

int Doors::getX()
{
	return c.X;
}

int Doors::getY()
{
	return c.Y;
}

int Doors::getDoorType()
{
	return doortype;
}

int Doors::getState()
{
	return Activated;
}

WORD Doors::getcolor()
{
	return color;
}

void Doors::setcord(int x, int y)
{
	c.X = x;
	c.Y = y;
}

void Doors::setType(int i)
{
	doortype = i;
	if (doortype == 1)
	{
		color = 0xB0;
	}
	else
	{
		color = 0x40;
	}
}

void Doors::changeState()
{
	if (Activated == true) {
		Activated = false;
	}
	/*if (Activated == true)
	{
		if (doortype == 1)
		{
			color = 0xB0;
		}
		else
		{
			color = 0x40;
		}
	}*/
	//else
	//{
		color = 0x8F;
	//}
}
