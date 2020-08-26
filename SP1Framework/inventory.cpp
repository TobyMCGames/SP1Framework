#include "inventory.h"

inventory::inventory()
{
	//inventory
	items[0] = "none"; // 'none' or 'empty' will be used to denote an unused slot
	items[1] = "none";
	items[2] = "none";
	items[3] = "none";
	current_equipped = "none";
}
inventory::~inventory()
{

}


//get functions
string inventory::get_current_equipped()
{
	return current_equipped;
}
int inventory::get_equipped_slot()
{
	return equipped_slot;
}

int inventory::pick_empty_slot()
{
	return distance(items, find(items, items + 6, "none"));
}


//set functions Û
void inventory::item_add(string Item)
{
	items[pick_empty_slot()] = Item;
}
void inventory::change_equipped_slot()
{
	equipped_slot++;
	if (equipped_slot > 5) {
		equipped_slot = 0;
		change_current_equipped();
	}
}
void inventory::change_current_equipped()
{
	current_equipped = items[equipped_slot];
}
void inventory::renderInventory(Console& anotherC)
{
	anotherC.writeToBuffer(13, 11, items[0], 0x0F);
	anotherC.writeToBuffer(23, 11, items[1], 0x0F);
	anotherC.writeToBuffer(13, 15, items[2], 0x0F);
	anotherC.writeToBuffer(23, 15, items[3], 0x0F);

	anotherC.writeToBuffer(18, 25, current_equipped, 0x0F);
}
void inventory::renderEquipChange(Console& anotherC)
{

}
