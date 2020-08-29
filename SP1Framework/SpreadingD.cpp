#include "SpreadingD.h"

SpreadingD::SpreadingD() :
	icon(' '),
	color(0x8F),
	Active(false)
{
	c.X = 2;
	c.Y = 2;
}

SpreadingD::~SpreadingD()
{
}

void SpreadingD::setIcon(char icon)
{
	this->icon = icon;
}

void SpreadingD::setColor(WORD color)
{
	this->color = color;
}

void SpreadingD::setCOORD(SHORT x, SHORT y)
{
	c.X = x;
	c.Y = y;
}

void SpreadingD::setActive(bool state)
{
	Active = state;
}

char SpreadingD::getIcon()
{
	return icon;
}

WORD SpreadingD::getColor()
{
	return color;
}

SHORT SpreadingD::getX()
{
	return c.X;
}

SHORT SpreadingD::getY()
{
	return c.Y;
}

bool SpreadingD::getState()
{
	return Active;
}
