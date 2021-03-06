#include "UI.h"


UI::UI() :
	disasterindicator{ },
	inventory{ },
	coin{ }
{
	for (int row = 0; row < 42; row++)
	{
		for (int col = 0; col < 43; col++)
		{
			disasterindicator[row][col] = ' ';
		}
	}

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			coin[row][col] = ' ';
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
	rendercoin(anotherC, anotherP);
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
				anotherC.writeToBuffer(c, "�����", 0x2A);
				c.X += 6;
			}
		}
		else
		{
			c.X = 6;
			c.Y = 3;
			for (int i = 0; i < anotherP.getlife(); i++)
			{
				anotherC.writeToBuffer(c, "�����", 0x2A);
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

void UI::loadcoin()
{
	std::ifstream f;
	f.open("Score/coin.csv");
	std::string data;
	int row = 0;
	int col = 0;
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (6 * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				coin[row][col] = data[datarow];
				col++;
			}
		}
		col = 0;
		row++;
	}
	f.close();
}

void UI::rendercoin(Console& anotherC, Player& anotherP)
{
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 6; col++) {
			switch (coin[row][col])
			{
			case ' ':
				anotherC.writeToBuffer(4 + col, 5 + row, " ", 0x00);
				break;
			case 'Y':
				anotherC.writeToBuffer(4 + col, 5 + row, "�", 0xEE);
				break;
			case 'G':
				anotherC.writeToBuffer(4 + col, 5 + row, "�", 0x66);
				break;
			}
		}
	}
	anotherC.writeToBuffer(12, 7, "x" + std::to_string(anotherP.getCoins()), 0x07);
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
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 43; col++)
		{
			if (disasterindicator[row][col] == 'B')
			{
				anotherC.writeToBuffer(137+col, row, " ", 0x1F);
			}
			else
			{
				anotherC.writeToBuffer(137+col, row , " ", 0x7F);
			}
		}
	}
	for (int row = 38; row < 42; row++)
	{
		for (int col = 0; col < 43; col++)
		{
			if (disasterindicator[row][col] == 'B')
			{
				anotherC.writeToBuffer(137 + col, row, " ", 0x1F);
			}
			else
			{
				anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
			}
		}
	}
	for (int row = 4; row < 20; row++)
	{
		for (int col = 0; col < 22; col++)
		{
			if (map.getvolcanoI() == true)
			{
				if ((disasterindicator[row][col] == 'Y'))
				{
					anotherC.writeToBuffer(137 + col, row, "�", 0x6E);
				}
				else if ((disasterindicator[row][col] == 'R'))
				{
					anotherC.writeToBuffer(137 + col, row, "�", 0x4C);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
				}
			}
			else
			{
				if ((disasterindicator[row][col] == 'Y'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x8E);
				}
				else if ((disasterindicator[row][col] == 'R'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x8C);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
				}
			}
		}
	}
	for (int row = 20; row < 38; row++)
	{
		for (int col = 0; col < 22; col++)
		{
			if (map.gettornadoI() == true)
			{
				if ((disasterindicator[row][col] == 'G'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x0F);
				}
				else if ((disasterindicator[row][col] == 'W'))
				{
					anotherC.writeToBuffer(137 + col, row, "�", 0x7F);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
				}
			}
			else
			{
				if ((disasterindicator[row][col] == 'G'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x8F);
				}
				else if ((disasterindicator[row][col] == 'W'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x8F);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
				}
			}
		}
	}

	for (int row = 4; row < 20; row++)
	{
		for (int col = 22; col < 43; col++)
		{
			if (map.getearthquakeI() == true)
			{
				if ((disasterindicator[row][col] == 'T'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x6E);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
				}
			}
			else
			{
				if ((disasterindicator[row][col] == 'T'))
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x8F);
				}
				else
				{
					anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
				}
			}
		}
		for (int row = 20; row < 38; row++)
		{
			for (int col = 22; col < 43; col++)
			{
				if (map.gettsunamiI() == true)
				{
					if ((disasterindicator[row][col] == 'A'))
					{
						anotherC.writeToBuffer(137 + col, row, " ", 0x3B);
					}
					else if ((disasterindicator[row][col] == 'O'))
					{
						anotherC.writeToBuffer(137 + col, row, " ", 0x1E);
					}
					else
					{
						anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
					}
				}
				else
				{
					if ((disasterindicator[row][col] == 'A'))
					{
						anotherC.writeToBuffer(137 + col, row, " ", 0x8B);
					}
					else if ((disasterindicator[row][col] == 'O'))
					{
						anotherC.writeToBuffer(137 + col, row, " ", 0x8E);
					}
					else
					{
						anotherC.writeToBuffer(137 + col, row, " ", 0x7F);
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
				switch (cell[i])
				{
				case 'B':
				case ' ':
				case 'N':
					inventory[row][col] = cell[i];
					break;
				case 'P':
				case 'R':
				case 'k':
				case 'C':
					item[row][col] += cell[i];
					break;
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
	COORD origin, c;
	WORD select_color;
	const WORD colors[] = {
		0x0F, //Black 0
		0x8F, //Grey 1
		0xFF, //White 2
		0xAF, //Green 3
		0xCF, //Red 4
		0x6F //Yellow 5

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
				case 'N':
					if (anotherP.getInventory(i))
					{

						anotherC.writeToBuffer(c, std::to_string(anotherP.getInventory(i)->getamt()), colors[0]);
					}
					break;
				default:
					anotherC.writeToBuffer(c, " ", colors[0]);
				}

				for (int j = 0; j < item[y][x].length(); j++)
				{
					switch (item[y][x][j])
					{
					case 'P': //HP Pot Border
						if (anotherP.getInventory(i) && anotherP.getInventory(i)->GetType() == Item::ITEM_TYPE::HP)
						{
							anotherC.writeToBuffer(c, " ", colors[2]);
						}
						break;
					case 'R': //HP Liquid
						if (anotherP.getInventory(i) && anotherP.getInventory(i)->GetType() == Item::ITEM_TYPE::HP)
						{
							anotherC.writeToBuffer(c, " ", colors[4]);
						}
						break;
					case 'k': //KEY
						if (anotherP.getInventory(i) && anotherP.getInventory(i)->GetType() == Item::ITEM_TYPE::KEY)
						{
							anotherC.writeToBuffer(c, " ", colors[5]);
						}
						break;
					case 'C': //KEYCARD
						if (anotherP.getInventory(i) && anotherP.getInventory(i)->GetType() == Item::ITEM_TYPE::KEYCARD)
						{
							anotherC.writeToBuffer(c, " ", colors[2]);
						}
						break;
					}
				}
				c.X += 1;
			}
			c.Y += 1;
		}

		/*c.X = origin.X;
		c.Y = origin.Y;
		if(anotherP.getInventory(i))
		{ 
			anotherC.writeToBuffer(c, anotherP.getInventory(i)->getname(), 0x0F);
		}
		else
		{
			anotherC.writeToBuffer(c, "Nothing", 0x0F);
		}*/
	}

	anotherC.writeToBuffer(12 , 33, "<Tab> to change slot" , colors[0]);
}
