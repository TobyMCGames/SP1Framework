#include "Item.h"


Item::Item(ITEM_TYPE argumentItemType) :
	itemType(argumentItemType),
	name(" "),
	amt(0),
	max_stacks(4),
	symbol("  ")
{
}


Item::~Item()
{

}

std::string Item::getname()
{
	return name;
}

int Item::getamt()
{
	return amt;
}

int Item::getmaxstacks()
{
	return max_stacks;
}

std::string Item::getsymbol()
{
	return symbol;
}


void Item::setname(std::string name)
{
	this->name = name;
}

void Item::increase()
{
	amt++;
}

void Item::decrease()
{
	amt--;
}

void Item::setmax(int max)
{
	max_stacks = max;
}

void Item::setsymbol(std::string symbol)
{
	this->symbol = symbol;
}


