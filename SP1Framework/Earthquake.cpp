#include "Earthquake.h"

Earthquake::Earthquake()
{
	setIcon('E');
	setColor(0x9F);
}

Earthquake::~Earthquake()
{
}

void Earthquake::toggle()
{
	if (getState() == true)
	{
		setActive(false);
		setColor(0x9F);
	}
	else
	{
		setActive(true);
		setColor(0x00);
	}
}


