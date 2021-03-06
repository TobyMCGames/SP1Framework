﻿#include "Map.h"

COORD offset;

Map::Map() :
	x(135),
	y(135),
	x_change(0),
	y_change(0),
	EQtime(0),
	Vtime(0),
	Ttime(0),
	Ctime(0),
	map{ },
	DisasterPlane{ },
	earthquakeI(false),
	tornadoI(false),
	tsunamiI(false),
	volcanoI(false),
	virusI(false),
	disasters { },
	virus{ },
	EQArray{ },
	DoorArray{ },
	VArray{ },
	TArray{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
			DisasterPlane[row][col] = ' ';
		}
	}
	coins = 0;
	maplevel = -1;
	mapchange = true;

	for (int i = 0; i < 500; i++) 
	{
		EQArray[i] = nullptr;
	}

	for (int i = 0; i < 50; i++)
	{
		disasters[i] = nullptr;
	}

	for (int i = 0; i < 4; i++)
	{
		virus[i] = nullptr;
	}

	for (int i = 0; i < 1000; i++)
	{
		VArray[i] = nullptr;
	}

	for (int i = 0; i < 1000; i++)
	{
		TArray[i] = nullptr;
	}
	for (int i = 0; i < 500; i++)
	{
		DoorArray[i] = nullptr;
	}
}

Map::~Map()
{

}

bool Map::getMapChange()
{
	return mapchange;
}

std::string Map::getlevel()
{
	std::string level = std::to_string(maplevel);
	return level;
}

bool Map::collides(char direction, Player& anotherP)
{
	x_change = 0;
	y_change = 0;
	switch (direction)
	{
	case 'W':
		y_change = -1;
		break;
	case 'A':
		x_change = -1;
		break;
	case 'S':
		y_change = 1;
		break;
	case 'D':
		x_change = 1;
		break;
	}
	switch (map[anotherP.getY() + y_change][anotherP.getX() + x_change])
	{
	case 'H': //Hole
	case 'S': //Silver Wall
	case 'W': //Wall
	case '0': //HP Pot
	case 'k': //key
	case 'C': //Card
	case 'G': //Endgame stuff
		return true;
	case '@':
		//insert reset stuff here
		mapchange = true;
		earthquakeI = false;
		volcanoI = false;
		tornadoI = false;
		tsunamiI = false;
		break;
	case 'D': //Door, if active - unable to pass
		for (int i = 0; i < 500; i++)
		{
			if (DoorArray[i] != nullptr && DoorArray[i]->getX() == anotherP.getX() + x_change && DoorArray[i]->getY() == anotherP.getY() + y_change && DoorArray[i]->getState() == true)
			{
				return true; 
			}
		}
		break;
	case 'E': //Earthquake, if active - unable to pass
		for (int i = 0; i < 500; i++)
		{
			if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() + x_change && EQArray[i]->getY() == anotherP.getY() + y_change && EQArray[i]->getState() == true)
			{
				return true;
			}
		}
		break;
	case 'F':
		for (int i = 0; i < 1000; i++)
		{
			if (VArray[i] != nullptr && VArray[i]->getX() == anotherP.getX() + x_change && VArray[i]->getY() == anotherP.getY() + y_change && VArray[i]->getState() == true)
			{
				anotherP.decreaselife();
			}
		}
		break;
	case 'M':
		for (int i = 0; i < 1000; i++)
		{
			if (TArray[i] != nullptr && TArray[i]->getX() == anotherP.getX() + x_change && TArray[i]->getY() == anotherP.getY() + y_change && TArray[i]->getState() == true)
			{
				return true;
			}
		}
		break;
	case '$':
		map[anotherP.getY() + y_change][anotherP.getX() + x_change] = ' ';
		anotherP.increaseCoins();
		break;
	}
	return false;
}

char Map::getPlayerfront(Player& player)
{
	return map[player.getY() + y_change][player.getX() + x_change];
}

void Map::interact(Player& player)
{
	switch (map[player.getY() + y_change][player.getX() + x_change])
	{
	case '0':	//HP Potion
		player.addInventory('0');
		map[player.getY() + y_change][player.getX() + x_change] = ' ';
		break;
	case 'k':	//key
		player.addInventory('k');
		map[player.getY() + y_change][player.getX() + x_change] = ' ';
		break;
	case 'C': //KeyCard
		player.addInventory('C');
		map[player.getY() + y_change][player.getX() + x_change] = ' ';
		break;
	}
}

void Map::unlockDoor(Player& player, int doortype)
{
	int x = player.getX() + x_change;
	int y = player.getY() + y_change;
	int idx = 1, set = 0, origin = 0;
	for (int i = 0; i < 500; i++)
	{
		if (DoorArray[i]->getX() == x && DoorArray[i]->getY() == y && DoorArray[i]->getDoorType() == doortype && DoorArray != nullptr)
		{
			idx = i;
			set = i;
			origin = i;
			break;
		}
	}
	while (true) {
		while (true)
		{
			if (DoorArray[idx] != nullptr) {
				DoorArray[idx]->changeState();
				if (map[DoorArray[idx]->getY()][DoorArray[idx]->getX() - 1] == 'D')
				{
					if (idx > 0) {
						idx--;
					}
				}
				else
				{
					idx = set;
					break;
				}
			}
		}
		while (true)
		{
			if (DoorArray[idx] != nullptr) {
				DoorArray[idx]->changeState();
				if (map[DoorArray[idx]->getY()][DoorArray[idx]->getX() + 1] == 'D')
				{
					idx++;
				}
				else
				{
					idx = set;
					break;
				}
			}
		}
		if (map[DoorArray[idx]->getY() - 1][DoorArray[idx]->getX()] == 'D') {
			for (int i = 0; i < 500; i++)
			{
				if (DoorArray[i]->getX() == DoorArray[idx]->getX() && DoorArray[i]->getY() == DoorArray[idx]->getY() - 1) {
					idx = i;
					set = i;
					break;
				}
			}
		}
		else
		{
			idx = origin;
			set = origin;
			break;
		}
	}
	/////////////
	if (map[DoorArray[idx]->getY() + 1][DoorArray[idx]->getX()] == 'D') {
		for (int i = 0; i < 500; i++)
		{
			if (DoorArray[i]->getX() == DoorArray[idx]->getX() && DoorArray[i]->getY() == DoorArray[idx]->getY() + 1) {
				idx = i;
				set = i;
				break;
			}
		}
		while (true) {
			while (true)
			{
				if (DoorArray[idx] != nullptr) {
					DoorArray[idx]->changeState();
					if (map[DoorArray[idx]->getY()][DoorArray[idx]->getX() - 1] == 'D')
					{
						idx--;
					}
					else
					{
						idx = set;
						break;
					}
				}
			}
			while (true)
			{
				if (DoorArray[idx] != nullptr) {
					DoorArray[idx]->changeState();
					if (map[DoorArray[idx]->getY()][DoorArray[idx]->getX() + 1] == 'D')
					{
						idx++;
					}
					else
					{
						idx = set;
						break;
					}
				}
			}
			if (map[DoorArray[idx]->getY() + 1][DoorArray[idx]->getX()] == 'D') {
				for (int i = 0; i < 500; i++)
				{
					if (DoorArray[i] != nullptr) {
						if (DoorArray[i]->getX() == DoorArray[idx]->getX() && DoorArray[i]->getY() == DoorArray[idx]->getY() + 1) {
							idx = i;
							set = i;
							break;
						}
					}
				}
			}
			else
			{
				idx = origin;
				set = origin;
				break;
			}
		}
	}
	/*while (true) {
		DoorArray[idx]->changeState();
		if (DoorArray[idx - 1]->getX() == col - 1 && DoorArray[idx - 1]->getY() == row) {
			idx--;
			col--;
		}
		else {

		}
	}*/
}

int Map::frontDoortype(Player& player)
{
	for (int i = 0; i < 500; i++)
	{
		if (DoorArray[i] != nullptr) {
			if (DoorArray[i]->getX() == player.getX() + x_change && DoorArray[i]->getY() == player.getY() + y_change)
			{
				return DoorArray[i]->getDoorType();
			}
		}
		else {
			break;
		}
	}
	return 0;
}

bool Map::frontDoorState(Player& player)
{
	for (int i = 0; i < 500; i++)
	{
		if (DoorArray[i] != nullptr)
		{
			if (DoorArray[i]->getX() == player.getX() + x_change && DoorArray[i]->getY() == player.getY() + y_change)
			{
				return DoorArray[i]->getState();
			}
		}
		else {
			break;
		}
	}
	return false;
}

void Map::nextlevel()
{
	maplevel++;
}

void Map::loadMap(std::string anothermap, Player& player)
{
	for (int i = 0; i < 50; i++)   //reset disaster
	{
		if (disasters[i] != nullptr)
		{
			delete disasters[i];
			disasters[i] = nullptr;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (virus[i] != nullptr)
		{
			delete virus[i];
			virus[i] = nullptr;
		}
	}
	
	for (int i = 0; i < 1000; i++)
	{
		delete TArray[i];
		TArray[i] = nullptr;

		delete VArray[i];
		VArray[i] = nullptr;
		
		if (i < 500)
		{
			delete EQArray[i];
			EQArray[i] = nullptr;

			delete DoorArray[i];
			DoorArray[i] = nullptr;
		}
	}
	std::string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string line;
	std::string cell;
	int EQidx = 0;
	int Vidx = 0;
	int Tidx = 0;
	int Didx = 0;
	int Cidx = 0;
	int Dooridx = 0;
	int col = 0;
	int row = 0;
	while (getline(f, line))  //gets the line
	{
		std::stringstream ss(line);
		while (getline(ss, cell, ',')) //gets cell
		{
			for (unsigned int i = 0; i < cell.length(); i++)
			{
				if (i == 0)									//FIRST CHAR REPRESENTS THE OBJECT
				{
					switch (cell[i])
					{
					case'E':		//EarthQuake Tiles
						map[row][col] = cell[i];
						EQArray[EQidx] = new Earthquake;
						EQArray[EQidx]->setCOORD(col, row);
						EQidx++;
						earthquakeI = true;
						break;	
					case'F':		//Volcano Tiles
						map[row][col] = cell[i];
						VArray[Vidx] = new Volcano;
						VArray[Vidx]->setCOORD(col, row);
						Vidx++;
						volcanoI = true;
						break;
					case'M':		//tsunami waves
						map[row][col] = cell[i];
						TArray[Tidx] = new Tsunami;
						TArray[Tidx]->setCOORD(col, row);
						Tidx++;
						tsunamiI = true;
						break;
					case 'B':		//EarthQuake Boulders
						map[row][col] = ' ';
						disasters[Didx] = new Boulder(col, row, 'B');
						DisasterPlane[row][col] = 'B';
						earthquakeI = true;
						break;
					case 'p':		//Moving Disaster Object path
						map[row][col] = ' ';
						DisasterPlane[row][col] = 'p';
						break;
					case 'T':		//Tornado Object
						map[row][col] = ' ';
						disasters[Didx] = new Tornado(col, row, 'T');
						tornadoI = true;
						DisasterPlane[row][col] = 'T';
						break;
					case 'V':		//Virus Object
						map[row][col] = ' ';
						virus[Cidx] = new Virus(col, row, 'V');
						virus[Cidx]->setspawner();
						Cidx++;
						virusI = true;
						DisasterPlane[row][col] = 'V';
						break;
					case 'D':       //Door object
						map[row][col] = 'D';
						DoorArray[Dooridx] = new Doors;
						DoorArray[Dooridx]->setcord(col, row);
						break;
					case '0':		//HP Potion
						map[row][col] = '0';
						break;
					case 'k':
						map[row][col] = 'k';
						break;
					case 'C':
						map[row][col] = 'C';
						break;
					case '$':
						map[row][col] = '$';
						break;
					default:
						if (cell[i] == player.getIcon())
						{
							map[row][col] = ' ';
							DisasterPlane[row][col] = ' ';
							player.setX(col);
							player.setY(row);
						}
						else
						{
							map[row][col] = cell[i];
							DisasterPlane[row][col] = ' ';
						}
					}
					
				}
				else										//SECOND CHAR REPRESENTS DIRECTION OR WHATEVER U WANT IT TO BE
				{
					switch (cell[i])
					{
					case 'A':
						if (cell[i - 1] == 'F' && Vidx >0)
						{
							VArray[Vidx - 1]->toggle();
						}
						break;
					case 'Q':
						if (cell[i - 1] == 'M' && Tidx > 0)
						{
							TArray[Tidx - 1]->toggle();
						}
						break;
					case 'U':
						disasters[Didx]->changeDirection('W');
						disasters[Didx]->setSpawner();
						Didx++;
						break;
					case 'D':
						disasters[Didx]->changeDirection('S');
						disasters[Didx]->setSpawner();
						Didx++;
						break;
					case 'L':
						disasters[Didx]->changeDirection('A');
						disasters[Didx]->setSpawner();
						Didx++;
						break;
					case 'R':
						disasters[Didx]->changeDirection('D');
						disasters[Didx]->setSpawner();
						Didx++;
						break;
					case '1':
						DoorArray[Dooridx]->setType(1);
						Dooridx++;
						break;
					case '2':
						DoorArray[Dooridx]->setType(2);
						Dooridx++;
						break;
					}
				}
			}
			col++;
			
		}
		row++;
		col = 0;
	}
	f.close();
	mapchange = false;

}

void Map::updateMap(double dt, Player& player)
{
	int EQidx;
	EQtime += dt;
	Vtime += dt;
	Ttime += dt;
	Ctime += dt;
	if (EQtime >= 0.16 * 1)
	{
		for (int i = 0; i < 5; i++) //EarthQuake Tiles
		{
			if (earthquakeI && EQArray[0])
			{
				EQidx = rand() % 500;
				while (EQArray[EQidx] == nullptr)
				{
					EQidx = rand() % 500;
				}

				if (EQArray[EQidx]->getState() != true)
				{
					EQArray[EQidx]->toggle();
					EQtime = 0;
				}
			}
		}
	}
		//Volcano Tiles
	if (Vtime >= 0.16 * 3)
	{
		if (volcanoI)
		{
			spreadcheck();
			Vtime = 0;


		}
	}

		//Tsunami Tiles
	if (Ttime >= 0.16 * 2)
	{
		if (tsunamiI)
		{
			wave(player);
			Ttime = 0;

		}
	}

	if (Ctime >= 0.08)
	{
		if (virusI)
		{
			Dchase(player);
			Ctime = 0;
		}
	}
}


void Map::setMap(int x)
{
	mapchange = true;
	maplevel = x;

}

void Map::DrawMap(Console& anotherC, Player& player)
{
	if (player.getX() >= 23 && player.getX() <= 113)
	{
		offset.X = player.getX() - 23 ;
	}
	////////////////////////////////////////////////////////////////////////////////////
	else if (player.getX() < 23)
	{
		offset.X = 0;
	}                                  //For sudden position change after changing map (x - axis)
	else if (player.getX() > 113)
	{
		offset.X = 90;
	}
	///////////////////////////////////////////////////////////////////////////////////
	if (player.getY() >= 21 && player.getY() <= 114)
	{
		offset.Y = player.getY() - 21 ;
	}
	////////////////////////////////////////////////////////////////////////////////////
	else if (player.getY() < 21)
	{
		offset.Y = 0;
	}                                  //For sudden position change after changing map (y - axis)
	else if (player.getY() > 114)
	{
		offset.Y = 93;
	}
	///////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 42; i++) //y
	{
		for (int j = 0; j < 45; j++) //x
		{
			switch (map[i + offset.Y][j + offset.X])
			{
				case 'W':
					anotherC.writeToBuffer(45 + j * 2, i, "±±", 0x08);
					break;
				case 'H':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x00);
					break;
				case 'Z':
				case ' ':
					anotherC.writeToBuffer(45 + j * 2, i, "²²", 0x8F);
					break;
				case '@':
					anotherC.writeToBuffer(45 + j * 2, i, (char)220, 0xF8);
					anotherC.writeToBuffer(46 + j * 2, i, (char)220, 0xF8);
					break;
				case 'G':
					anotherC.writeToBuffer(45 + j * 2, i, (char)233, 0xF4);
					anotherC.writeToBuffer(46 + j * 2, i, (char)247, 0xF4);
					break;
				case 'I':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x6E);
					break;
				case '0':
					anotherC.writeToBuffer(45 + j * 2, i, "00", 0xF4);
					break;
				case 'k':
					anotherC.writeToBuffer(45 + j * 2, i, "kk", 0x8E);
					break;
				case 'C':
					anotherC.writeToBuffer(45 + j * 2, i, "CC", 0x8E);
					break;
				case '$':
					anotherC.writeToBuffer(45 + j * 2, i, "$$", 0x8E);
					break;
				case 'E':
					for (int k = 0; k < 500; k++)
					{
						if (EQArray[k] != nullptr && EQArray[k]->getX() == j + offset.X && EQArray[k]->getY() == i + offset.Y)
						{
							anotherC.writeToBuffer(45 + j * 2, i, "²²", EQArray[k]->getColor());
						}
					}
					break;
				case 'F':
					for (int k = 0; k < 1000; k++)
					{

						if (VArray[k] != nullptr && VArray[k]->getX() == j + offset.X && VArray[k]->getY() == i + offset.Y)
						{
							anotherC.writeToBuffer(45 + j * 2, i, "²²", VArray[k]->getColor());
						}
					}
					break;
				case 'M':
					for (int k = 0; k < 1000; k++)
					{
						if (TArray[k] != nullptr && TArray[k]->getX() == j + offset.X && TArray[k]->getY() == i + offset.Y)
						{
							anotherC.writeToBuffer(45 + j * 2, i, "²²", TArray[k]->getColor());
						}
					}
					break;
				case 'S':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0xB0);
					break;
				case 'D':
					for (int k = 0; k < 500; k++)
					{
						if (DoorArray[k] != nullptr && DoorArray[k]->getX() == j + offset.X && DoorArray[k]->getY() == i + offset.Y)
						{
							anotherC.writeToBuffer(45 + j * 2, i, "²²", DoorArray[k]->getcolor());
						}
					}
					break;
			}	
			switch (DisasterPlane[i + offset.Y][j + offset.X])
			{
			case 'B':
				anotherC.writeToBuffer(45 + j * 2, i, "±±", 0x68);
				break;
			case 'T':
				anotherC.writeToBuffer(45 + j * 2, i, "°°", 0x2F);
				break;
			case 'V':
				anotherC.writeToBuffer(45 + j * 2, i, "°°", 0x5D);
				break;
			}
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(45 + 2 * (anotherP.getX() - offset.X), anotherP.getY() - offset.Y, anotherP.getmodel() , charColor);
}

bool Map::getearthquakeI()
{
	return earthquakeI;
}

bool Map::gettornadoI()
{
	return tornadoI;
}

bool Map::gettsunamiI()
{
	return tsunamiI;
}

bool Map::getvolcanoI()
{
	return volcanoI;
}

void Map::spreadcheck()
{
	int x = 0;
	int y = 0;
	int max = VArray[0]->getamt();
	bool added = false;
	for (int j = 0; j < max; j++) //Starting Point
	{
		if (VArray[j] != nullptr)
		{
			for (int i = 0; i < 4; i++) //Spread
			{
				VArray[j]->setDirection(i);
				x = VArray[j]->getxchange();
				y = VArray[j]->getychange();
				if (map[VArray[j]->getY() + y][VArray[j]->getX() + x] == ' ' )
				{
					if (VArray[999] == nullptr)
					{
						map[VArray[j]->getY() + y][VArray[j]->getX() + x] = 'F';
					}
					for (int k = 0; k < 1000; k++)
					{
						if (VArray[k] == nullptr && added == false)
						{
							VArray[k] = new Volcano;
							VArray[k] -> setCOORD(VArray[j]->getX() + x, VArray[j]->getY() + y);
							VArray[k]->toggle();
							added = true;
						}
					}
					added = false;
				}
			}
		}
	};
}

void Map::wave(Player& player)
{
	int x = 0;
	int y = 0;
	int max = TArray[0]->getamt();
	bool added = false;
	for (int j = 0; j < max; j++) //Starting Point
	{
		if (TArray[j] != nullptr)
		{
			for (int i = 0; i < 4; i++) //Spread
			{
				TArray[j]->setDirection(i);
				x = TArray[j]->getxchange();
				y = TArray[j]->getychange();
				if (map[TArray[j]->getY() + y][TArray[j]->getX() + x] == ' ')
				{
					if (TArray[999] == nullptr)
					{
						map[TArray[j]->getY() + y][TArray[j]->getX() + x] = 'M';
					}
					for (int k = 0; k < 1000; k++)
					{
						if (TArray[k] == nullptr && added == false)
						{
							TArray[k] = new Tsunami;
							TArray[k]->setCOORD(TArray[j]->getX() + x, TArray[j]->getY() + y);
							TArray[k]->toggle();
							added = true;
							if (getPlayerfront(player) == 'M') {
								TArray[k]->reaction_towards(player, player.getFacing());
								if (map[player.getY()][player.getX()] == 'W' || map[player.getY()][player.getX()] == 'M') {
									for (int y = 0; y < 5; y++) {
										player.decreaselife();
									}
									break;
								}
							}
							else {
								TArray[k]->reaction_away(player, player.getFacing());
								if (map[player.getY()][player.getX()] == 'W' || map[player.getY()][player.getX()] == 'M') {
									for (int y = 0; y < 5; y++) {
										player.decreaselife();
									}
									break;
								}
							}
						}
					}
					added = false;
				}
			}
		}
	}
}



// Disaster functions
void Map::Dmoves(Player& player)
{
	for (int i = 0; i < 50; i++)
	{
		if (disasters[i] != nullptr)
		{
			COORD cord = disasters[i]->getcord();
			int x = 0, y = 0;
			switch (disasters[i]->getdirection())
			{
			case 'W':
				y = -1;
				break;
			case 'A':
				x = -1;
				break;
			case 'S':
				y = 1;
				break;
			case 'D':
				x = 1;
				break;
			}
			if (disasters[i]->reaction(player, map[cord.Y + y][cord.X + x]) == true)
			{
				DisasterPlane[cord.Y][cord.X] = 'p';
				cord = disasters[i]->getcord();
				DisasterPlane[cord.Y][cord.X] = disasters[i]->geticon();
			}
			if ((DisasterPlane[cord.Y + y][cord.X + x] != 'p') &&  (DisasterPlane[cord.Y + y][cord.X + x] != 'h'))
			{
				switch (disasters[i]->getdirection())
				{
				case 'W':
				case 'S':
					if (DisasterPlane[cord.Y][cord.X + 1] == 'p')
					{
						disasters[i]->changeDirection('D');
						break;
					}
					else if((DisasterPlane[cord.Y][cord.X - 1] == 'p'))
					{
						disasters[i]->changeDirection('A');
						break;
					}
					else if (disasters[i]->getdirection() == 'W')
					{
						disasters[i]->changeDirection('S');
						break;
					}
					else
					{
						disasters[i]->changeDirection('W');
						break;
					}
				case 'A':
				case 'D':
					if (DisasterPlane[cord.Y + 1][cord.X] == 'p')
					{
						disasters[i]->changeDirection('S');
						break;
					}
					else if (DisasterPlane[cord.Y - 1][cord.X] == 'p')
					{
						disasters[i]->changeDirection('W');
						break;
					}
					else if (disasters[i]->getdirection() == 'A')
					{
						disasters[i]->changeDirection('D');
						break;
					}
					else
					{
						disasters[i]->changeDirection('A');
						break;
					}
				}
			}
			DisasterPlane[cord.Y][cord.X] = 'p';
			disasters[i]->move();
			cord = disasters[i]->getcord();
			DisasterPlane[cord.Y][cord.X] = disasters[i]->geticon();
		}
	}
}

void Map::Dchase(Player& player)
{

	for (int j = 0; j < 4; j++)
	{
		if (virus[j] != nullptr)
		{
			COORD cord = virus[j]->getcord();
			int xdiff = 0;
			int ydiff = 0;
			int x = 0;
			int y = 0;
			xdiff = cord.X - player.getX();
			ydiff = cord.Y - player.getY();
			virus[j]->setDistance(ydiff, xdiff);
			if (virus[j]->reaction(player, map[cord.Y][cord.X]) == false)
			{
				if (virus[j]->getdistancex() < 9 && virus[j]->getdistancex() < virus[j]->getdistancey() && virus[j]->getdistancex() > 0)
				{
					virus[j]->changeDirection('W');
				}
				else if (virus[j]->getdistancex() > -9 && virus[j]->getdistancex() < virus[j]->getdistancey() && virus[j]->getdistancex() < 0)
				{
					virus[j]->changeDirection('S');
				}
				else if (virus[j]->getdistancey() < 9 && virus[j]->getdistancey() < virus[j]->getdistancex() && virus[j]->getdistancey() > 0)
				{
					virus[j]->changeDirection('A');
				}
				else if (virus[j]->getdistancey() > -9 && virus[j]->getdistancey() < virus[j]->getdistancex() && virus[j]->getdistancey() < 0)
				{
					virus[j]->changeDirection('D');
				}
				else if (virus[j]->getdistancey() == 0 && virus[j]->getdistancex() == 0)
				{
					virus[j]->changeDirection('Q');
				}
				else
				{
					int chance = rand() % 5;
					switch (chance)
					{
					case 0:
						virus[j]->changeDirection('W');
						break;
					case 1:
						virus[j]->changeDirection('A');
						break;
					case 2:
						virus[j]->changeDirection('S');
						break;
					case 3:
						virus[j]->changeDirection('D');
						break;
					case 4:
						virus[j]->changeDirection('Q');
						break;
					}
				}
			}
			{
				COORD cord = virus[j]->getcord();
				DisasterPlane[cord.Y][cord.X] = ' ';
			}
			{

				virus[j]->move();
				COORD cord = virus[j]->getcord();
				if (map[cord.Y][cord.X] == 'W')
				{
					DisasterPlane[cord.Y][cord.X] = ' ';
				}
				else if (map[cord.Y][cord.X] == 'H')
				{
					DisasterPlane[cord.Y][cord.X] = ' ';
				}
				else
				{
				DisasterPlane[cord.Y][cord.X] = virus[j]->geticon();
				}
			}
		}
	}
}
