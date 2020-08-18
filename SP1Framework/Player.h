#pragma once
class Player
{
private:
	int location[2]; //(x, y)
	int health;
	bool Active;
	char facing;

public:
	Player();
	~Player();
	void changeActive();

	//get functions
	int getX();
	int getY();
	bool is_Active();

	//movement
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();
};

