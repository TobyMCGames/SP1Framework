#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <sstream>
#include "Framework\console.h"
#include "Player.h"
#include "Earthquake.h"
#include "Boulder.h"
#include "Tornado.h"
#include "Volcano.h"

class Map
{
private:
	int x, y, maplevel;
	double fixed_update;
	char map[135][135];
	char DisasterPlane[135][135];
	bool mapchange;
	bool earthquakeI, tornadoI, tsunamiI, volcanoI;
	MovingD* disasters[50];
	Earthquake* EQArray[500];
	Volcano* VArray[500];

public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	std::string getlevel();
	bool collides(char direction, Player& anotherP);
	bool getearthquakeI();
	bool gettornadoI();
	bool gettsunamiI();
	bool getvolcanoI();

	//Disaster movements
	void Disasterfacing();
	void Dmoves(Player& player);

	//Input and draw 
	void nextlevel();
	void updateMap(double dt);
	void interact(Player& player);
	void loadMap(std::string anothermap, Player& player);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	
};

