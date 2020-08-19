#include "UI.h"

UI::UI() :
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

void UI::loadstate()
{
	if (User.getlife() > 3)
	{
		std::ifstream f;
		f.open("status(G).csv");
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
	if (User.getlife() < 2)
	{
		std::ifstream f;
		f.open("status(R).csv");
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
		f.open("status(Y).csv");
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
				anotherC.writeToBuffer(row, 4 + col, "л", 0x9B);
			}
			else if ((state[row][col] == 'G'))
			{
				anotherC.writeToBuffer(row, 4 + col, "л", 0x2A);
			}
			else if ((state[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(row, 4 + col, "л", 0x7E);
			}
			else if ((state[row][col] == 'R'))
			{
				anotherC.writeToBuffer(row, 4 + col, "л", 0x4C);
			}
			else
			{
				anotherC.writeToBuffer(row, 4 + col, " ", 0x7F);
			}
		}
	}
}

void UI::loaddindicater()
{
	//Grid 
	std::ifstream f;
	f.open("gridicon.csv");
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
				dindicater[row][col] = data[datarow];
				row++;
			}

		}
		row = 0;
		col++;
	}
	f.close();

	//Volcano icon
	std::ifstream f;
	f.open("volcanoicon.csv");
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
				dindicater[row][col] = data[datarow];
				row++;
			}

		}
		row = 0;
		col++;
	}
	f.close();

	//Earthquake icon
	std::ifstream f;
	f.open("earthquakeicon.csv");
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
				dindicater[row][col] = data[datarow];
				row++;
			}

		}
		row = 0;
		col++;
	}
	f.close();

	//Tsunami icon
	std::ifstream f;
	f.open("tsunamiicon.csv");
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
				dindicater[row][col] = data[datarow];
				row++;
			}

		}
		row = 0;
		col++;
	}
	f.close();

	//Tornado icon
	std::ifstream f;
	f.open("tornadoicon.csv");
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
				dindicater[row][col] = data[datarow];
				row++;
			}

		}
		row = 0;
		col++;
	}
	f.close();
}

void UI::renderdindicater(Console& anotherC)
{
}
