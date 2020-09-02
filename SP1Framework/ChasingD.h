#pragma once
#include "Player.h"
#include "Framework/console.h"

class ChasingD
{
protected:
	COORD spawner;
	COORD c;
	char direction;
	char icon;
	int distancex;
	int distancey;

public:
	ChasingD();
	~ChasingD();

	COORD getcord();
	COORD getspawnCord();
	char getdirection();
	char geticon();

	void setspawner();
	void BTspawner(); //Sends cord back to spawner
	void changeDirection(char d);
	void setDistance(int dx, int dy);
	void move();
	virtual bool reaction(Player& player, char tile) = 0;

};

