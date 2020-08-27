#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	int amt;
public:
	HealthPotion();
	~HealthPotion();

	void use();

};

