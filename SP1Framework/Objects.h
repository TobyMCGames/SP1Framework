#pragma once
#include "Framework/console.h"
#include <string>
using namespace std;

class Objects
{
private:
	COORD c;
	string function;
	char icon;

public:
	Objects(int x, int y, string function, char icon);
	~Objects();


	//Get functions
	int getX();
	int getY();
	char geticon();
	string getfunction();

	//Set functions
	void setX(int x);
	void setY(int y);
};
