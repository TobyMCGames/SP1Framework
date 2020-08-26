#pragma once
#include "Player.h"
#include "Framework/console.h"

class MovingD
{
protected:
	COORD Spawner;
	COORD c;
	char direction;
	char icon;

public:
	MovingD();
	~MovingD();

	COORD getcord();
	COORD getSpawnCord();
	char getdirection();
	char geticon();

	void changeDirection(char d);
	void move();
	virtual void reaction(Player& player, char tile) = 0;
};

