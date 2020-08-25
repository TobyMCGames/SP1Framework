#pragma once
#include "Framework\console.h"
#include "Button.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
class gameover
{
private:
	int x;
	int y;
	char GOlogo[17][180];
	int option;
	Button* buttons[2];
	int selector;

public:
	gameover();
	~gameover();

	int getSelector();
	int GOCheckbuttons(COORD c);
	void setselector(int select);
	void increaseselector();
	void decreaseselector();
	void loadgameover();
	void renderGO(Console& anotherC);
};

