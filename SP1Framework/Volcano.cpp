#include "Volcano.h"

int Volcano::amount = 0;
Volcano::Volcano()
{
	setIcon('F');
	setColor(0x8F);
	x = 0;
	y = 0;
	direction = 0;
	amount++;
}

Volcano::~Volcano()
{
	amount--;
}

int Volcano::getxchange()
{
	return x;
}

int Volcano::getychange()
{
	return y;
}

int Volcano::getamt()
{
	return amount;
}

void Volcano::toggle()
{
	if (getState() == true)
	{
		setActive(false);
		setColor(0x8F);
	}
	else
	{
		setActive(true);
		setColor(0x44);
	}

}

void Volcano::setDirection(int i)
{
	switch (i)
	{
	case 0:
		x = 0;
		y = -1;
		break;
	case 1:
		x = 1;
		y = 0;
		break;
	case 2:
		x = 0;
		y = 1;
		break;
	case 3:
		x = -1;
		y = 0;
		break;
	}
}