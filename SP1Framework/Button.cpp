#include "Button.h"

Button::Button(int x, int y, WORD color, string name) 
{
	this->x = x;
	this->y = y;
	this->color = color;
	this->name = name;
}

Button::~Button()
{

}

string Button::getName()
{
	return name;
}

int Button::getX(void)
{
	return x;
}

int Button::getY(void)
{
	return y;
}

void Button::renderButton(Console& console, bool onbutton)
{
	if (onbutton == false)
	{
		console.writeToBuffer(x, y, name, color);
	}
	else
	{
		console.writeToBuffer(x-2, y, "|<"+name+">|", color);
	}
}

