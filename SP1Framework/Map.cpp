#include "Map.h"
using namespace std;

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
	std::ostringstream ss1, ss2, ss3, ss4;
	ss1 << "screen.X = " << player.getscreenX() << " screen.Y = " << player.getscreenY();
	ss2 << "map.X = " << player.getmapX() << " map.Y = " << player.getmapY();
	ss3 << "X = " << player.getX()<< " Y = " << player.getY();

	anotherC.writeToBuffer(0 , 10, ss1.str());
	anotherC.writeToBuffer(0,  11, ss2.str());
	anotherC.writeToBuffer(0, 12, ss3.str());

	for (int row = 0; row < 42; row++) {
		for (int col = 0; col < 45; col++) {
			if (player.getmapX() >= 0 && player.getmapY() >= 0)
			{
				if (map[row + player.getmapY()][col + player.getmapX()] == 'W')
				{ 

					anotherC.writeToBuffer(45 + col * 2, row, "  ", 0xFF);
				}
				if (map[row + player.getmapY()][col + player.getmapX()] == ' ')
				{
					if (player.getmapX() >= 0)
					{
						anotherC.writeToBuffer(45 + col * 2, row, "  ", 0x9F);
					}
				}
			}
			else
			{
				if (map[row][col] == 'W')
				{

					anotherC.writeToBuffer(45 + col * 2, row, "  ", 0xFF);
				}
				if (map[row][col] == ' ')
				{
					if (player.getmapX() >= 0 && player.getmapY() >= 0)
					{
						anotherC.writeToBuffer(45 + col * 2, row, "  ", 0x9F);
					}
				}
			}
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(45 + anotherP.getscreenX() * 2, anotherP.getscreenY(), "  ", charColor);
}