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
	Button* buttons[6] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
	int selector;
public:
	mainmenu();
	~mainmenu();

	int getselector();
	int checkButtons(COORD c);

	void setselector(int select);
	void increaseselector();
	void decreaseselector();
	void loadmainmenu();
	void rendermenu(Console& anotherC);
	
};

