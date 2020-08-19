#pragma once
#include "Framework/console.h"

class Player
{
private:
	COORD p_screen; //coordinate of where player is on the screen
	COORD p_map; //coordinate of where player is on the map
	static int life;
	bool Active;
	char facing;

public:
	Player();
	~Player();
	void changeActive();

	//get functions
	int getX();
	int getY();

	int getscreenX();
	int getscreenY();

	int getmapX();
	int getmapY();

	int getlife();
	bool is_Active();

	//movement
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();
};

