#pragma once
#include "Framework\console.h"
#include "Button.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
class mainmenu
{
private:
	int x;
	int y;
	char logo[17][180];
	Button* buttons[5] = {nullptr, nullptr, nullptr, nullptr,  nullptr};
	int option;
public:
	mainmenu();
	~mainmenu();

	void checkButtons(COORD c);
	void loadmainmenu();
	void rendermenu(Console& anotherC);
	
};

