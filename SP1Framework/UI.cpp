#include "UI.h"

UI::UI() :
	life(5),
	x(9),
	y(27),
	state{ }
{
	for (int row = 0; row < x; row++)
	{
		for (int col = 0; col < y; col++)
		{
			state[row][col] = ' ';
		}
	}
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

void UI::loadstate()
{
	if (life > 3)
	{
		std::ifstream f;
		f.open("");
		std::string data;
		int row = 0;
		int col = 0;
		while (getline(f, data))
		{
			for (int datarow = 0; datarow < (x * 2 - 1); datarow++) {
				if (data[datarow] == ',')
				{
					continue;
				}
				else
				{
					state[row][col] = data[datarow];
					row++;
				}

			}
			row = 0;
			col++;
		}
		f.close();
	}
	if (life < 2)
	{
		std::ifstream f;
		f.open("");
		std::string data;
		int row = 0;
		int col = 0;
		while (getline(f, data))
		{
			for (int datarow = 0; datarow < (x * 2 - 1); datarow++) {
				if (data[datarow] == ',')
				{
					continue;
				}
				else
				{
					state[row][col] = data[datarow];
					row++;
				}

			}
			row = 0;
			col++;
		}
		f.close();
	}
	else
	{
		std::ifstream f;
		f.open("");
		std::string data;
		int row = 0;
		int col = 0;
		while (getline(f, data))
		{
			for (int datarow = 0; datarow < (x * 2 - 1); datarow++) {
				if (data[datarow] == ',')
				{
					continue;
				}
				else
				{
					state[row][col] = data[datarow];
					row++;
				}

			}
			row = 0;
			col++;
		}
		f.close();
	}
}
	
	

void UI::renderstate(Console& anotherC)
{
	for (int row = 0; row < x; row++)
	{
		for (int col = 0; col < y; col++)
		{
			if (state[row][col] == 'B') //Border for us to see
			{
				anotherC.writeToBuffer(row, 4 + col, "Û", 0x9B);
			}
			else if ((state[row][col] == 'G'))
			{
				anotherC.writeToBuffer(row, 4 + col, "Û", 0x7E);
			}
			else if ((state[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(row, 4 + col, "Û", 0x7E);
			}
			else
			{
				anotherC.writeToBuffer(row, 4 + col, " ", 0x7F);
			}
		}
	}
}
