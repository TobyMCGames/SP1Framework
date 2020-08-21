#include "mainmenu.h"


mainmenu::mainmenu() :
	x(180),
	y(17),
	logo{ },
	option(1)
{
	
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			logo[row][col] = ' ';
		}
	}
	buttons[0] = new Button(25, 24, 0x0F, "    Start  Game    ");
	buttons[1] = new Button(25, 25, 0x0F, "   How  to  play   ");
	buttons[2] = new Button(25, 26, 0x0F, "      Options      ");
	buttons[3] = new Button(25, 27, 0x0F, "      Credits      ");
	buttons[4] = new Button(25, 28, 0x0F, "    Leave  Game    ");
}

mainmenu::~mainmenu()
{
}


int mainmenu::checkButtons(COORD c)
{
	for (int i = 0; i < 5; i++)
	{
		if ((c.X >= buttons[i]->getX()) && (c.X <= (buttons[i]->getX() + (buttons[i]->getName()).size())) && (c.Y == buttons[i]->getY()))
		{
			return i;
		}
	}
	return -1;
}

void mainmenu::loadmainmenu()
{
	std::ifstream f;
	f.open("Menu/logo.csv");
	std::string data;
	int col = 0; //x
	int row = 0; //y
	while (getline(f, data)) 
	{
		for (int datarow = 0; datarow < (x * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				logo[row][col] = data[datarow];
				col++;
			}
			
		}
		col = 0;
		row++;
	}
	f.close();
}

void mainmenu::rendermenu(Console& anotherC)
{
	for (int row = 0; row < y; row++) 
	{
		for (int col = 0; col < x; col++) 
		{
			if (logo[row][col] == 'B') 
			{
				anotherC.writeToBuffer(col, row + 2 , "Û", 0x9B);
			}
			else if ((logo[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(col, row + 2, "Û",  0x7E);
			}
			else 
			{
				anotherC.writeToBuffer(col, row + 2, " ", 0x7F);
			}
		}
	}

	for (int x = 0; x < 5; x++) {
		buttons[x]->renderButton(anotherC);
	}
}



	/*COORD c = { 25, 25 };
	gotoXY(c);
	anotherC.writeToBuffer(c, "Start Game", 0x9B);*/

	/*COORD c = { 25, 28 };
	gotoXY(c);
	anotherC.writeToBuffer(c, "Options", 0x9B);*/



	/*COORD c = { 25, 31 };
	gotoXY(c);
	anotherC.writeToBuffer(c, "Leave Game", 0x9B);*/
