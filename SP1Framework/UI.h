#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "Framework\console.h"
#include "Player.h"
#include "Map.h"

class UI
{
private:
	char state[29][36];
	char disasterindicator[12][43];
public:
	UI();
	~UI();

	void renderUI(Console& anotherC, Player& anotherP, Map& map);
	void renderlife(Console& anotherC, Player& anotherP);
	void rendermapborder(Console& anotherC, Player& anotherP);
	void loadstate();
	void renderstate(Console& anotherC, Player& anotherP);
	void loaddisasterindicator();
	void renderdisasterindicator(Console& anotherC, Map& map);
	void renderInventory(Console& anotherC, Player& anotherP);
};

