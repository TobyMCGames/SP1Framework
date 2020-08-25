#pragma once
#include "trapfloor.h"
#include <time.h>

class Tornado : public trapfloor
{
public:
	Tornado();
	~Tornado();

	void reaction();
	void spawnT();
};

