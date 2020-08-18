#include "Map.h"
using namespace std;

Map::Map()
{
	for (int row = 0; row < 42; row++) {
		for (int col = 0; col < 91; col++) {
			map[row][col] = ' ';
		}
	}
}

Map::~Map()
{

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