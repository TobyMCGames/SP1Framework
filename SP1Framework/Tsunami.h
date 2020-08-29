#pragma once
#include "SpreadingD.h"

class Tsunami : public SpreadingD
{
private:

public:
	Tsunami();
	~Tsunami();

	void toggle();
	bool reaction(Player& player, char moveP);
};
