#pragma once
#include "Framework/console.h"

class trapfloor
{
private:
	char icon;
	WORD color;
	COORD c;
	bool Active;

public:
	trapfloor();
	~trapfloor();

	virtual void toggle() = 0;
	//setter
	void setIcon(char icon);
	void setColor(WORD color);
	void setCOORD(SHORT x, SHORT y);
	void setActive(bool state);

	//getter
	char getIcon();
	WORD getColor();
	SHORT getX();
	SHORT getY();
	bool getState();

};

