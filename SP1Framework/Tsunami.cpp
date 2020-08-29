#include "Tsunami.h"

Tsunami::Tsunami()
{
	setIcon('M');
	setColor(0x8F);
}

Tsunami::~Tsunami()
{
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

bool Tsunami::reaction(Player& player, char moveP)
{
	int x = 0;
	int y = 0;

	if ((getX() == player.getX()) && (getY() == player.getY()))
	{
		//player.decreaselife(); // lose 1 life
		switch (moveP)
		{
		case 'W':
			y = 3;
			break;
		case 'A':
			x = 3;
			break;
		case 'S':
			y = -3;
			break;
		case 'D':
			x = -3;
			break;
		}
		player.setX(player.getX() + x);
		player.setY(player.getY() + y);
	}
	return false;
}