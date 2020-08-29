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
#include "Doors.h"

class Map
{
private:
	int x, y, x_change, y_change, maplevel, xaxis, yaxis;
	double EQtime, Vtime;
	char DisasterPlane[135][135];
	bool mapchange;
	bool earthquakeI, tornadoI, tsunamiI, volcanoI;
	MovingD* disasters[50];
	Earthquake* EQArray[500];
	Volcano* VArray[500];
	Doors* DoorArray[500];

public:
	Map();
	~Map();
	char map[135][135];

	//get functions
	bool getMapChange();
	std::string getlevel();
	bool collides(char direction, Player& anotherP);
	char getPlayerfront(Player& player);
	bool getearthquakeI();
	bool gettornadoI();
	bool gettsunamiI();
	int getxaxis();
	int getyaxis();
	bool getvolcanoI();

	//Disaster movements
	void Dmoves(Player& player);

	//Inventory Stuff
	void interact(Player& player);
	void unlockDoor(Player& player, int doortype);
	int frontDoortype(Player& player);
	bool frontDoorState(Player& player);

	//Input and draw 
	void nextlevel();
	void updateMap(double dt);
	void setMap(int x);
	void loadMap(std::string anothermap, Player& player);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	void spreadcheck();
};

