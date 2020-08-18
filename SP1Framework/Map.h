#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Framework\console.h"
class Map
{
private:
	char map[42][91];
	bool mapchange;
public:
	Map();
	~Map();

	bool getMapChange();
	void inputMap(std::string anothermap);
	void DrawMap(Console& anotherC);
};

