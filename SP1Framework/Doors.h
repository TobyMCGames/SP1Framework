#pragma once
#include "Framework/console.h"
class Doors
{
private: 
	COORD c;
	int doortype;
	bool Activated;
	WORD color;


public:
	Doors();
	~Doors();

	int getX();
	int getY();
	int getDoorType();
	bool getState();
	WORD getcolor();

	void setcord(int x, int y);
	void setType(int i);
	void changeState();
};

