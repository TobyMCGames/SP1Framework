#include "inventory.h"

inventory::inventory()
{
	//inventory
	items[0] = "rock"; // 'none' or 'empty' will be used to denote an unused slot
	items[1] = "none";
	items[2] = "none";
	items[3] = "none";
	items[4] = "none";
	items[5] = "none";
	current_equipped = "none";

	//buttons
	buttons[0] = new Button(10, 12, 0x0F, "   Swap   ");
	buttons[1] = new Button(20, 12, 0x0F, "   Swap   ");
	buttons[2] = new Button(10, 16, 0x0F, "   Swap   ");
	buttons[3] = new Button(20, 16, 0x0F, "   Swap   ");
	buttons[4] = new Button(10, 20, 0x0F, "   Swap   ");
	buttons[5] = new Button(20, 20, 0x0F, "   Swap   ");
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


//set functions Û
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
	anotherC.writeToBuffer(10, 11, items[0], 0x0F);
	anotherC.writeToBuffer(20, 11, items[1], 0x0F);
	anotherC.writeToBuffer(10, 15, items[2], 0x0F);
	anotherC.writeToBuffer(20, 15, items[3], 0x0F);
	anotherC.writeToBuffer(10, 19, items[4], 0x0F);
	anotherC.writeToBuffer(20, 19, items[5], 0x0F);

	anotherC.writeToBuffer(15, 25, current_equipped, 0x0F);
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





