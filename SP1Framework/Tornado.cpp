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
	case 'P': //if tornado touches P
		player.decreaselife(); // lose 1 life
		player.setX(2); //setting player to original pos
		player.setY(2);
		c.X = player.getX();
		c.Y = player.getY();
		gotoXY(c.X, c.Y);
		c.X = Spawner.X; //Tornado go back to original pos
		c.Y = Spawner.Y;
	case 'W': //if tornado touches the Walls
		c.X = Spawner.X;
		c.Y = Spawner.Y;

	}
}

