#pragma once
#include "ChaseD.h"

class Virus : public ChaseD
{
public:
	Virus(int x, int y, char icon);
	~Virus();

	bool reaction(Player& player, char tile);
};

