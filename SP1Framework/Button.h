#pragma once
#include "Framework/console.h"
#include "string"
using namespace std;
class Button
{
private:
	int x, y;
	WORD color;
	string name;

public:
	Button(int x, int y, WORD color, string name);
	~Button();

	void renderButton(Console& console);
};

