#include "itemtest.h"


itemtest::itemtest() :
	itemColor(0x6E),
	model("  "),
	icon('I'),
	function("test"),
	item_exist(false),
	player_near(false)
{
	item_test[0] = nullptr;
}
itemtest::~itemtest()
{

}


//get and set functions
WORD itemtest::getColor()
{
	return itemColor;
}
std::string itemtest::getModel()
{
	return model;
}
void itemtest::setModel()
{
	ostringstream ss;
	ss << char(223) << char(223);
	model = ss.str();
}


//set variables for object
int itemtest::getX()
{
	return 10;
}
int itemtest::getY()
{
	return 15;
}
char itemtest::getIcon()
{
	return icon;
}
string itemtest::getFunction()
{
	return function;
}
void itemtest::setObject()
{
	item_test[0] = new Objects(getX(), getY(), getFunction(), getIcon());
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