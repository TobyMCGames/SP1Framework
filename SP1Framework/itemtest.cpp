#include "itemtest.h"

itemtest::itemtest()
{
	item_exist = false;
	player_near = false;
}

itemtest::~itemtest()
{

}


//set functions
void itemtest::setXY(int x, int y)
{
	c.X = 100;
	c.Y = 25;
}
void itemtest::setFunction(string function)
{
	Function = function;
}
void itemtest::setIcon(char icon)
{
	Icon = icon;
}


//item exist state change
bool itemtest::is_item_exist()
{
	return item_exist;
}
void itemtest::change_exist()
{
	item_exist = !item_exist;
}
bool itemtest::is_player_near()
{
	return player_near;
}
void itemtest::change_near()
{
	player_near = !player_near;
}
