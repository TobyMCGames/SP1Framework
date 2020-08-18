#pragma once
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
class mainmenu
{
private:
	char logo[149][15];
public:
	mainmenu();
	~mainmenu();

	void loadmainmenu();
	void rendermenu(Console& anotherC);
};

