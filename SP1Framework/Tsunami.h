#pragma once
#include "SpreadingD.h"

class Tsunami : public SpreadingD
{
private:
	int x, y;
	char direction;
public:
	Tsunami();
	~Tsunami();
	int getxchange();
	int getychange();
	char getDirection();

	void toggle();
	void setDirection(int i);
	bool reaction(Player& player, char moveP);
};
