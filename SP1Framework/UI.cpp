#include "UI.h"

UI::UI() :
	life(5)
{
}

UI::~UI()
{
}

void UI::renderlife(Console& anotherC)
{
	COORD c;
	std::stringstream ss;
	ss << "Life : " << life;
	c.X = 0;
	c.Y = 0;
	anotherC.writeToBuffer(c, ss.str());
}
