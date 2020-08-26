#pragma once
#include "Framework/console.h"
#include "Item.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>


class inventory
{
private:
	//inventory
	Item* inventoryArr[4];

public:
	inventory();
	~inventory();


};

