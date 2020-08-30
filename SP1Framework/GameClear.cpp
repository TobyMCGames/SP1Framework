#include "GameClear.h"

GameClear::GameClear():
x(180),
y(17),
GClogo{ },
option(1)
{
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			GClogo[row][col] = ' ';
		}
	}

	buttons[0] = new Button(88, 30, 0x0F, "     Retry    ");
	buttons[1] = new Button(88, 31, 0x0F, "     Exit    ");
	selector = 0;
}

GameClear::~GameClear()
{
}

int GameClear::getSelector()
{
	return selector;
}

int GameClear::GCCheckbuttons(COORD c)
{
	for (int i = 0; i < 2; i++)
	{
		if ((c.X >= buttons[i]->getX()) && (c.X <= buttons[i]->getX() + (buttons[i]->getName()).size()) && (c.Y == buttons[i]->getY()))
		{
			return i;
		}
	}
	return -1;
}

void GameClear::setselector(int select)
{
	selector = select;
}

void GameClear::increaseselector()
{
	if (selector < 1)
	{
		selector++;
	}
	else
	{
		selector = 0;
	}
}

void GameClear::decreaseselector()
{
	if (selector > 0)
	{
		selector--;
	}
	else
	{
		selector = 1;
	}
}

void GameClear::loadgameclear()
{
	std::ifstream g;
	g.open("GameClear/GameClear.csv");
	std::string data;
	int col = 0; //x
	int row = 0; //y
	while (getline(g, data))
	{
		for (int datarow = 0; datarow < (x * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				GClogo[row][col] = data[datarow];
				col++;
			}

		}
		col = 0;
		row++;
	}
	g.close();
}

void GameClear::renderGC(Console& anotherC)
{
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			if (GClogo[row][col] == 'B')
			{
				anotherC.writeToBuffer(col, row + 2, "Û", 0x9B);
			}
			else if ((GClogo[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(col, row + 2, "Û", 0x7E);
			}
			else
			{
				anotherC.writeToBuffer(col, row + 2, " ", 0x7F);
			}
		}
	}
	for (int x = 0; x < 2; x++) {
		bool onbutton = false;
		if (x == selector)
		{
			onbutton = true;
		}
		buttons[x]->renderButton(anotherC, onbutton);
	}
}
