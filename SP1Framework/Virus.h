#pragma once
#include "ChasingD.h"

class Virus : public ChasingD
{
private:
	int x, y, limit;

public:
	Virus();
	~Virus();

	int getlimit(int limit);

	void toggle();
};

