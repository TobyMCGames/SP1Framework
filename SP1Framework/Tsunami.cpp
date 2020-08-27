#include "Tsunami.h"

Tsunami::Tsunami()
{
	setIcon('M');
	setColor(0x8F);
}

Tsunami::~Tsunami()
{
}

void Tsunami::toggle()
{
	if (getState() == true)
	{
		setActive(false);
		setColor(0x8F);
	}
	else
	{
		setActive(true);
		setColor(0x19);
	}
}
