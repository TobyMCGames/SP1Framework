#include "Virus.h"

Virus::Virus()
{
	setIcon('V');
	setColour(0x8F);
	x = 0;
	y = 0;
	limit = 10;
}

Virus::~Virus()
{
}

int Virus::getlimit (int limit)
{
	return limit;
}

void Virus::toggle()
{
	if (getState() == true)
	{
		setActive(false);
		setColour(0x8F);
	}
	else
	{
		setActive(true);
		setColour(0x5D);
	}
}


