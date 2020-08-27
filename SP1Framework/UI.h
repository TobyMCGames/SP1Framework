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
	char disasterindicator[38][43];

public:
	UI();
	~UI();

	void renderUI(Console& anotherC, Player& anotherP, Map& map);
	void renderlife(Console& anotherC, Player& anotherP);
	void rendermapborder(Console& anotherC, Player& anotherP);
	void loaddisasterindicator();
	void renderdisasterindicator(Console& anotherC, Map& map);
	void renderInventory(Console& anotherC, Player& anotherP);
};