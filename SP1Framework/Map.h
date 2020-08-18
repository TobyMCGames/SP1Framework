#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Framework\console.h"
class Map
{
private:
	char map[42][91];
public:
	Map();
	~Map();

	void inputMap(std::string anothermap);
	void DrawMap(Console& anotherC);
};

