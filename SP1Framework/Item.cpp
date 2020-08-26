#include "Item.h"


Item::Item() :
	name(" "),
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

void Item::setmax(int max)
{
	max_stacks = max;
}

void Item::setsymbol(char symbol)
{
	this->symbol = symbol;
}


