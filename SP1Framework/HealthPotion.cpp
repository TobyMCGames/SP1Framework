#include "HealthPotion.h"
#include "Player.h"

HealthPotion::HealthPotion()
{
	setname("HP Potion");
	setsymbol('00');
	setmax(4);
}

HealthPotion::~HealthPotion()
{
}

void HealthPotion::use(Player& player)
{
	player.increaselife();
}
