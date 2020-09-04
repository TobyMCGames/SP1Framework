#include "Virus.h"

Virus::Virus(int x, int y, char icon)
{
	c.X = x;
	c.Y = y;
	spawner.X = x;
	spawner.Y = y;
	this->icon = icon;
}

Virus::~Virus()
{

}

bool Virus::reaction(Player& player, char tile)
{
	switch (tile)
	{
	case 'H':
	case 'W':
		changeicon('W');
		BTspawner();
		changeicon('V');
		return true;
	}
	if ((c.X == player.getX()) && (c.Y == player.getY()))
	{
		player.decreaselife();
		return false;
	}
	return false;
}
