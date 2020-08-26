#include "Map.h"

COORD offset;

Map::Map() :
	x(135),
	y(135),
	fixed_update(0),
	map{ },
	DisasterPlane{ },
	earthquakeI(false),
	tornadoI(false),
	tsunamiI(false),
	volcanoI(false),
	disasters { },
	EQArray{ },
	VArray{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
			DisasterPlane[row][col] = ' ';
		}
	}
	maplevel = 0;
	mapchange = true;

	for (int i = 0; i < 500; i++) 
	{
		EQArray[i] = nullptr;
	}

	for (int i = 0; i < 50; i++)
	{
		disasters[i] = nullptr;
	}

	for (int i = 0; i < 500; i++)
	{
		VArray[i] = nullptr;
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
	switch (direction)
	{
	case 'W':
		switch (map[anotherP.getY() - anotherP.getspeed()][anotherP.getX()]) {
		case 'W':
			return true;
		case '@':
			//insert reset stuff here
			mapchange = true;
			earthquakeI = false;
			volcanoI = false;
			tornadoI = false;
			tsunamiI = false;
			break;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() && EQArray[i]->getY() == anotherP.getY() - anotherP.getspeed() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		case 'F':
			for (int i = 0; i < 500; i++)
			{
				if (VArray[i] != nullptr && VArray[i]->getX() == anotherP.getX() && VArray[i]->getY() == anotherP.getY() - anotherP.getspeed() && VArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		}
		break;
	case 'S':
		switch (map[anotherP.getY() + anotherP.getspeed()][anotherP.getX()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
			break;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() && EQArray[i]->getY() == anotherP.getY() + anotherP.getspeed() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		case 'F':
			for (int i = 0; i < 500; i++)
			{
				if (VArray[i] != nullptr && VArray[i]->getX() == anotherP.getX() && VArray[i]->getY() == anotherP.getY() - anotherP.getspeed() && VArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		}
		break;
	case 'A':
		switch (map[anotherP.getY()][anotherP.getX() - anotherP.getspeed()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
			break;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() - anotherP.getspeed() && EQArray[i]->getY() == anotherP.getY() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		case 'F':
			for (int i = 0; i < 500; i++)
			{
				if (VArray[i] != nullptr && VArray[i]->getX() == anotherP.getX() && VArray[i]->getY() == anotherP.getY() - anotherP.getspeed() && VArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		}
		break;
	case 'D':
		switch (map[anotherP.getY()][anotherP.getX() + anotherP.getspeed()]) {
		case 'W':
			return true;
		case '@':
			mapchange = true;
			break;
		case 'E':
			for (int i = 0; i < 500; i++)
			{
				if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() + anotherP.getspeed() && EQArray[i]->getY() == anotherP.getY() && EQArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		case 'F':
			for (int i = 0; i < 500; i++)
			{
				if (VArray[i] != nullptr && VArray[i]->getX() == anotherP.getX() && VArray[i]->getY() == anotherP.getY() - anotherP.getspeed() && VArray[i]->getState() == true)
				{
					return true;
				}
			}
			break;
		}
		break;
	}
	return false;
}

void Map::nextlevel()
{
	maplevel++;
}

void Map::loadMap(std::string anothermap, Player& player)
{
	for (int i = 0; i < 50; i++)
	{
		if (disasters[i] != nullptr)
		{
			delete disasters[i];
			disasters[i] = nullptr;
		}
	}
	std::string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string line;
	std::string cell;
	int EQidx = 0;
	int Vidx = 0;
	int Didx = 0;
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
					case'E':
						map[row][col] = cell[i];
						EQArray[EQidx] = new Earthquake;
						EQArray[EQidx]->setCOORD(col, row);
						EQidx++;
						earthquakeI = true;
						break;
					case'F':
						map[row][col] = cell[i];
						VArray[Vidx] = new Volcano;
						VArray[Vidx]->setCOORD(col, row);
						Vidx++;
						volcanoI = false;
						break;
					case 'B':
						map[row][col] = ' ';
						disasters[Didx] = new Boulder(col, row, 'B');
						Didx++;
						DisasterPlane[row][col] = 'B';
					case 'p':
						map[row][col] = ' ';
						DisasterPlane[row][col] = 'p';
						break;
					case 'h':
						map[row][col] = ' ';
						DisasterPlane[row][col] = 'h';
						break;
					case 'T':
						map[row][col] = ' ';
						disasters[Didx] = new Tornado(col, row, 'T');
						Didx++;
						tornadoI = true;
						DisasterPlane[row][col] = 'T';
						break;
					case '0':
						map[row][col] = ' ';

					default:
						if (cell[i] == player.getIcon())
						{
							map[row][col] = ' ';
							player.setX(col);
							player.setY(row);
						}
						else
						{
							map[row][col] = cell[i];
						}
					}
					
				}
				else										//SECOND CHAR REPRESENTS DIRECTION OR WHATEVER U WANT IT TO BE
				{
					//if (cell[i] == d) blahblahblah
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

void Map::updateMap(double dt)
{
	int EQidx;
	int Vidx;
	fixed_update += dt;
	if (fixed_update >= 0.16 * 1) 
	{
		for (int i = 0; i < 5; i++) //EarthQuake Tiles
		{
			EQidx = rand() % 500;
			while (EQArray[EQidx] == nullptr)
			{
				EQidx = rand() % 500;
			}

			if (EQArray[EQidx]->getState() != true)
			{
				EQArray[EQidx]->toggle();
				fixed_update = 0;
			}
		}

		//for (int j = 0; j < 5; j++) //Volcano Tiles
		//{
		//	Vidx = rand() % 500;
		//	while (VArray[Vidx] == nullptr)
		//	{
		//		Vidx = rand() % 500;
		//	}

		//	if (VArray[Vidx]->getState() != true)
		//	{
		//		VArray[Vidx]->toggle();
		//		fixed_update = 0;
		//	}
		//}
		//The rest of the disasters
	}

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
				case ' ':
					anotherC.writeToBuffer(45 + j * 2, i, "²²", 0x8F);
					break;
				case '@':
					anotherC.writeToBuffer(45 + j * 2, i, (char)220, 0xF8);
					anotherC.writeToBuffer(46 + j * 2, i, (char)220, 0xF8);
					break;
				case 'I':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x6E);
					break;
				case '@':
					anotherC.writeToBuffer(45 + j * 2, i, (char)223, 0x8F);
					anotherC.writeToBuffer(46 + j * 2, i, (char)223, 0x8F);
					break;
				case '1':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x6E);
					break;
				case '2':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x6E);
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
					for (int k = 0; k < 500; k++)
					{
						if (VArray[k] != nullptr && VArray[k]->getX() == j + offset.X && VArray[k]->getY() == i + offset.Y)
						{
							anotherC.writeToBuffer(45 + j * 2, i, "²²", VArray[k]->getColor());
						}
					}
					break;
				case 'S':
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0xB0);
					break;
			}	
			switch (DisasterPlane[i + offset.Y][j + offset.X])
			{
			case 'B':
				anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x1F);
				break;
			case 'T':
				anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x2A);
				break;
			}
		}
	}
}

void Map::DrawPlayer(Console& anotherC, Player& anotherP, WORD charColor)
{
	anotherC.writeToBuffer(45 + 2 * (anotherP.getX() - offset.X), anotherP.getY() - offset.Y, anotherP.getmodel() , charColor);
}

/*
char Map::facing_icon(char facing, Player& player, Item& item)
{
	if (player.is_Active() == true) {
		switch (facing)
		{
		case 'W':
			if ((player.getX() == item.getX()) && ((player.getY() - 1) == item.getY() - 1)) {
				item.change_exist();
				return item.is_item_exist();
				break;
			}
		case 'A':
			if (((player.getX() - 1) == item.getX()) && (player.getY() == item.getY())) {
				item.change_exist();
				return item.is_item_exist();
				break;
			}
		case 'S':
			if ((player.getX() == item.getX()) && ((player.getY() - 1) == item.getY() + 1)) {
				item.change_exist();
				return item.is_item_exist();
				break;
			}
		case 'D':
			if (((player.getX() + 1) == item.getX()) && (player.getY() == item.getY())) {
				item.change_exist();
				return item.is_item_exist();
			}
		}
	}
}
*/

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


// Disaster functions
void Map::Disasterfacing()
{
	for (int i = 0; i < 50; i++)
	{
		if (disasters[i] != nullptr)
		{
			COORD cord= disasters[i]->getcord();
			if (DisasterPlane[cord.Y - 1][cord.X] == 'h')
			{
				disasters[i]->changeDirection('W');
			}
			if (DisasterPlane[cord.Y][cord.X - 1] == 'h')
			{
				disasters[i]->changeDirection('A');
			}
			if (DisasterPlane[cord.Y + 1][cord.X] == 'h')
			{
				disasters[i]->changeDirection('S');
			}
			if (DisasterPlane[cord.Y][cord.X + 1] == 'h')
			{
				disasters[i]->changeDirection('D');
			}
		}
	}
}

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
			if ((DisasterPlane[cord.Y + y][cord.X + x] != 'p') && (DisasterPlane[cord.Y + y][cord.X + x] != 'h'))
			{
				switch (disasters[i]->getdirection())
				{
				case 'W':
				case 'S':
					if ((DisasterPlane[cord.Y][cord.X + 1] == 'p') || (DisasterPlane[cord.Y][cord.X + 1] == 'h'))
					{
						disasters[i]->changeDirection('D');
						break;
					}
					else if ((DisasterPlane[cord.Y][cord.X - 1] == 'p') || (DisasterPlane[cord.Y][cord.X - 1] == 'h'))
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
					if ((DisasterPlane[cord.Y + 1][cord.X] == 'p') || (DisasterPlane[cord.Y + 1][cord.X] == 'h'))
					{
						disasters[i]->changeDirection('S');
						break;
					}
					else if ((DisasterPlane[cord.Y - 1][cord.X] == 'p') || (DisasterPlane[cord.Y - 1][cord.X] == 'h'))
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
			disasters[i]->reaction(player, map[cord.Y][cord.X]);
			DisasterPlane[cord.Y][cord.X] = disasters[i]->geticon();
		}
	}
}