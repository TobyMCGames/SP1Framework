#pragma once
#include "Framework/console.h"
#include "Item.h"
#include "HealthPotion.h"
#include <string>
#include <sstream>

class Player
{
private:
	COORD c;
	WORD charColor;
	std::string model;
	Item* inventory[4];
	static int life;
	int speed;
	bool Active;
	char icon;
	char facing;

public:
	Player();
	~Player();
	void changeActive();

	//get functions
	char getIcon();
	WORD getColor();
	std::string getmodel();
	int getX();
	int getY();
	char getFacing();
	int getspeed();
	int getlife();
	bool is_Active();

	//inventory
	Item* getInventory(int slot);
	void addInventory(char item);

	//set functions
	void setmodel(char direction);
	void setX(int x);
	void setY(int y);
	void increaselife();
	void decreaselife();
	void interact();
	void setLife(int x);

	//movement
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();

};

