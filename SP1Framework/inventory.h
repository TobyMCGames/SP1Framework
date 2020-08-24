#pragma once
#include "Framework/console.h"
#include "itemtest.h"
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
	string items[6];
	string current_equipped;

	//buttons
	Button* buttons[6] = { nullptr, nullptr, nullptr, nullptr,  nullptr, nullptr };
	int equipped_slot;

public:
	inventory();
	~inventory();

	//get functions
	string get_current_equipped();
	int get_equipped_slot();
	int checkButtons(COORD c);

	//set functions
	void change_equipped_slot();
	void change_current_equipped();
	void renderInventory(Console& anotherC);
	void renderEquipChange(Console& anotherC);
};



