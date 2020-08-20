#include "SplashScreen.h"

SplashScreen::SplashScreen() :
	screen{ }
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::loadSplashScreen()
{
	std::ifstream f;
	f.open("Menu/SplashScreen.csv");
	std::string data;
	int col = 0; //x
	int row = 0; //y
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (180 * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				screen[row][col] = data[datarow];
				col++;
			}

		}
		col = 0;
		row++;
	}
	f.close();
}

void SplashScreen::renderSplashScreen(Console& anotherC)
{
	for (int row = 0; row < 42; row++)
	{
		for (int col = 0; col < 180; col++)
		{
			switch (screen[row][col])
			{
			case'B':
				anotherC.writeToBuffer(col, row, " ", 0x1F);
				break;
			case'1':
				anotherC.writeToBuffer(col, row, "°", 0x18);
				break;
			case'2':
				anotherC.writeToBuffer(col, row, "²", 0x18);
				break;
			default:
				anotherC.writeToBuffer(col, row, " ", 0x88);
				break;
			}
		}
	}
}
