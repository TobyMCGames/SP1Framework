#include "Map.h"
using namespace std;

Map::Map()
{
	for (int row = 0; row < 42; row++) {
		for (int col = 0; col < 91; col++) {
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
	while (getline(f, data)) {
		for (int col = 0; col < 91; col++) {
			map[row][col] = data[col];
		}
		row++;
	}
	f.close();
	mapchange = false;
}

void Map::DrawMap(Console& anotherC)
{
	for (int row = 0; row < 42; row++) {
		for (int col = 0; col < 91; col++) {
			if (map[row][col] == 'W') {
				anotherC.writeToBuffer(40 + col, row, "²", 0xF0);
			}
			else {
				anotherC.writeToBuffer(40 + col, row, map[row][col], 0x0F);
			}
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(40 + anotherP.getX(), anotherP.getY(), (char)31, charColor);
}