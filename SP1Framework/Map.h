#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Framework\console.h"
#include "Player.h"

#include <sstream>
class Map
{
private:
	int x, y;
	char map[135][135];
	bool mapchange;
public:
	Map();
	~Map();

	//get functions
	bool getMapChange();
	bool collides(char direction, Player& anotherP);

	//get entities
	void getplayer(Player& player);

	//Input and draw 
	void inputMap(std::string anothermap);
	void DrawMap(Console& anotherC);
	void DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor);
	
};

