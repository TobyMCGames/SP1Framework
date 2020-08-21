#pragma once
#include "Framework/console.h"
#include "itemtest.h"
#include <string>
using namespace std;

class inventory
{
private:
	string items[6]; // (item1, item2, item3...)
	//string current_equipped;
	int equipped_slot;
	int no_of_items;
	bool itemactive;

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
};


/*
General controls for inventory:
spacebar to interact (pickup/use item)
leftclick to select item to use in inventory
another button to be chosen later (or mouse click) to drop current equiped item

Things that might be changed:
inventory changed to 7 slots (including the equipped slot instead of being a copy)

How inventory works:
there are 6 item slots that the player can use to store items for later
equiping an item will highlight that item slot green and also show a copy of the item on the bottom (current equiped slot)
items cant be collected if the inventory is full
only 1 item can be held at a time
user can equip an empty slot that does not do anything



Other inventory stuffs to be done:
items to be created (maybe 2 or 3 for now)
UI for the inventory slots to be rendered
keyboard and mouse controls to be added for the inventory
random location for items to spawn
items to have functions


Stuffs to be added if time is available:
collectables for a side objective
a light system where a torch would help with vision?
enemies and maybe a small fighting system?(/avoidance system)
*/
