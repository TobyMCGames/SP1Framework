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
	char disasterindicator[42][43];
	char coin[5][6];
	char inventory[9][18];
	std::string item[9][18];
public:
	UI();
	~UI();

	void renderUI(Console& anotherC, Player& anotherP, Map& map);
	void renderlife(Console& anotherC, Player& anotherP);
	void rendermapborder(Console& anotherC, Player& anotherP);
	void loadcoin();
	void rendercoin(Console& anotherC, Player& anotherP);
	void loaddisasterindicator();
	void renderdisasterindicator(Console& anotherC, Map& map);
	void loadInventory();
	void renderInventory(Console& anotherC, Player& anotherP);
};