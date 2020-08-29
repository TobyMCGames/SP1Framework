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
	int x, y, x_change, y_change, maplevel;
	double fixed_update;
	char map[135][135];
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
	void nextlevel(); // Increase level number
	void updateMap(double dt); // Updates Disaster's with InActive / Active State
	void setMap(int x); //Change map to what you want 
	void loadMap(std::string anothermap, Player& player);  //Loads map from csv file
	void DrawMap(Console& anotherC, Player& player);  //Draws map onto screen
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor); // Draw player onto screen
	
};

