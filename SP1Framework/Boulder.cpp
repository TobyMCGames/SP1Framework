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

bool Boulder::reaction(Player& player, char tile)
{
	switch (tile)
	{
	case 'W':
		BTSpawner();
		return true;
	}
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife();
		BTSpawner();
		return true;
	}
	return false;
}