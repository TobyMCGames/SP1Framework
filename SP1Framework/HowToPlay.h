#pragma once
#include "Framework\console.h"
#include "Button.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

class HowToPlay
{
private:
	Button* buttons[1];
	int selector;

public:
	HowToPlay();
	~HowToPlay();

	int getselector();

	void setselector(int select);

	void renderHTP(Console& anotherC);
};

