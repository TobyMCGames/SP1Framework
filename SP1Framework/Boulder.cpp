#include "Boulder.h"

Boulder::Boulder(int x, int y)
{
	c.X = x;
	c.Y = y;
	Spawner.X = x;
	Spawner.Y = y;
}

Boulder::~Boulder()
{

}

void Boulder::reaction(Player& player)
{
	player.decreaselife();
	c.X = Spawner.X;
	c.Y = Spawner.Y;
}