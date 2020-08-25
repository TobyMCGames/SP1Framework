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
#include "Boulder.h"
#include <sstream>
class Map
{
private:
	int x, y, maplevel;
	double fixed_update;
	char map[135][135];
	bool mapchange;
	MovingD* disasters[50];
	Earthquake* EQArray[500];

public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	string getlevel();
	bool collides(char direction, Player& anotherP);
	bool item_pickup(char facing, Player& anotherP, item_general& anotherI);
	bool earthquakeI;
	bool tornadoI;
	bool tsunamiI;
	bool volcanoI;

	//Input and draw 
	void nextlevel();
	void updateMap(double dt);
	void item_remove(item_general& item);
	void loadMap(std::string anothermap, Player& player, item_general& item);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	
};

