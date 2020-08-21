#pragma once
#include "Events.h"
class Earthquake : public Events
{
private:
	char symbol = 'E';
public:
	Earthquake();
	~Earthquake();

};

