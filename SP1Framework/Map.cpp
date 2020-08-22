#include "Map.h"
using namespace std;

COORD offset;

Map::Map() :
	x(135),
	y(135),
	map{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
		}
	}
	maplevel = 0;
	mapchange = true;
	stairs[0] = nullptr;
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
		if (map[anotherP.getY() - anotherP.getspeed()][anotherP.getX()] == 'W') {
			return true;
		}
		break;
	case 'S':
		if (map[anotherP.getY() + anotherP.getspeed()][anotherP.getX()] == 'W') {
			return true;
		}
		break;
	case 'A':
		if (map[anotherP.getY()][anotherP.getX() - anotherP.getspeed()] == 'W') {
			return true;
		}
		break;
	case 'D':
		if (map[anotherP.getY()][anotherP.getX() + anotherP.getspeed()] == 'W') {
			return true;
		}
		break;
	}
	return false;
}

void Map::changeMap(Player& player)
{
	if ((player.getX() >= stairs[0]->getX()) &&
		(player.getX() <= stairs[0]->getX() + 3) &&
		(player.getY() >= stairs[0]->getY()) &&
		(player.getY() <= stairs[0]->getY() + 3))
	{
		mapchange = true;
	}
}

void Map::nextlevel()
{
	maplevel++;
}

void Map::loadMap(std::string anothermap, Player& player)
{
	string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string data;
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
			else if (data[datarow] == '@') //Stairs
			{
				stairs[0] = new Objects(col, row, "next", '@');
				map[row][col] = data[datarow];
				col++;
			}
			else
			{
				map[row][col] = data[datarow];
				col++;
			}
		}
		row++;
		col = 0;
	}
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			map[stairs[0]->getY() + i][stairs[0]->getX() + j] = '@';
		}
	}
	f.close();
	mapchange = false;
}

void Map::DrawMap(Console& anotherC, Player& player)
{
	//45,42
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
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0xFF);
					break;
				case ' ':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x9F);
					break;
				case '@':
					anotherC.writeToBuffer(45 + j * 2, i, (char)223, 0x8F);
					anotherC.writeToBuffer(46 + j * 2, i, (char)223, 0x8F);
					break;
				case 'E':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x00);
			}		
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(45 + 2 * (anotherP.getX() - offset.X), anotherP.getY() - offset.Y, anotherP.getmodel() , charColor);
}

void Map::DrawItem(Console& anotherC, itemtest& anotherI, WORD itemColor)
{
	anotherC.writeToBuffer(45 + 2 * (anotherI.getX() - offset.X), anotherI.getY() - offset.Y, anotherI.getModel(), itemColor);
}