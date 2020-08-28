#pragma once
#include "trapfloor.h"
#include "Player.h"

class Volcano : public trapfloor
{
private:

public:
	Volcano();
	~Volcano();
	Volcano(int x,int y);

	void toggle();
};

