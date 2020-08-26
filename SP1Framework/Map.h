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
#include "Tornado.h"
#include "Volcano.h"
#include <sstream>
class Map
{
private:
	int x, y, maplevel;
	double fixed_update;
	char map[135][135];
	char DisasterPlane[135][135];
	bool mapchange;
	MovingD* disasters[50];
	Earthquake* EQArray[500];
	Volcano* VArray[500];

public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	string getlevel();
	bool collides(char direction, Player& anotherP);
	char facing_icon(char facing, Player& player, item& Item);
	bool earthquakeI;
	bool tornadoI;
	bool tsunamiI;
	bool volcanoI;

	//Disaster movements
	void Disasterfacing();
	void Dmoves(Player& player);

	//Input and draw 
	void nextlevel();
	void updateMap(double dt);
	void item_remove(char facing, Player& player, item& Item, inventory& Inventory);
	void loadMap(std::string anothermap, Player& player, item& Item);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	
};

