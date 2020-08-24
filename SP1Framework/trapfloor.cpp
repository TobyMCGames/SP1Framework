#include "trapfloor.h"

trapfloor::trapfloor():
	icon(' '),
	color(0x9F),
	Active(false)
{
	c.X = 2;
	c.Y = 2;
}

trapfloor::~trapfloor()
{
}

void trapfloor::setIcon(char icon)
{
	this->icon = icon;
}

void trapfloor::setColor(WORD color)
{
	this->color = color;
}

void trapfloor::setCOORD(SHORT x, SHORT y)
{
	c.X = x;
	c.Y = y;
}

void trapfloor::setActive(bool state)
{
	Active = state;
}

char trapfloor::getIcon()
{
	return icon;
}

WORD trapfloor::getColor()
{
	return color;
}

SHORT trapfloor::getX()
{
	return c.X;
}

SHORT trapfloor::getY()
{
	return c.Y;
}

bool trapfloor::getState()
{
	return Active;
}
