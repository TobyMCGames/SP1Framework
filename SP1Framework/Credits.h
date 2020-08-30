#pragma once
#include "Framework\console.h"
#include "Button.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

class Credits
{
private:
	Button* buttons[1];
	int selector;

public:
	Credits();
	~Credits();

	int getselector();

	void setselector(int select);

	void renderCredits(Console& anotherC);
};

