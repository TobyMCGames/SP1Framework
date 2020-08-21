#include "UI.h"

UI::UI() :
	state{ },
	dgrid{ }
{
	for (int row = 0; row < 33; row++)
	{
		for (int col = 0; col < 33; col++)
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
	c.X = 2;
	c.Y = 2;
	anotherC.writeToBuffer(c, "HP: ", 0x0F);
	for (int j = 0; j < 2; j++)
	{
		if (j != 1)
		{
			c.X = 6;
			for (int i = 0; i < User.getlife(); i++)
			{
				anotherC.writeToBuffer(c, "ллллл", 0x2A);
				c.X += 6;
			}
		}
		else
		{
			c.X = 6;
			c.Y = 3;
			for (int i = 0; i < User.getlife(); i++)
			{
				anotherC.writeToBuffer(c, "ллллл", 0x2A);
				c.X += 6;
			}
		}
		
	}
}

void UI::rendermapborder(Console& anotherC)
{
	for (int i = 0; i < 42; i++)
	{
		anotherC.writeToBuffer( 43, i, "  ", 0x8F);
		anotherC.writeToBuffer( 135, i, "  ", 0x8F);
	}
}

void UI::loadstate()
{
	
	std::ifstream f;
	f.open("UI/Stat(G).csv");
	std::string data;
	int row = 0;
	int col = 0;
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (33 * 2 - 1); datarow++) {
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
	
	

void UI::renderstate(Console& anotherC)
{
	for (int row = 0; row < 33; row++)
	{
		for (int col = 0; col < 33; col++)
		{
			if (User.getlife() >=4) 
			{
				if ((state[row][col] == 'G'))
				{
					anotherC.writeToBuffer(141 + row, col, "л", 0x2A);
				}
				else if ((state[row][col] == 'I'))
				{
					anotherC.writeToBuffer(141 + row, col, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(141 + row, col, " ", 0x0A);
				}
			}
			else if (User.getlife() >=2)
			{
				if ((state[row][col] == 'G'))
				{
					anotherC.writeToBuffer(141 + row, col, "л", 0x6E);
				}
				else if ((state[row][col] == 'I'))
				{
					anotherC.writeToBuffer(141 + row, col, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(141 + row, col, " ", 0x0A);
				}
			}
			else
			{
				if ((state[row][col] == 'G'))
				{
					anotherC.writeToBuffer(141 + row, col, "л", 0x4C);
				}
				else if ((state[row][col] == 'I'))
				{
					anotherC.writeToBuffer(141 + row, col, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(141 + row, col, " ", 0x0A);
				}
			}
		}
	}
}

void UI::loadgrid()
{
}

void UI::rendergrid(Console& anotherC)
{
}

