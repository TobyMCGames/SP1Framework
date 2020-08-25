#pragma once
#include "MovingD.h"
class Boulder : public MovingD
{
public:
	Boulder(int x, int y);
	~Boulder();

	void reaction(Player& player);
};

