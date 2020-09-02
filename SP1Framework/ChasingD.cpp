#include "ChasingD.h"

ChasingD::ChasingD()
{
	spawner.X = 0;
	spawner.Y = 0;
	c.X = 0;
	c.Y = 0;
	direction = 'W';
	icon = 'V';
}

ChasingD::~ChasingD()
{
}

COORD ChasingD::getcord()
{
	return c;
}

COORD ChasingD::getspawnCord()
{
	return spawner;
}

char ChasingD::getdirection()
{
	return direction;
}

char ChasingD::geticon()
{
	return icon;
}

void ChasingD::setspawner()
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

void ChasingD::BTspawner()
{
	c.X = spawner.X;
	c.Y = spawner.Y;
}

void ChasingD::changeDirection(char d)
{
	direction = d;
}

void ChasingD::setDistance(int dx, int dy)
{
	distancex = dx;
	distancey = dy;
}

void ChasingD::move()
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
