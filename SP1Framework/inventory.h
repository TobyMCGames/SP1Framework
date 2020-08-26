#pragma once
#include "Framework/console.h"
#include "Button.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;


class inventory
{
private:
	//inventory
	string items[4];
	string current_equipped;

	//buttons
	Button* buttons[4] = { nullptr, nullptr, nullptr, nullptr};
	int equipped_slot;

public:
	inventory();
	~inventory();

	//get functions
	string get_current_equipped();
	int get_equipped_slot();
	int checkButtons(COORD c);
	int pick_empty_slot();

	//set functions
	void item_add(string Item);
	void change_equipped_slot();
	void change_current_equipped();
	void renderInventory(Console& anotherC);
	void renderEquipChange(Console& anotherC);
};

