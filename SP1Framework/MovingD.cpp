#include "MovingD.h"

MovingD::MovingD()
{
	c.X = 0;
	c.Y = 0;
	direction = 'W';
}

MovingD::MovingD(int x,  int y) //Starting position
{
	c.X = x;
	c.Y = y;
	direction = 'W';
}

MovingD::~MovingD()
{

}

COORD MovingD::getcord()
{
	return c;
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