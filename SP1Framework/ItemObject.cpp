#include "ItemObject.h"

ItemObject::ItemObject()
{
	c.X = 0;
	c.Y = 0;

}

ItemObject::~ItemObject()
{

}

int ItemObject::getX()
{
	return c.X;
}
int ItemObject::getY()
{
	return c.Y;
}
char ItemObject::getIcon()
{
	return Icon;
}
string ItemObject::getFunction()
{
	return Function;
}


void ItemObject::setXY()
{
	
}
void ItemObject::setIcon()
{
	
}
void ItemObject::setFunction()
{
	
}
