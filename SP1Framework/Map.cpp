#include "Map.h"
using namespace std;

Map::Map():
	x(42),
	y(45),
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

void Map::inputMap(std::string anothermap)
{
	string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string data;
	int row = 0;
	int col = 0;
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
				col++;
			}

		}
		row++;
		col = 0;
	}
	f.close();
	mapchange = false;
}

void Map::DrawMap(Console& anotherC)
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			if (map[row][col] == 'W') {
				anotherC.writeToBuffer(45 + col*2, row, "  ", 0xFF);
			}
			if (map[row][col] == ' ') {
				anotherC.writeToBuffer(45 + col*2, row, "  ", 0x9F);
			}
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(45 + anotherP.getX() * 2, anotherP.getY(), "  ", charColor);
}