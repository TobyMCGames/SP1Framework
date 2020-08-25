#pragma once
#include "MovingD.h"
#include "Player.h"

class Tornado : public MovingD
{
public:
	Tornado(int x, int y);
	~Tornado();

	void reaction(Player &player);
};

