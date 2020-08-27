#include "HealthPotion.h"

HealthPotion::HealthPotion() : 
	Item(ITEM_TYPE::HP),
	amt(0)
{
	setname("HP Potion");
	setsymbol("00");
	setmax(4);
	amt++;
}

HealthPotion::~HealthPotion()
{
}

void HealthPotion::use()
{
}

