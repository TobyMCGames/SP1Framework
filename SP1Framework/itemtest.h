#pragma once
#include <string>
#include <sstream>
#include "Objects.h"


class itemtest
{
private:
	Objects* item_test[1];
	WORD itemColor;
	string model;
	char icon;
	string function;
	bool item_exist;
	bool player_near;

public:
	itemtest();
	~itemtest();

	//get and set functions
	WORD getColor();
	string getModel();
	void setModel();

	//object stuffs
	int getX();
	int getY();
	char getIcon();
	string getFunction();
	void setObject();

	//state change
	bool is_item_exist();
	void change_exist();
	bool is_player_near();
	void change_near();
};
