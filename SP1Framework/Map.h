#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include "Framework\console.h"
#include "Player.h"
#include "Objects.h"
#include "Earthquake.h"
#include "item_general.h"
#include <sstream>
class Map
{
private:
	int x, y, maplevel;
	double framebuffer;
	char map[135][135];
	bool mapchange;
	Earthquake* EQArray[50];

public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	string getlevel();
	bool collides(char direction, Player& anotherP);
	bool item_pickup(char facing, Player& anotherP, item_general& anotherI);


	//Input and draw 
	void nextlevel();
	void updateMap(double dt);
	void item_remove(item_general& item);
	void loadMap(std::string anothermap, Player& player, item_general& item);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	
};

