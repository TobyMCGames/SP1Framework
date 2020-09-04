#pragma once
#include "Framework/console.h"
#include "Button.h"
#include "Player.h"
#include <fstream>
#include <vector>

class Highscore
{
private:
	COORD c;
	int x, y;
	char highscore[17][180];
	Button* buttons[1];
	int selector;
	int score[10];
public:
	Highscore();
	~Highscore();

	void loadscore(Player& player);
	void renderhighscore(Console& anotherC);
	int getselector();
	void setselector(int select);
};