#pragma once
#include "Framework/console.h"
#include "Item.h"
#include "HealthPotion.h"
#include "Key.h"
#include "Keycard.h"
#include <string>
#include <sstream>

class Player
{
private:
	COORD c;
	WORD charColor;
	std::string model;
	Item* inventory[4];
	int select;
	static int life;
	int speed;
	char icon;
	char facing;

public:
	Player();
	~Player();

	//get functions
	char getIcon();
	WORD getColor();
	std::string getmodel();
	int getX();
	int getY();
	char getFacing();
	int getspeed();
	int getlife();
	int getselect();

	//inventory
	Item* getInventory(int slot);
	void setInventory(int slot, char item, int value);
	void addInventory(char item);
	void nextItem();
	void useItem();

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

