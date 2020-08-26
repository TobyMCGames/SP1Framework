#pragma once
#include <string>
#include <sstream>
#include "Objects.h"
#include "player.h"
#include "inventory.h"



class item
{
private:
	Objects* object[2] = { nullptr, nullptr };
	char itemIcons[2] = { '1', '2' };
	int no_of_items;
public:
	item();
	~item();

	//get functions
	char itemSetXY(char icon, int x, int y);
	bool is_itemIcon(char icon);
	char what_itemIcon(char icon);
	int getX(char icon);
	int getY(char icon);
	string getFunction(char icon);
};

