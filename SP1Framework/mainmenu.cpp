#include "mainmenu.h"


mainmenu::mainmenu() :
	x(180),
	y(17),
	logo{ },
	option(1)
{
	
	for (int row = 0; row < x; row++)
	{
		for (int col = 0; col < y; col++)
		{
			logo[row][col] = ' ';
		}
	}
}

mainmenu::~mainmenu()
{
}

void mainmenu::loadmainmenu()
{
	std::ifstream f;
	f.open("Menu/logo.csv");
	std::string data;
	int row = 0;
	int col = 0;
	while (getline(f, data)) 
	{
		for (int datarow = 0; datarow < (x*2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				logo[row][col] = data[datarow];
				row++;
			}
			
		}
		row = 0;
		col++;
	}
	f.close();
}

void mainmenu::rendermenu(Console& anotherC)
{
	for (int row = 0; row < x; row++)
	{
		for (int col = 0; col < y; col++)
		{
			if (logo[row][col] == 'B') //Border for us to see
			{
				anotherC.writeToBuffer(row, 4 + col, "Û", 0x9B);
			}
			else if ((logo[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(row, 4 + col, "Û",  0x7E);
			}
			else 
			{
				anotherC.writeToBuffer(row, 4 + col, " ", 0x7F);
			}
		}
	}
}
