#pragma once
#include <string>
#include <sstream>

class Player;

class Item
{
private:
	std::string name;
	std::string symbol;
	int max_stacks;

public:
	Item();
	~Item();

	virtual void use(Player& player) = 0;

	//getter
	std::string getname();
	int getmaxstacks();
	std::string getsymbol();

	//setter
	void setname(std::string name);
	void setmax(int max);
	void setsymbol(char symbol);
};

