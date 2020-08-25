#include "Map.h"
using namespace std;

COORD offset;

Map::Map() :
	x(135),
	y(135),
	fixed_update(0),
	map{ },
	disasters { },
	EQArray{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
		}
	}
	maplevel = 0;
	mapchange = true;

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
	int idx = 0;
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
				col++;
			}
			else if (data[datarow] == 'E' && EQArray[idx] == nullptr)
			{
				map[row][col] = data[datarow];
				EQArray[idx] = new Earthquake;
				EQArray[idx]->setCOORD(col, row);
				col++;
			}
			else if (data[datarow] == item.getIcon()) //Item Icon
			{
				if (item.is_item_exist() == true) {
					item.setX(col);
					item.setY(row);
					map[row][col] = 'I';
					col++;
				}
				else
				{
					map[row][col] = ' ';
					col++;
				}
			}
			else if (data[datarow] == 'B')
			{
				disasters[idx] = new Boulder(col, row);
			}
			else
			{
				map[row][col] = data[datarow];
				col++;
			}
		}
		idx++;
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
