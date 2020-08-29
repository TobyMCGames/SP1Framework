#include "Tsunami.h"

int Tsunami::amount = 0;
Tsunami::Tsunami()
{
	setIcon('M');
	setColor(0x8F);
	x = 0;
	y = 0;
	direction = 'W';
	amount++;
}

Tsunami::~Tsunami()
{
	amount--;
}

int Tsunami::getamt()
{
	return amount;
}

int Tsunami::getxchange()
{
	return x;
}

int Tsunami::getychange()
{
	return y;
}

char Tsunami::getDirection()
{
	return direction;
}

void Tsunami::toggle()
{
	if (getState() == true)
	{
		setActive(false);
		setColor(0x8F);
	}
	else
	{
		setActive(true);
		setColor(0x19);
	}
}

void Tsunami::setDirection(int i)
{
	switch (i)
	{
	case 0:
		x = 0;
		y = -1;
		direction = 'A';
		break;
	case 1:
		x = 1;
		y = 0;
		direction = 'W';
		break;
	case 2:
		x = 0;
		y = 1;
		direction = 'D';
		break;
	case 3:
		x = -1;
		y = 0;
		direction = 'S';
		break;
	}
}

bool Tsunami::reaction(Player& player, char moveP)
{
	int x = 0;
	int y = 0;

	if ((getX() == player.getX()) && (getY() == player.getY()))
	{
		switch (moveP)
		{
		case 'W':
			y = 1;
			break;
		case 'A':
			x = 1;
			break;
		case 'S':
			y = -1;
			break;
		case 'D':
			x = -1;
			break;
		}
		player.setX(player.getX() + x);
		player.setY(player.getY() + y);
	}
	return false;
}