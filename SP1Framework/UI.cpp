#include "UI.h"


UI::UI() :
	state{ },
	disasterindicator{ }
{
	for (int row = 0; row < 29; row++)
	{
		for (int col = 0; col < 36; col++)
		{
			state[row][col] = ' ';
		}
	}
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 43; col++)
		{
			disasterindicator[row][col] = ' ';
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
	WORD color = 0x8F;
	if (User.getlife() > 2)
	{
		color = 0xAF;
	}
	else
	{
		color = 0xCF;
	}

	for (int i = 0; i < 42; i++)
	{
		anotherC.writeToBuffer( 43, i, "  ", color);
		anotherC.writeToBuffer( 135, i, "  ", color);
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
		for (int datarow = 0; datarow < (36 * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				state[row][col] = data[datarow];
				col++;
			}

		}
		col = 0;
		row++;
	}
	f.close();
	
}
	
	

void UI::renderstate(Console& anotherC)
{
	for (int row = 0; row < 29; row++)
	{
		for (int col = 0; col < 36; col++)
		{
			if (User.getlife() >=4) 
			{
				if ((state[row][col] == 'G'))
				{
					anotherC.writeToBuffer(140 + col, 13 + row, "л", 0x2A);
				}
				else if ((state[row][col] == 'I'))
				{
					anotherC.writeToBuffer(140 + col, 13 + row, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(140 + col, 13 + row, " ", 0x0A);
				}
			}
			else if (User.getlife() >=2)
			{
				if ((state[row][col] == 'G'))
				{
					anotherC.writeToBuffer(140 + col, 13 + row, "л", 0x6E);
				}
				else if ((state[row][col] == 'I'))
				{
					anotherC.writeToBuffer(140 + col, 13 + row, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(140 + col, 13 + row, " ", 0x0A);
				}
			}
			else
			{
				if ((state[row][col] == 'G'))
				{
					anotherC.writeToBuffer(140 + col, 13 + row, "л", 0x4C);
				}
				else if ((state[row][col] == 'I'))
				{
					anotherC.writeToBuffer(140 + col, 13 + row, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(140 + col, 13 + row, " ", 0x0A);
				}
			}
		}
	}
}

void UI::loaddisasterindicator()
{

	std::ifstream f;
	f.open("UI/disasterindicator.csv");
	std::string data;
	int row = 0;
	int col = 0;
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (43 * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				disasterindicator[row][col] = data[datarow];
				col++;
			}

		}
		col = 0;
		row++;
	}
	f.close();

}

void UI::renderdisasterindicator(Console& anotherC)
{
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 43; col++)
		{
			if (disasterindicator[row][col] == 'B')
			{
				anotherC.writeToBuffer(137+col, 2+row, " ", 0x1F);
			}
			else
			{
				anotherC.writeToBuffer(137+col, 2+row , " ", 0x7F);
			}
		}
	}
	for (int row = 10; row < 12; row++)
	{
		for (int col = 0; col < 43; col++)
		{
			if (disasterindicator[row][col] == 'B')
			{
				anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x1F);
			}
			else
			{
				anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
			}
		}
	}
	for (int row = 2; row < 10; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			if (map.getvolcanoI() == true)
			{
				if ((disasterindicator[row][col] == 'Y'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, "л", 0x6E);
				}
				else if ((disasterindicator[row][col] == 'R'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, "л", 0x4C);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
				}
			}
			else
			{
				if ((disasterindicator[row][col] == 'Y'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8E);
				}
				else if ((disasterindicator[row][col] == 'R'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8C);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
				}
			}
		}
	}
	for (int row = 2; row < 10; row++)
	{
		for (int col = 11; col < 22; col++)
		{
			if (map.gettornadoI() == true)
			{
				if ((disasterindicator[row][col] == 'G'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x0F);
				}
				else if ((disasterindicator[row][col] == 'W'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, "л", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
				}
			}
			else
			{
				if ((disasterindicator[row][col] == 'G'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8F);
				}
				else if ((disasterindicator[row][col] == 'W'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8F);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
				}
			}
		}
	}
	for (int row = 2; row < 10; row++)
	{
		for (int col = 22; col < 33; col++)
		{
			if (map.getearthquakeI() == true)
			{
				if ((disasterindicator[row][col] == 'T'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x6E);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
				}
			}
			else
			{
				if ((disasterindicator[row][col] == 'T'))
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8F);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
				}
			}
		}
		for (int row = 2; row < 10; row++)
		{
			for (int col = 33; col < 43; col++)
			{
				if (map.gettsunamiI() == true)
				{
					if ((disasterindicator[row][col] == 'A'))
					{
						anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x3B);
					}
					else if ((disasterindicator[row][col] == 'O'))
					{
						anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x1E);
					}
					else
					{
						anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
					}
				}
				else
				{
					if ((disasterindicator[row][col] == 'A'))
					{
						anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8B);
					}
					else if ((disasterindicator[row][col] == 'O'))
					{
						anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x8E);
					}
					else
					{
						anotherC.writeToBuffer(137 + col, 2 + row, " ", 0x7F);
					}
				}
			}
		}
	}
}