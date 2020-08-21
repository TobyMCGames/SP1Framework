#include "Objects.h"

Objects::Objects(int x, int y, string function, char icon)
{
	c.X = x;
	c.Y = y;
	this->function = function;
	this->icon = icon;
}

Objects::~Objects()
{

}

int Objects::getX()
{
	return c.X;
}

int Objects::getY()
{
	return c.Y;
}

char Objects::geticon()
{
	return icon;
}

string Objects::getfunction()
{
	return function;
}


