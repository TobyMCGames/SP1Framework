#include "Map.h"

COORD offset;

Map::Map() :
	x(135),
	y(135),
	x_change(0),
	y_change(0),
	fixed_update(0),
	map{ },
	DisasterPlane{ },
	earthquakeI(false),
	tornadoI(false),
	tsunamiI(false),
	volcanoI(false),
	disasters { },
	EQArray{ },
	VArray{ },
	TArray{ }
{
	for (int row = 0; row < x; row++) {
		for (int col = 0; col < y; col++) {
			map[row][col] = ' ';
			DisasterPlane[row][col] = ' ';
		}
	}
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

	for (int i = 0; i < 50; i++)
	{
		VArray[i] = nullptr;
	}

	for (int i = 0; i < 500; i++)
	{
		TArray[i] = nullptr;
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
	case 'S': //Silver Wall
	case 'W': //Wall
	case '0': //HP Pot
	case 'k': //key
	case 'C':
	case 'G': //Endgame stuff
	case 'D':
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
			if (EQArray[i] != nullptr && EQArray[i]->getX() == anotherP.getX() + x_change && EQArray[i]->getY() == anotherP.getY() + y_change && EQArray[i]->getState() == true)
			{
				return true;
			}
		}
		break;
	case 'F':
		for (int i = 0; i < 50; i++)
		{
			if (VArray[i] != nullptr && VArray[i]->getX() == anotherP.getX() + x_change && VArray[i]->getY() == anotherP.getY() + y_change && VArray[i]->getState() == true)
			{
				player.decreaselife();
			}
		}
		break;
	case 'M':
		for (int i = 0; i < 500; i++)
		{
			if (TArray[i] != nullptr && TArray[i]->getX() == anotherP.getX() + x_change && TArray[i]->getY() == anotherP.getY() + y_change && TArray[i]->getState() == true)
			{
				return true;
			}
		}
		break;
	}
	return false;
}

char Map::interact(Player& player)
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
	case 'G':
		return 'G';
	case 'D':
		int x = player.getX() + x_change, col = player.getX() + x_change;
		int y = player.getY() + y_change, row = player.getY() + y_change;
		while (true)
		{
			while (true)
			{
				map[row][col] = ' ';
				if (map[row][col - 1] == 'D')
				{
					col--;
				}
				else
				{
					col = x;
					break;
				}
			}
			while (true)
			{
				map[row][col] = ' ';
				if (map[row][col + 1] == 'D')
				{
					col++;
				}
				else
				{
					col = x;
					break;
				}
			}
			if (map[row - 1][col] == 'D') {
				row--;
			}
			else
			{
				row = y;
				break;
			}
		}
		while (true)
		{
			while (true)
			{
				map[row][col] = ' ';
				if (map[row][col - 1] == 'D')
				{
					col--;
				}
				else
				{
					col = x;
					break;
				}
			}
			while (true)
			{
				map[row][col] = ' ';
				if (map[row][col + 1] == 'D')
				{
					col++;
				}
				else
				{
					col = x;
					break;
				}
			}
			if (map[row + 1][col] == 'D') {
				row++;
			}
			else
			{
				row = y;
				break;
			}
		}
	}
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
	std::string path = "Maps\\" + anothermap;
	std::ifstream f;
	f.open(path);
	std::string line;
	std::string cell;
	int EQidx = 0;
	int Vidx = 0;
	int Tidx = 0;
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
					case'M':
						map[row][col] = cell[i];
						TArray[Tidx] = new Tsunami;
						TArray[Tidx]->setCOORD(col, row);
						Tidx++;
						tsunamiI = true;
						break;
					case 'B':
						map[row][col] = ' ';
						disasters[Didx] = new Boulder(col, row, 'B');
						DisasterPlane[row][col] = 'B';
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
					case '0':		//HP Potion
						map[row][col] = '0';
						break;
					case 'k':
						map[row][col] = 'k';
						break;
					case 'C':
						map[row][col] = 'C';
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
					case 'U':
						disasters[Didx]->changeDirection('W');
						break;
					case 'D':
						disasters[Didx]->changeDirection('S');
						break;
					case 'L':
						disasters[Didx]->changeDirection('A');
						break;
					case 'R':
						disasters[Didx]->changeDirection('D');
						break;
					case 'Q':
						TArray[(Tidx - 1)]->toggle();
						break;
					}
					Didx++;
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
	int T_tiles = 0;
	int Tidx_temp = 0;
	int Tidx_active[500];
	for (int i = 0; i < 500; i++) {
		Tidx_active[i] = -1;
		if (TArray[i] != nullptr) {
			T_tiles++;
		}
	}
	fixed_update += dt;
	if (fixed_update >= 0.16 * 1) 
	{
		if (earthquakeI) //EarthQuake Tiles
		{
			for (int i = 0; i < 5; i++)
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
		}

		if (volcanoI) //Volcano Tiles
		{
			for (int j = 0; j < 5; j++)
			{
				Vidx = rand() % 50;
				while (VArray[Vidx] == nullptr)
				{
					Vidx = rand() % 50;
				}

				if (VArray[Vidx]->getState() != true)
				{
					VArray[Vidx]->toggle();
					fixed_update = 0;
				}
			}
		}

		if (tsunamiI) //Tsunami Tiles
		{
			for (int k = 0; k < 5; k++)
			{
				for (int Tidx = 0; Tidx < T_tiles; Tidx++)
				{
					if (TArray[Tidx]->getState() == true && ((std::find(Tidx_active, Tidx_active+500, Tidx)) == Tidx_active+500))
					{
						Tidx_temp = Tidx;
						Tidx_active[std::distance(Tidx_active, std::find(Tidx_active, Tidx_active + 500, -1))] = Tidx;
						break;
					}
				}

				for (int Tidx = 0; Tidx < T_tiles; Tidx++)
				{
					if (TArray[Tidx]->getState() == false &&
						((((TArray[Tidx]->getX() + 1) == TArray[Tidx_temp]->getX()) && (TArray[Tidx]->getY() == TArray[Tidx_temp]->getY())) ||
							((TArray[Tidx]->getX() == TArray[Tidx_temp]->getX()) && ((TArray[Tidx]->getY() + 1) == TArray[Tidx_temp]->getY())) ||
							(((TArray[Tidx]->getX() - 1) == TArray[Tidx_temp]->getX()) && (TArray[Tidx]->getY() == TArray[Tidx_temp]->getY())) ||
							((TArray[Tidx]->getX() == TArray[Tidx_temp]->getX()) && ((TArray[Tidx]->getY() - 1) == TArray[Tidx_temp]->getY()))))
					{
						TArray[Tidx]->toggle();
						fixed_update = 0;
						break;
					}
				}
			}
		}
		//The rest of the disasters
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
				case 'M':
					for (int k = 0; k < 500; k++)
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
					anotherC.writeToBuffer(45 + j * 2, i, "  ", 0xB0);
					break;
			}	
			switch (DisasterPlane[i + offset.Y][j + offset.X])
			{
			case 'B':
				anotherC.writeToBuffer(45 + j * 2, i, "  ", 0x6F);
				break;
			case 'T':
				anotherC.writeToBuffer(45 + j * 2, i, "  ", 0xBA);
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
			if (disasters[i]->reaction(player, map[cord.Y + y][cord.X + x]) == true)
			{
				DisasterPlane[cord.Y][cord.X] = 'p';
				disasters[i]->BTSpawner();
				cord = disasters[i]->getcord();
				DisasterPlane[cord.Y][cord.X] = disasters[i]->geticon();
			}
		}
	}
}