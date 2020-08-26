#include "Map.h"
using namespace std;

COORD offset;

Map::Map() :
	x(135),
	y(135),
	fixed_update(0),
	map{ },
	DisasterPlane{ },
	disasters { },
	EQArray{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
			DisasterPlane[row][col] = ' ';
		}
	}
	maplevel = 0;
	mapchange = true;

	for (int i = 0; i < 500; i++) 
	{
		EQArray[i] = nullptr;
	}

	for (int i = 0; i < 50; i++)
	{
		disasters[i] = nullptr;
	}

}

Map::~Map()
{

}

bool Map::getMapChange()
{
	return mapchange;
}

string Map::getlevel()
{
	string level = to_string(maplevel);
	return level;
}

bool Map::collides(char direction, Player& anotherP)
{
	switch (direction)
	{
	case 'W':
		switch (map[anotherP.getY() - anotherP.getspeed()][anotherP.getX()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() && EQArray[i]->getY() == anotherP.getY() - anotherP.getspeed() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
		}
		break;
	case 'S':
		switch (map[anotherP.getY() + anotherP.getspeed()][anotherP.getX()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() && EQArray[i]->getY() == anotherP.getY() + anotherP.getspeed() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
		}
		break;
	case 'A':
		switch (map[anotherP.getY()][anotherP.getX() - anotherP.getspeed()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() - anotherP.getspeed() && EQArray[i]->getY() == anotherP.getY() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
		}
		break;
	case 'D':
		switch (map[anotherP.getY()][anotherP.getX() + anotherP.getspeed()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() + anotherP.getspeed() && EQArray[i]->getY() == anotherP.getY() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
		}
		break;
	}
	return false;
}

void Map::nextlevel()
{
	maplevel++;
}

void Map::loadMap(std::string anothermap, Player& player, item_general& item)
{
	string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string data;
	int EQidx = 0;
	int Didx = 0;
	int col = 0;
	int row = 0;
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (y * 2 - 1); datarow++) 
		{
			if (data[datarow] == ',') //ignore comma in csv
			{
				continue;
			}
			else if (data[datarow] == player.getIcon()) //Player Icon
			{
				player.setX(col);
				player.setY(row);
				map[row][col] = ' ';
				DisasterPlane[row][col] = ' ';
				col++;
			}
			else if (data[datarow] == 'E' && EQArray[EQidx] == nullptr)
			{
				earthquakeI = true;
				map[row][col] = data[datarow];
				DisasterPlane[row][col] = ' ';
				EQArray[EQidx] = new Earthquake;
				EQArray[EQidx]->setCOORD(col, row);
				EQidx++;
				col++;
			}
			else if (data[datarow] == item.getIcon()) //Item Icon
			{
				if (item.is_item_exist() == true) {
					item.setX(col);
					item.setY(row);
					map[row][col] = 'I';
					DisasterPlane[row][col] = ' ';
					col++;
				}
				else
				{
					map[row][col] = ' ';
					DisasterPlane[row][col] = ' ';
					col++;
				}
			}
			else if (data[datarow] == 'B')
			{
				disasters[Didx] = new Boulder(col, row, 'B');
				Didx++;
				map[row][col] = ' ';
				DisasterPlane[row][col] = 'B';
				col++;
			}
			else if (data[datarow] == 'p')
			{
				map[row][col] = ' ';
				DisasterPlane[row][col] = 'p';
				col++;
			}
			else if (data[datarow] == 'h')
			{
				map[row][col] = ' ';
				DisasterPlane[row][col] = 'h';
				col++;
			}
			else if (data[datarow] == 'T')
			{
				disasters[Didx] = new Tornado(col, row, 'T');
				Didx++;
				map[row][col] = 'T';
				col++;
			}
			else
			{
				map[row][col] = data[datarow];
				DisasterPlane[row][col] = ' ';
				col++;
			}
		}
		row++;
		col = 0;
	}
	f.close();
	mapchange = false;
}

void Map::updateMap(double dt)
{
	int idx;
	fixed_update += dt;
	if (fixed_update >= 0.16 * 1) 
	{
		for (int i = 0; i < 5; i++) //EarthQuake Tiles
		{
			idx = rand() % 500;
			while (EQArray[idx] == nullptr)
			{
				idx = rand() % 500;
			}

			if (EQArray[idx]->getState() != true)
			{
				EQArray[idx]->toggle();
				fixed_update = 0;
			}
		}

		//The rest of the disasters
	}

}

void Map::DrawMap(Console& anotherC, Player& player)
{
	if (player.getX() >= 23 && player.getX() <= 113)
	{
		offset.X = player.getX() - 23 ;
	}
	////////////////////////////////////////////////////////////////////////////////////
	else if (player.getX() < 23)
	{
		offset.X = 0;
	}                                  //For sudden position change after changing map (x - axis)
	else if (player.getX() > 113)
	{
		offset.X = 90;
	}
	///////////////////////////////////////////////////////////////////////////////////
	if (player.getY() >= 21 && player.getY() <= 114)
	{
		offset.Y = player.getY() - 21 ;
	}
	////////////////////////////////////////////////////////////////////////////////////
	else if (player.getY() < 21)
	{
		offset.Y = 0;
	}                                  //For sudden position change after changing map (y - axis)
	else if (player.getY() > 114)
	{
		offset.Y = 93;
	}
	///////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 42; i++) //y
	{
		for (int j = 0; j < 45; j++) //x
		{
			switch (map[i + offset.Y][j + offset.X])
			{
				case 'W':
					anotherC.writeToBuffer(45 + j * 2, i, "±±", 0x08);
					break;
				case ' ':
					anotherC.writeToBuffer(45 + j * 2, i, "²²", 0x8F);
					break;
				case 'I':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x6E);
					break;
				case '@':
					anotherC.writeToBuffer(45 + j * 2, i, (char)223, 0x8F);
					anotherC.writeToBuffer(46 + j * 2, i, (char)223, 0x8F);
					break;
				case 'E':
					for (int k = 0; k < 500; k++)
					{
						if (EQArray[k] != nullptr && EQArray[k]->getX() == j + offset.X && EQArray[k]->getY() == i + offset.Y)
						{
							anotherC.writeToBuffer(45 + j * 2, i, "²²", EQArray[k]->getColor());
						}
					}
					break;
				case 'S':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0xB0);
					break;
			}	
			switch (DisasterPlane[i + offset.Y][j + offset.X])
			{
			case 'B':
				anotherC.writeToBuffer(45 + j * 2, i, " ", 0x1F);
				anotherC.writeToBuffer(46 + j * 2, i, " ", 0x1F);
				break;
			case 'T':
				anotherC.writeToBuffer(45 + j * 2, i, "²²", 0x2A);
				anotherC.writeToBuffer(46 + j * 2, i, "²²", 0x2A);
			}
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(45 + 2 * (anotherP.getX() - offset.X), anotherP.getY() - offset.Y, anotherP.getmodel() , charColor);
}

bool Map::item_pickup(char facing, Player& player, item_general& item)
{
	if (player.is_Active() == true) {
		switch (facing)
		{
		case 'W':
			if ((player.getX() == item.getX()) && ((player.getY() - 1) == item.getY() - 1)) {
				item.change_exist();
				return item.is_item_exist();
				break;
			}
		case 'A':
			if (((player.getX() - 1) == item.getX()) && (player.getY() == item.getY())) {
				item.change_exist();
				return item.is_item_exist();
				break;
			}
		case 'S':
			if ((player.getX() == item.getX()) && ((player.getY() - 1) == item.getY() + 1)) {
				item.change_exist();
				return item.is_item_exist();
				break;
			}
		case 'D':
			if (((player.getX() + 1) == item.getX()) && (player.getY() == item.getY())) {
				item.change_exist();
				return item.is_item_exist();
			}
		}
	}
}

void Map::item_remove(item_general& item)
{
	map[item.getX()][item.getY()] = ' ';
}

// Disaster functions
void Map::Disasterfacing()
{
	for (int i = 0; i < 50; i++)
	{
		if (disasters[i] != nullptr)
		{
			COORD cord= disasters[i]->getcord();
			if (map[cord.Y - 1][cord.X] == 'h')
			{
				disasters[i]->changeDirection('W');
			}
			if (map[cord.Y][cord.X - 1] == 'h')
			{
				disasters[i]->changeDirection('A');
			}
			if (map[cord.Y + 1][cord.X] == 'h')
			{
				disasters[i]->changeDirection('S');
			}
			if (map[cord.Y][cord.X + 1] == 'h')
			{
				disasters[i]->changeDirection('D');
			}
		}
	}
}

void Map::Dmoves(Player& player)
{
	for (int i = 0; i < 50; i++)
	{
		if (disasters[i] != nullptr)
		{
			COORD cord = disasters[i]->getcord();
			int x = 0, y = 0;
			switch (disasters[i]->getdirection())
			{
			case 'W':
				y = -1;
				break;
			case 'A':
				x = -1;
				break;
			case 'S':
				y = 1;
				break;
			case 'D':
				x = 1;
				break;
			}
			if ((DisasterPlane[cord.Y + y][cord.X + x] != 'p') && (DisasterPlane[cord.Y + y][cord.X + x] != 'h'))
			{
				switch (disasters[i]->getdirection())
				{
				case 'W':
				case 'S':
					if ((DisasterPlane[cord.Y][cord.X + 1] == 'p') || (DisasterPlane[cord.Y][cord.X + 1] == 'h'))
					{
						disasters[i]->changeDirection('D');
						break;
					}
					else if ((DisasterPlane[cord.Y][cord.X - 1] == 'p') || (DisasterPlane[cord.Y][cord.X - 1] == 'h'))
					{
						disasters[i]->changeDirection('A');
						break;
					}
					else if (disasters[i]->getdirection() == 'W')
					{
						disasters[i]->changeDirection('S');
						break;
					}
					else
					{
						disasters[i]->changeDirection('W');
						break;
					}
				case 'A':
				case 'D':
					if ((DisasterPlane[cord.Y + 1][cord.X] == 'p') || (DisasterPlane[cord.Y + 1][cord.X] == 'h'))
					{
						disasters[i]->changeDirection('S');
						break;
					}
					else if ((DisasterPlane[cord.Y - 1][cord.X] == 'p') || (DisasterPlane[cord.Y - 1][cord.X] == 'h'))
					{
						disasters[i]->changeDirection('W');
						break;
					}
					else if (disasters[i]->getdirection() == 'A')
					{
						disasters[i]->changeDirection('D');
						break;
					}
					else
					{
						disasters[i]->changeDirection('A');
						break;
					}
				}
			}
			DisasterPlane[cord.Y][cord.X] = 'p';
			disasters[i]->move();
			cord = disasters[i]->getcord();
			disasters[i]->reaction(player, map[cord.Y][cord.X]);
			DisasterPlane[cord.Y][cord.X] = disasters[i]->geticon();
		}
	}
}