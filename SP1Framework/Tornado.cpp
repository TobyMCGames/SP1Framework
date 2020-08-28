#include "Tornado.h"

Tornado::Tornado(int x, int y,char icon)
{
	c.X = x;
	c.Y = y;
	Spawner.X = x;
	Spawner.Y = y;
	this->icon = icon;
}

Tornado::~Tornado()
{

}

bool Tornado::reaction(Player& player, char tile)
{
	int x = 0;
	int y = 0;
	
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife(); // lose 1 life
		//c.X = player.getX();
		//c.Y = player.getY();
		switch (player.getFacing())
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
		//c.X = player.getX();
		//c.Y = player.getY();
		//gotoXY(c.X, c.Y);
		//return true;
	}
	return false;
}

