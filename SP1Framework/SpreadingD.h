#pragma once
#include "Player.h"
#include "Framework/console.h"

class SpreadingD
{
private:
	char icon;
	WORD color;
	COORD c;
	bool Active;

public:
	SpreadingD();
	~SpreadingD();

	virtual void toggle() = 0;
	virtual bool reaction_away(Player& player, char moveP) = 0;
	virtual bool reaction_towards(Player& player, char moveP) = 0;
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
