#include "Item.h"


Item::Item()
{
	no_of_items = sizeof(itemIcons);
	object[0] = new Objects(2, 2, "rock", '1');
	object[1] = new Objects(2, 2, "axe", '2');
}
Item::~Item()
{

}

char Item::itemSetXY(char icon, int x, int y)
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

int Item::getX(char icon)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			return object[i]->getX();
			break;
		}
	}
}

int Item::getY(char icon)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			return object[i]->getY();
			break;
		}
	}
}

string Item::getFunction(char icon)
{
	for (int i = 0; i < no_of_items; i++) {
		if (icon == itemIcons[i]) {
			return object[i]->getfunction();
			break;
		}
	}
}

bool Item::is_itemIcon(char icon)
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

char Item::what_itemIcon(char icon)
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

