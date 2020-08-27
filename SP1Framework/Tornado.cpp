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
	switch (tile)
	{
	case 'W': //if tornado touches the Walls
		return true;
	}
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife(); // lose 1 life
		c.X = player.getX();
		c.Y = player.getY();
		switch (player.getFacing())
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
		c.X = player.getX();
		c.Y = player.getY();
		gotoXY(c.X, c.Y);
		return true;
	}
	return false;
}

