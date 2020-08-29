#pragma once
#include "trapfloor.h"

class Volcano : public trapfloor
{
private:
	int x, y;
	int direction;
	static int amount;

public:
	Volcano();
	~Volcano();
	int getxchange();
	int getychange();
	int getamt();

	void toggle();
	void setDirection(int i);
};

