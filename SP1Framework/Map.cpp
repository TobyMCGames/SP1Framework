#include "Map.h"
using namespace std;

COORD offset;

Map::Map():
	x(135),
	y(135),
	map{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
		}
	}
	mapchange = true;
}

Map::~Map()
{

}

bool Map::getMapChange()
{
	return mapchange;
}

bool Map::collides(char direction, Player& anotherP)
{
	if (direction == 'W') {
		if (map[anotherP.getY() - 1][anotherP.getX()] == 'W') {
			return true;
		}
	}
	if (direction == 'S') {
		if (map[anotherP.getY() + 1][anotherP.getX()] == 'W') {
			return true;
		}
	}
	if (direction == 'A') {
		if (map[anotherP.getY()][anotherP.getX() - 1] == 'W') {
			return true;
		}
	}
	if (direction == 'D') {
		if (map[anotherP.getY()][anotherP.getX() + 1] == 'W') {
			return true;
		}
	}
return false;
	
}

void Map::getplayer(Player& player)
{
	map[player.getY()][player.getX()] = 'P';
}

void Map::inputMap(std::string anothermap, Player& player)
{
	string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string data;
	int col = 0;
	int row = 0;
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (y * 2 - 1); datarow++) {
			if ((data[datarow] == ','))
			{
				continue;
			}
			else
			{
				map[row][col] = data[datarow];
				if (map[row][col] == 'P')
				{
					player.setX(col);
					player.setY(row);
					map[row][col] = ' ';
				}
				col++;
			}

		}
		row++;
		col = 0;
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
	if (player.getY() >= 21 && player.getY() <= 114)
	{
		offset.Y = player.getY() - 21 ;
	}
	std::ostringstream ss1, ss2, ss3;
	ss1 << "offset.X = " << offset.X << " offset.Y = " << offset.Y;
	ss3 << "X = " << player.getX()<< " Y = " << player.getY();

	anotherC.writeToBuffer(0, 10, ss1.str());
	anotherC.writeToBuffer(0, 12, ss3.str());

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
			}		
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	//For future use --> Facing directions user art.str()
	std::ostringstream art;
	art << char(220) << char(220);

	anotherC.writeToBuffer(45 + 2 * (anotherP.getX() - offset.X), anotherP.getY() - offset.Y, "  ", charColor);
}