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
	Button* buttons[2] = { nullptr , nullptr};
	int selector;

public:
	gameover();
	~gameover();

	int getSelector();
	void WSmenu(int updown);
	int GOCheckbuttons(COORD c);
	void loadgameover();
	void renderGO(Console& anotherC);
};

