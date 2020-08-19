#include "inventory.h"

inventory::inventory(); {
	items[0] = 'torch';
	items[1] = 'none';
	items[2] = 'none';
	items[3] = 'none';
	items[4] = 'none';
	items[5] = 'none';
	equipped_slot = 0;
	no_of_items = 1
	itemactive = false;

}

inventory::~inventory(); {
	no_of_items++;
	if no_of_items >= 6 {
		// print out the statement "your inventory is too full" somewhere?
	}
}

int inventory::equipchange(); {
	equipped_slot++;
	if equipped_slot >= no_of_items{
		equipped_slot = 0;
	}
	return equipped_slot;
}

int inventory::get_no_of_items(); {
	return no_of_items;
}

void inventory::item_active(); {
	itemactive = !itemactive;
}

