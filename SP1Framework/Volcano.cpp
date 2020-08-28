#include "Volcano.h"

Volcano::Volcano()
{
	setIcon('F');
	setColor(0x8F);
}

Volcano::~Volcano()
{
}

Volcano::Volcano(int x, int y)
{
	setIcon('F');
	setColor(0x44);
	setCOORD(x, y);
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
		setColor(0x44);
	}

}