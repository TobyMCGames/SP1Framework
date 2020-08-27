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
	switch (tile)
	{
	case 'W': //if tornado touches the Walls
		return true;
	}
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife(); // lose 1 life
		player.setX(2);
		player.setY(2);
		c.X = player.getX();
		c.Y = player.getY();
		gotoXY(c.X, c.Y);
		return true;
	}
	return false;
}

