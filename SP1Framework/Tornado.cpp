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

void Tornado::reaction(Player& player, char tile)
{
	switch (tile)
	{
	case 'W': //if tornado touches the Walls
		c.X = Spawner.X;
		c.Y = Spawner.Y;
	}
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife(); // lose 1 life
		if (c.X != 'W' && c.Y != 'W')
		{
			player.setX(rand() % 135);
			player.setY(rand() % 135);
			c.X = player.getX();
			c.Y = player.getY();
			gotoXY(c.X, c.Y);
		}
		//player.setX(2);
		//player.setY(2);
		c.X = Spawner.X; //Tornado go back to original pos
		c.Y = Spawner.Y;
	}
}

