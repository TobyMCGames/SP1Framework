#pragma once
#include "ItemObject.h"

class itemtest : public ItemObject
{
private:
	bool item_exist;
	bool player_near;
public:
	itemtest();
	~itemtest();

	//set funtions
	void setXY(int x, int y);
	void setFunction(string function);
	void setIcon(char icon);

	//state change
	bool is_item_exist();
	void change_exist();
	bool is_player_near();
	void change_near();
};

