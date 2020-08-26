#pragma once
#include "MovingD.h"
class Boulder : public MovingD
{
public:
	Boulder(int x, int y, char icon);
	~Boulder();

	void reaction(Player& player, char tile);
};

