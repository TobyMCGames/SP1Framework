#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "Framework\console.h"
#include "Player.h"
class UI
{
private:
	char state[29][36];
	char disasterindicator[44][12];
	Player User;
public:
	UI();
	~UI();


	void renderlife(Console& anotherC);
	void rendermapborder(Console& anotherC);
	void loadstate();
	void renderstate(Console& anotherC);
	void loaddisasterindicator();
	void renderdisasterindicator(Console& anotherC);
};

