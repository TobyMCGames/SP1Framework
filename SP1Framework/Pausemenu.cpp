#include "Pausemenu.h"

Pausemenu::Pausemenu():
	option(0),
	selector(0),
	buttons{ }
{
	buttons[0] = new Button(180/2 - 16, 19, 0x0F, "      Resume       ");
	buttons[1] = new Button(180/2 - 16, 21, 0x0F, "    How To Play    ");
	buttons[2] = new Button(180/2 - 16, 23, 0x0F, " Exit to Main Menu ");

}

Pausemenu::~Pausemenu()
{
}

int Pausemenu::getselector()
{
	return selector;
}

void Pausemenu::setselector(int select)
{
	selector = select;
}

void Pausemenu::in_selector()
{
	if (selector < 2)
	{
		selector++;
	}
	else
	{
		selector = 0;
	}
}

void Pausemenu::de_selector()
{
	if (selector > 0)
	{
		selector--;
	}
	else
	{
		selector = 2;
	}
}

void Pausemenu::renderpause(Console& anotherC)
{
	for (int x = 0; x < 3; x++) {
		bool onbutton = false;
		if (x == selector)
		{
			onbutton = true;
		}
		buttons[x]->renderButton(anotherC, onbutton);
	}
}
