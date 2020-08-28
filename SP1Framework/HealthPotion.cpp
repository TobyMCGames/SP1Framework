#include "HealthPotion.h"

HealthPotion::HealthPotion() : 
	Item(ITEM_TYPE::HP)
{
	setname("HP Potion");
	setsymbol('0');
	setmax(4);
}

HealthPotion::~HealthPotion()
{
}

