#pragma once
#include "trapfloor.h"

class Volcano : public trapfloor
{
private:
	int x, y;
	int direction;

public:
	Volcano();
	~Volcano();
	int getxchange();
	int getychange();

	void toggle();
	void setDirection(int i);
};

