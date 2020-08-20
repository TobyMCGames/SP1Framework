#pragma once
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

class SplashScreen
{
private:
	char screen[42][180];
public:
	SplashScreen();
	~SplashScreen();

	void loadSplashScreen();
	void renderSplashScreen(Console& anotherC);
};

