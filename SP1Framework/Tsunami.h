#pragma once
#include "SpreadingD.h"

class Tsunami : public SpreadingD
{
private:
	int x, y;
	char direction;
	static int amount;
public:
	Tsunami();
	~Tsunami();
	int getamt();
	int getxchange();
	int getychange();
	char getDirection();

	void toggle();
	void setDirection(int i);
	bool reaction(Player& player, char moveP);
};
