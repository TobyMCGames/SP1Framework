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
	string items[6]; // (item1, item2, item3...)
	string current_equipped;
	int equipped_slot;
	int no_of_items;
	bool itemactive;

	//buttons
	Button* buttons[6] = { nullptr, nullptr, nullptr, nullptr,  nullptr, nullptr };
	int button_pressed;

public:
	inventory();
	~inventory();

	//get functions
	int get_equipped_slot();
	int get_no_of_items();

	//item usage
	void item_active_change();
	bool item_active();

	//inventory change
	void equipchange();
	void item_pickup();
	void item_drop();
	void list_rearrange();

	//buttons
	void which_button_pressed(Console& anotherC);
};

