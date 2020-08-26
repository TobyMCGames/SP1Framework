#include "inventory.h"

inventory::inventory()
{
	//inventory
	items[0] = "none"; // 'none' or 'empty' will be used to denote an unused slot
	items[1] = "none";
	items[2] = "none";
	items[3] = "none";
	current_equipped = "none";

	//buttons
	buttons[0] = new Button(13, 12, 0x0F, "   Swap   ");
	buttons[1] = new Button(23, 12, 0x0F, "   Swap   ");
	buttons[2] = new Button(13, 16, 0x0F, "   Swap   ");
	buttons[3] = new Button(23, 16, 0x0F, "   Swap   ");
	equipped_slot = 0;
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
int inventory::checkButtons(COORD c)
{
	for (int i = 0; i < 6; i++)
	{
		if ((c.X >= buttons[i]->getX()) && (c.X <= buttons[i]->getX() + (buttons[i]->getName()).size()) && (c.Y == buttons[i]->getY()))
		{
			return i;
		}
	}
	return -1;
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
	for (int x = 0; x < 5; x++) {
		bool onbutton = false;
		if (x == equipped_slot)
		{
			onbutton = true;
		}
		buttons[x]->renderButton(anotherC, onbutton);
	}
}
