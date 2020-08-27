#include "MovingD.h"

MovingD::MovingD()
{
	Spawner.X = 0;
	Spawner.Y = 0;
	c.X = 0;
	c.Y = 0;
	direction = 'W';
	icon = 'E';
}

MovingD::~MovingD()
{

}

COORD MovingD::getcord()
{
	return c;
}

COORD MovingD::getSpawnCord()
{
	return Spawner;
}

char MovingD::getdirection()
{
	return direction;
}

char MovingD::geticon()
{
	return icon;
}


void MovingD::BTSpawner()
{
	c.X = Spawner.X;
	c.Y = Spawner.Y;
}

void MovingD::changeDirection(char d)
{
	direction = d;
}

void MovingD::move()
{
	switch (direction)
	{
	case 'W':
		c.Y -= 1;
		break;
	case 'A':
		c.X -= 1;
		break;
	case 'S':
		c.Y += 1;
		break;
	case 'D':
		c.X += 1;
		break;
	}
}