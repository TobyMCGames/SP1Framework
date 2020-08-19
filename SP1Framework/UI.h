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
	int x;
	int y;
	char state[9][27];
	char dindicater[13][23];
	Player User;
public:
	UI();
	~UI();

	void renderlife(Console& anotherC);
	void loadstate();
	void renderstate(Console& anotherC);
	void loaddindicater();
	void renderdindicater(Console& anotherC);
};

