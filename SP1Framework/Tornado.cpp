#include "Tornado.h"

Tornado::Tornado()
{
	setIcon('T');
	setColor(0x8F);
}

Tornado::~Tornado()
{

}

void Tornado::reaction()
{

}

void Tornado::spawnT()
{
	if (getState() == true)
	{
		setActive(false);
		setColor(0x8F);
	}
	else
	{
		setActive(true);
		setColor(0x00);
	}
}
