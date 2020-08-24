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

public:
	gameover();
	~gameover();

	void loadgameover();
	void renderGO(Console& anotherC);
};

