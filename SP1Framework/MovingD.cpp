#include "MovingD.h"

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
	case 'A':
		c.X -= 1;
	case 'S':
		c.Y += 1;
	case 'D':
		c.X += 1;
	}
}