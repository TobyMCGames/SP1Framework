#include "Keycard.h"

Keycard::Keycard() : Item(ITEM_TYPE::KEYCARD)

{
	setname("Card");
	setsymbol('C');
}

Keycard::~Keycard()
{
}
