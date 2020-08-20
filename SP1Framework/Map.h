#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Framework\console.h"
#include "Player.h"
#include "Objects.h"

#include <sstream>
class Map
{
private:
	int x, y;
	char map[135][135];
	int maplevel;
	bool mapchange;
	Objects* stairs[1];

public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	string getlevel();
	bool collides(char direction, Player& anotherP);

	//get entities
	void getplayer(Player& player);


	//Input and draw 
	void changeMap(Player& player);
	void nextlevel();
	void inputMap(std::string anothermap, Player& player);
	void DrawMap(Console& anotherC, Player& player);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	
};

