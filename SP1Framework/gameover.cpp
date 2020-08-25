#include "gameover.h"

gameover::gameover() :
	x(180),
	y(17),
	GOlogo{ },
	option(1)
{
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			GOlogo[row][col] = ' ';
		}
	}

	buttons[0] = new Button(88, 30, 0x0F, "    Retry    ");

	selector = 0;
}

gameover::~gameover()
{
}

int gameover::getSelector()
{
	return selector;
}

void gameover::WSmenu(int updown)
{
	int buffer = selector + (updown);
	if (buffer >= 0 && buffer <= 1) {
		selector = buffer;
	}
}

void gameover::loadgameover()
{
	std::ifstream g;
	g.open("GameOver/GameOver.csv");
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
				GOlogo[row][col] = data[datarow];
				col++;
			}

		}
		col = 0;
		row++;
	}
	g.close();
}

void gameover::renderGO(Console& anotherC)
{
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			if (GOlogo[row][col] == 'B')
			{
				anotherC.writeToBuffer(col, row + 2, "�", 0x9B);
			}
			else if ((GOlogo[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(col, row + 2, "�", 0x7E);
			}
			else
			{
				anotherC.writeToBuffer(col, row + 2, " ", 0x7F);
			}
		}
	}
	for (int x = 0; x < 1; x++) {
		bool onbutton = false;
		if (x == selector)
		{
			onbutton = true;
		}
		buttons[x]->renderButton(anotherC, onbutton);
	}
}
