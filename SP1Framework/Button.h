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

	string getName();
	int getX(void);
	int getY(void);
	void renderButton(Console& console);
};

