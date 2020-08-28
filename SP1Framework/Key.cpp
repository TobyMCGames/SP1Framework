#include "Key.h"

Key::Key() : Item(ITEM_TYPE::KEY)
{
	setname("Key");
	setsymbol('k');
}

Key::~Key()
{
}
