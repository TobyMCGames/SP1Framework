#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "Framework\console.h"
#include "Player.h"
class UI
{
private:
	char state[33][33];
	char dgrid[13][23];
	char dicons[5][10];
	Player User;
public:
	UI();
	~UI();


	void renderlife(Console& anotherC);
	void rendermapborder(Console& anotherC);
	void loadstate();
	void renderstate(Console& anotherC);
	void loadgrid();
	void rendergrid(Console& anotherC);
};

