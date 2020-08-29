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
	bool getMapChange();      // AllowChange map
	std::string getlevel();   // Get level number
	bool collides(char direction, Player& anotherP);  // Check for collision
	char getPlayerfront(Player& player);  // Get tile infront of player
	bool getearthquakeI(); //Check for Earth Disaster
	bool gettornadoI();    //Check for Wind Disaster
	bool gettsunamiI();    //Check for water Disaster
	bool getvolcanoI();    //Check for Fire Disaster

	//Disaster movements
	void Dmoves(Player& player);  // How Disaster moves

	//Inventory Stuff
	void interact(Player& player);  // Interact actions
	void unlockDoor(Player& player, int doortype);  //Unlocks interacted door
	int frontDoortype(Player& player);  // Check type of door infront of player
	bool frontDoorState(Player& player);// Check if Door is Active

	//Input and draw 
	void nextlevel();
	void updateMap(double dt);
	void setMap(int x);
	void loadMap(std::string anothermap, Player& player);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	void spreadcheck();
};

