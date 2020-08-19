#pragma once
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
class mainmenu
{
private:
	int x;
	int y;
	char logo[180][17];
	char button[40][20];
	int option;
public:
	mainmenu();
	~mainmenu();

	void loadmainmenu();
	void rendermenu(Console& anotherC);
	void renderstart(Console& anotherC, int x, int y);
	void renderoptions(Console& anotherC, int x, int y);
	void renderleave(Console& anotherC, int x, int y);
};

