#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Framework\console.h"
#include "Player.h"
#include "Objects.h"
#include "itemtest.h"

#include <sstream>
class Map
{
private:
	int x, y;
	char map[135][135];
	int maplevel;
	bool mapchange;

public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	string getlevel();
	bool collides(char direction, Player& anotherP);


	//Input and draw 
	void nextlevel();
	void loadMap(std::string anothermap, Player& player);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	void DrawItem(Console& anotherC, itemtest& anotherI, WORD itemColor);
	
};

