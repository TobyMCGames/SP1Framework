#pragma once
#include "MovingD.h"
#include "Player.h"
#include <random>

class Tornado : public MovingD
{
public:
	Tornado(int x, int y,char icon);
	~Tornado();

	void reaction(Player &player, char tile);
};

