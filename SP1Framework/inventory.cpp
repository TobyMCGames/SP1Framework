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

	buttons[0] = new Button(10, 12, 0x0F, "   " + items[0] + "   " + "\n    Swap    ");
	buttons[1] = new Button(20, 12, 0x0F, "   " + items[1] + "   " + "\n    Swap    ");
	buttons[2] = new Button(10, 16, 0x0F, "   " + items[2] + "   " + "\n    Swap    ");
	buttons[3] = new Button(20, 16, 0x0F, "   " + items[3] + "   " + "\n    Swap    ");
	buttons[4] = new Button(10, 20, 0x0F, "   " + items[4] + "   " + "\n    Swap    ");
	buttons[5] = new Button(20, 20, 0x0F, "   " + items[5] + "   " + "\n    Swap    ");
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

void inventory::which_button_pressed(Console& anotherC)
{
	for (int x = 0; x < 6; x++) {
		bool onbutton = false;
		buttons[x]->renderButton(anotherC, onbutton);
	}
}
