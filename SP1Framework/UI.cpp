#include "UI.h"


UI::UI() :
	disasterindicator{ },
	inventory{ }
{
	for (int row = 0; row < 38; row++)
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

void UI::renderUI(Console& anotherC, Player& anotherP, Map& map)
{
	renderlife(anotherC, anotherP);
	rendermapborder(anotherC, anotherP);
	renderdisasterindicator(anotherC, map);
	renderInventory(anotherC, anotherP);
}

void UI::renderlife(Console& anotherC, Player& anotherP)
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
			for (int i = 0; i < anotherP.getlife(); i++)
			{
				anotherC.writeToBuffer(c, "ллллл", 0x2A);
				c.X += 6;
			}
		}
		else
		{
			c.X = 6;
			c.Y = 3;
			for (int i = 0; i < anotherP.getlife(); i++)
			{
				anotherC.writeToBuffer(c, "ллллл", 0x2A);
				c.X += 6;
			}
		}
		
	}
}

void UI::rendermapborder(Console& anotherC, Player& anotherP)
{
	WORD color = 0x8F;
	if (anotherP.getlife() > 2)
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

void UI::loaddisasterindicator()
{

	std::ifstream f;
	f.open("UI/disastericons.csv");
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

void UI::renderdisasterindicator(Console& anotherC, Map& map)
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
	for (int row = 36; row < 38; row++)
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
	for (int row = 2; row < 18; row++)
	{
		for (int col = 0; col < 22; col++)
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
	for (int row = 18; row < 36; row++)
	{
		for (int col = 0; col < 22; col++)
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

	for (int row = 2; row < 18; row++)
	{
		for (int col = 22; col < 43; col++)
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
		for (int row = 18; row < 36; row++)
		{
			for (int col = 22; col < 43; col++)
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

void UI::loadInventory()
{
	int col = 0;
	int row = 0;
	//std::string path = "UI/Inventory/" + idk;
	std::ifstream f;
	f.open("UI/Inventory.csv");
	std::string line;
	std::string cell;
	while (getline(f, line))  //gets the line
	{
		std::stringstream ss(line);
		while (getline(ss, cell, ',')) //gets cell
		{
			for (unsigned int i = 0; i < cell.length(); i++)
			{
				if (i == 0)									//FIRST CHAR REPRESENTS THE OBJECT
				{
					inventory[row][col] = cell[i];
					
				}

			}
			col++;
		}
		row++;
		col = 0;
	}
	f.close();
}

void UI::renderInventory(Console& anotherC, Player& anotherP)
{

	// 18 by 9
	COORD origin,c;
	WORD select_color;
	const WORD colors[] = {
		0x0F, //Black 0
		0x8F, //Grey 1
		0xFF, //White 2
		0xAF, //Green 3
		0xCF, //Red 4

	};
	for (int i = 0; i < 4; i++)
	{
		if (anotherP.getselect() == i)
		{
			select_color = colors[3];
		}
		else
		{
			select_color = colors[1];
		}
		switch (i)
		{
		case 0:
			origin.X = 2;
			origin.Y = 12;
			break;
		case 1:
			origin.X = 22;
			origin.Y = 12;
			break;
		case 2:
			origin.X = 2;
			origin.Y = 22;
			break;
		case 3:
			origin.X = 22;
			origin.Y = 22;
		}

		c.Y = origin.Y;
		for (int y = 0; y < 9; y++)
		{
			c.X = origin.X;
			for (int x = 0; x < 18; x++)
			{	
				switch (inventory[y][x])
				{
				case 'B': //Border
					anotherC.writeToBuffer(c, " ", select_color);
					break;
				case 'P': //HP Pot Border
					if (anotherP.getInventory(i) && anotherP.getInventory(i)->GetType() == Item::ITEM_TYPE::HP)
					{
						anotherC.writeToBuffer(c, " ", colors[2]);
					}
					else
					{
						anotherC.writeToBuffer(c, " ", colors[0]);
					}
					break; 
				case 'R': //HP Liquid
					if (anotherP.getInventory(i) && anotherP.getInventory(i)->GetType() == Item::ITEM_TYPE::HP)
					{
						anotherC.writeToBuffer(c, " ", colors[4]);
					}
					else
					{
						anotherC.writeToBuffer(c, " ", colors[0]);
					}
					break;
				case 'N':
					if (anotherP.getInventory(i))
					{
						
						anotherC.writeToBuffer(c, std::to_string(anotherP.getInventory(i)->getamt()), colors[0]);
					}
					break;
				default:
					anotherC.writeToBuffer(c, " ", colors[0]);

				}
				c.X += 1;
			}
			c.Y += 1;
		}
	}
}
