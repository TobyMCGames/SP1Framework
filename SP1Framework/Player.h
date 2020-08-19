#pragma once
#include "Framework/console.h"

class Player
{
private:
	COORD c; //(x, y)
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
	int getlife();
	bool is_Active();

	//movement
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();
};

