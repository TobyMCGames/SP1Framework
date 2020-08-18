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
	int option;
public:
	mainmenu();
	~mainmenu();

	void loadmainmenu();
	void rendermenu(Console& anotherC);
};

