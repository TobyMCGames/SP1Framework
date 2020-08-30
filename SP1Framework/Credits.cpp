#include "Credits.h"

Credits::Credits() :
	buttons{ },
	selector(0)
{
	buttons[0] = new Button(3, 39, 0x0F, "Enter/Space to Return to Menu");
}

Credits::~Credits()
{
}

int Credits::getselector()
{
	return selector;
}

void Credits::setselector(int select)
{
	selector = select;
}

void Credits::renderCredits(Console& anotherC)
{
	anotherC.writeToBuffer(57, 10, "                          TEAM 13                          ", 0x0F);
	anotherC.writeToBuffer(57, 12, "                   CLASS : GD  2003/2004                   ", 0x0F);
	anotherC.writeToBuffer(57, 14, "                      Team Supervisor                      ", 0x0F);
	anotherC.writeToBuffer(57, 16, "                          Mr Tang                          ", 0x0F);
	anotherC.writeToBuffer(57, 18, "                        Team Leader                        ", 0x0F);
	anotherC.writeToBuffer(57, 20, "                       Toby Chua (04)                      ", 0x0F);
	anotherC.writeToBuffer(57, 22, "                          Members                          ", 0x0F);
	anotherC.writeToBuffer(57, 24, "                       Jeryl Lah (04)                      ", 0x0F);
	anotherC.writeToBuffer(57, 26, "                      Justin Toh  (03)                     ", 0x0F);
	anotherC.writeToBuffer(57, 28, "                      Amir Rahimi (04)                     ", 0x0F);
	anotherC.writeToBuffer(57, 30, "                       Ryann Tan (03)                      ", 0x0F);
	buttons[0]->renderButton(anotherC, false);
}
