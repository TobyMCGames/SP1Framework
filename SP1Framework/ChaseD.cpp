#include "ChaseD.h"
ChaseD::ChaseD()
{
	spawner.X = 0;
	spawner.Y = 0;
	c.X = 0;
	c.Y = 0;
	direction = 'W';
	icon = 'V';
}

ChaseD::~ChaseD()
{
}

COORD ChaseD::getcord()
{
	return c;
}

COORD ChaseD::getspawnCord()
{
	return spawner;
}

char ChaseD::getdirection()
{
	return direction;
}

char ChaseD::geticon()
{
	return icon;
}

int ChaseD::getdistancex()
{
	return distancex;
}

int ChaseD::getdistancey()
{
	return distancey;
}

void ChaseD::setspawner()
{
	switch (direction)
	{
	case 'W':
		spawner.Y += 1;
		break;
	case 'A':
		spawner.X += 1;
		break;
	case 'S':
		spawner.Y -= 1;
		break;
	case 'D':
		spawner.X -= 1;
		break;
	}
}

void ChaseD::BTspawner()
{
	c.X = spawner.X;
	c.Y = spawner.Y;
}

void ChaseD::changeDirection(char d)
{
	direction = d;
}

void ChaseD::changeicon(char i)
{
	icon = i;
}

void ChaseD::setDistance(int dx, int dy)
{
	distancex = dx;
	distancey = dy;
}

/*void ChaseD::setDirection()
{
	if (distancex < 0)
	{
		direction = 'A';
	}
	else if (distancex > 0)
	{
		direction = 'D';
	}
	else if (distancey < 0)
	{
		direction = 'W';
	}
	else if (distancey > 0)
	{
		direction = 'S';
	}
}*/

void ChaseD::move()
{
	switch (direction)
	{
	case 'W':
		c.Y -= 1;
		c.X += 0;
		break;
	case 'A':
		c.X -= 1;
		c.Y += 0;
		break;
	case 'S':
		c.Y += 1;
		c.X += 0;
		break;
	case 'D':
		c.X += 1;
		c.Y += 0;
		break;
	case 'Q':
		c.X += 0;
		c.Y += 0;
		break;
	}
}
