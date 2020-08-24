#pragma once
#include <string>
#include <sstream>
#include "Objects.h"
#include "player.h"


class item_general
{
private:
	string current_item;
	char Icon;
public:
	item_general();
	~item_general();

	//set functions
	void setX(int x);
	void setY(int y);
	//void setIcon();

	//get functions
	int getX();
	int getY();
	string getFunction();
	bool is_item_exist();
	//bool is_player_near();
	char getIcon();

	void change_exist();
	//void change_near();
	void change_current_item();
};

struct Items
{
	COORD c;
	char icon;
	string function;
	bool item_exist;
	//bool player_near;
};
