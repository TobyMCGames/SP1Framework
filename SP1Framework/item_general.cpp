#include "item_general.h"


item::item()
{
	no_of_items = sizeof(itemIcons);
	object[0] = new Objects(2, 2, "rock", '1');
	object[1] = new Objects(2, 2, "axe", '2');
}
item::~item()
{

}

char item::itemSetXY(char icon, int x, int y)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			object[i]->setX(x);
			object[i]->setY(y);
			return itemIcons[i];
			break;
		}
	}
}

int item::getX(char icon)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			return object[i]->getX();
			break;
		}
	}
}

int item::getY(char icon)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			return object[i]->getY();
			break;
		}
	}
}

string item::getFunction(char icon)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			return object[i]->getfunction();
			break;
		}
	}
}

bool item::is_itemIcon(char icon)
{
	char* Icon;
	Icon = std::find(itemIcons, itemIcons + no_of_items, icon);
	if (Icon != itemIcons + no_of_items) {
		return true;
	}
	else {
		return false;
	}
}

char item::what_itemIcon(char icon)
{
	char* Icon;
	Icon = std::find(itemIcons, itemIcons + no_of_items, icon);
	if (Icon != itemIcons + no_of_items) {
		return (Icon[0]);
	}
	else {
		return 'X';
	}
}

