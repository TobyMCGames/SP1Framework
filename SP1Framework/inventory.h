#pragma once
#include <string>

class inventory {
private:
	string items[6]; // (item1, item2, item3...)
	int equipped_slot;
	int no_of_items;
	bool itemactive;

public:
	inventory();
	~inventory();
	void equipchange();
	int get_no_of_items();
	bool item_active();
}