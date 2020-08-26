#include "Boulder.h"

Boulder::Boulder(int x, int y, char icon)
{
	c.X = x;
	c.Y = y;
	Spawner.X = x;
	Spawner.Y = y;
	this->icon = icon;
}

Boulder::~Boulder()
{

}

void Boulder::reaction(Player& player, char tile)
{
	switch (tile)
	{
	case 'W':
		c.X = Spawner.X;
		c.Y = Spawner.Y;
	}
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife();
		c.X = Spawner.X;
		c.Y = Spawner.Y;
	}
}