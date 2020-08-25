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
	Button* buttons[1] = { nullptr };
	int selector;

public:
	gameover();
	~gameover();

	int getSelector();
	void WSmenu(int updown);
	void loadgameover();
	void renderGO(Console& anotherC);
};

