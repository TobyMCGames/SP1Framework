#pragma once
#include "Framework/console.h"
#include <string>
using namespace std;


class ItemObject
{
public:
	ItemObject();
	~ItemObject();

	virtual void setXY();
	virtual void setFunction();
	virtual void setIcon();

	//Get functions
	int getX();
	int getY();
	char getIcon();
	string getFunction();
protected:
	COORD c;
	string Function;
	char Icon;
};

