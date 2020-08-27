#pragma once
#include "MovingD.h"
class Boulder : public MovingD
{
public:
	Boulder(int x, int y, char icon);
	~Boulder();

	bool reaction(Player& player, char tile);
};

