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
	int selector;
	int option;
public:
	mainmenu();
	~mainmenu();

	int getselector();
	int checkButtons(COORD c);
	void WSmenu(int updown);
	void loadmainmenu();
	void rendermenu(Console& anotherC);
	
};

