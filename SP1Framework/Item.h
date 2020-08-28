#pragma once
#include <string>
#include <sstream>
class Item
{
public:

	enum class ITEM_TYPE : unsigned char
	{
		NOTHING,
		HP,
		KEY,		//For normal doors
		KEYCARD		//For stair door
	};

	ITEM_TYPE GetType() const
	{
		return itemType;
	}

	Item(ITEM_TYPE argumentItemType);
	~Item();

	//getter
	std::string getname();
	int getamt();
	int getmaxstacks();
	char getsymbol();


	//setter
	void setname(std::string name);
	void increase();
	void decrease();
	void setmax(int max);
	void setsymbol(char symbol);

private:
	std::string name;
	char symbol;
	int amt, max_stacks;
	const ITEM_TYPE itemType;
};

