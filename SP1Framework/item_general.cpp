#include "item_general.h"

Items rock;

item_general::item_general()
{
	current_item = "rock";
	Icon = 'I';
	rock.icon = Icon;

	rock.c.X = 2;
	rock.c.Y = 2;
	rock.function = "rock";
	rock.item_exist = true;
}
item_general::~item_general()
{

}

//set functions
void item_general::setX(int x)
{
	if (current_item == "rock") {
		rock.c.X = x;
	}
}
void item_general::setY(int y)
{
	if (current_item == "rock") {
		rock.c.Y = y;
	}
}
/*
void item_general::setIcon()
{
	if (current_item == "rock") {
		rock.icon = Icon;
	}
}
*/


//get functions
int item_general::getX()
{
	if (current_item == "rock") {
		return rock.c.X;
	}
}
int item_general::getY()
{
	if (current_item == "rock") {
		return rock.c.Y;
	}
}
char item_general::getIcon()
{
	if (current_item == "rock") {
		return rock.icon;
	}
}
string item_general::getFunction()
{
	if (current_item == "rock") {
		return rock.function;
	}
}
bool item_general::is_item_exist()
{
	if (current_item == "rock") {
		return rock.item_exist;
	}
}
/*
bool item_general::is_player_near()
{
	if (current_item == "rock") {
		return rock.player_near;
	}
}
*/


//change state
void item_general::change_exist()
{
	if (current_item == "rock") {
		rock.item_exist = !rock.item_exist;
	}
}
/*
void item_general::change_near()
{
	if (current_item == "rock") {
		rock.player_near = !rock.player_near;
	}
}
*/
void item_general::change_current_item()
{

}


