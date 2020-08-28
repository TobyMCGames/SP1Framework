#pragma once
#include "Framework\console.h"
#include "Button.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
class GameClear
{
private:
	int x;
	int y;
	char GClogo[17][180];
	int option;
	Button* buttons[2];
	int selector;

public:
	GameClear();
	~GameClear();

	int getSelector();
	int GCCheckbuttons(COORD c);
	void setselector(int select);
	void increaseselector();
	void decreaseselector();
	void loadgameclear();
	void renderGC(Console& anotherC);
};

