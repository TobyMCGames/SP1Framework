#pragma once
#include "Framework\console.h"
#include "Button.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

class Pausemenu
{
private:
	int selector, option;
	Button* buttons[3];
public:
	Pausemenu();
	~Pausemenu();

	int getselector();

	void setselector(int select);
	void in_selector();
	void de_selector();
	void renderpause(Console& anotherC);
};

