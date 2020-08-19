#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include "Framework\console.h"
#include "Player.h"
class UI
{
private:
	Player User;
public:
	UI();
	~UI();

	void renderlife(Console& anotherC);
};

