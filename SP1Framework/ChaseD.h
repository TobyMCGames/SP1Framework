#pragma once
#include "Player.h"
#include "Framework/console.h"

class ChaseD
{
protected:
	COORD spawner;
	COORD c;
	char direction;
	char icon;
	int distancex;
	int distancey;

public:
	ChaseD();
	~ChaseD();

	COORD getcord();
	COORD getspawnCord();
	char getdirection();
	char geticon();
	int getdistancex();
	int getdistancey();

	void setspawner();
	void BTspawner();
	void changeDirection(char d);
	void setDistance(int dx, int dy);
	void move();
	virtual bool reaction(Player& player, char tile) = 0;

};

