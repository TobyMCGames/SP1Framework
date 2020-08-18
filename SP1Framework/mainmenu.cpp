#include "mainmenu.h"


mainmenu::mainmenu() :
	logo{ }
{
	
	for (int row = 0; row < 149; row++)
	{
		for (int col = 0; col < 15; col++)
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
		for (int datarow = 0; datarow < (149*2 - 1); datarow++) {
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
	for (int row = 0; row < 149; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			if (logo[row][col] == 'B')
			{
				anotherC.writeToBuffer(row, 3 + col, " ", 0x1B);
			}
			else 
			{
				anotherC.writeToBuffer(row, 3 + col, " ", 0x0F);
			}
		}
	}
}
