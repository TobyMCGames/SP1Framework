#pragma once
#include "Player.h";
#include "Framework/console.h"

class MovingD
{
protected:
	COORD Spawner;
	COORD c;
	char direction;


public:
	MovingD();
	MovingD(int x, int y);
	~MovingD();

	COORD getcord();

	void changeDirection(char d);
	void move();
	virtual void reaction() = 0;
};

