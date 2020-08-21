#include "inventory.h"

inventory::inventory()
{
	items[0] = "none"; // 'none' or 'empty' will be used to denote an unused slot
	items[1] = "none";
	items[2] = "none";
	items[3] = "none";
	items[4] = "none";
	items[5] = "none";
	current_equipped = "none";
	equipped_slot = 0;
	no_of_items = 1;
	itemactive = false;
}

inventory::~inventory()
{

}


//get functions
int inventory::get_equipped_slot()
{
	return equipped_slot;
}

int inventory::get_no_of_items()
{
	return no_of_items;
}


//item usage
void inventory::item_active_change()
{
	itemactive = !itemactive;
}

bool inventory::item_active()
{
	return itemactive;
}


//inventory change
void inventory::equipchange()
{
	//equipped_slot = items[button_pressed]
}

void inventory::item_pickup()
{
	itemtest item;
	if (no_of_items < 6) {
		items[no_of_items] = item.getFunction();
		no_of_items++;
	}
}

void inventory::item_drop()
{
	items[equipped_slot] = "none";
	no_of_items--;
}

void inventory::list_rearrange()
{
	//used for when item is dropped from inventory as items added are already sorted according to next empty slot
	if (no_of_items > 0 && equipped_slot < 5) {
		for (int i = 0; i < no_of_items; i++) {
			if (items[i] == "none") {
				items[i] = items[i + 1];
			}
		}
	}
}
