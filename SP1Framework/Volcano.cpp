#include "Volcano.h"

Volcano::Volcano()
{
	setIcon('F');
	setColor(0x8F);
}

Volcano::~Volcano()
{
}

void Volcano::toggle()
{
	if (getState() == true)
	{
		setActive(false);
		setColor(0x8F);
	}
	else
	{
		setActive(true);
		setColor(0x4C);
	}
}
