#include "Player.h"

int Player::life = 5;

Player::Player() :
	charColor(0x4C),
	model("  "),
	inventory{ },
	select(0),
	speed(1),
	icon('P'),
	facing('W')
{
	c.X = 2;
	c.Y = 2;
};

Player::~Player()
{

}

char Player::getIcon()
{
	return icon;
}

WORD Player::getColor()
{
	return charColor;
}

std::string Player::getmodel()
{
	return model;
}

int Player::getX()
{
	return c.X;
}

int Player::getY()
{
	return c.Y;
}

int Player::getspeed()
{
	return speed;
}

int Player::getlife()
{
	return life;
}

int Player::getselect()
{
	return select;
}

char Player::getFacing()
{
	return facing;
}


Item* Player::getInventory(int slot)
{
	return inventory[slot];
}

Item* Player::getSelected()
{
	return inventory[select];
}

void Player::setInventory(int slot, char item, int value)
{
	for (int i = 0; i < value; i++)
	{
		switch (item)
		{
		case '0':
			inventory[slot] = new HealthPotion;
			inventory[slot]->increase();
			break;
		case ' ':				//value needs to be at least 1
			delete inventory[slot];
			inventory[slot] = nullptr;
			break;
		}
	}
}

void Player::addInventory(char item)
{
	bool added = false;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i]) 
		{
			switch (inventory[i]->GetType())
			{
			case Item::ITEM_TYPE::HP:
				if (item == inventory[i]->getsymbol() && inventory[i]->getamt() < inventory[i]->getmaxstacks())
				{
					inventory[i]->increase();
					added = true;
				}
				break;
			case Item::ITEM_TYPE::KEY:
				if (item == inventory[i]->getsymbol())
				{
					inventory[i]->increase();
					added = true;
				}
				break;
			case Item::ITEM_TYPE::KEYCARD:
				if (item == inventory[i]->getsymbol())
				{
					inventory[i]->increase();
					added = true;
				}
				break;
			}
		}
	}
	if (!added)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!inventory[i] && !added)
			{
				switch (item)
				{
				case '0':
					inventory[i] = new HealthPotion;
					break;
				case 'k':
					inventory[i] = new Key;
					break;
				case 'C':
					inventory[i] = new Keycard;
					break;
				}
				inventory[i]->increase();
				added = true;
			}
		}
	}
}

void Player::nextItem()
{
	if (select < 3)
	{
		select++;
	}
	else
	{
		select = 0;
	}
}

void Player::useItem(char front, int doortype, bool isActive)
{
	if (inventory[select])
	{
		switch (inventory[select]->GetType())
		{
		case Item::ITEM_TYPE::HP:
			increaselife();
			inventory[select]->decrease();
			break;
		case Item::ITEM_TYPE::KEY:
			if (front == 'D' && doortype == 1 && isActive == true) {
				inventory[select]->decrease();
			}
			break;
		case Item::ITEM_TYPE::KEYCARD:
			if (front == 'D' && doortype == 2 && isActive == true) {
				inventory[select]->decrease();
			}
			break;
		}
		
		if (inventory[select]->getamt() == 0)
		{
			delete inventory[select];
			inventory[select] = nullptr;
		}
	}
}

void Player::setmodel(char direction)
{
	std::ostringstream ss;
	switch (direction)
	{
	case 'W':
		ss << char(223) << char(223);
		facing = 'W';
		break;
	case 'S':
		ss << char(220) << char(220);
		facing = 'S';
		break;
	case 'A':
		ss << char(219) << char(255);
		facing = 'A';
		break;
	case 'D':
		ss << char(255) << char(219);
		facing = 'D';
		break;
	}

	model = ss.str();
}

void Player::setX(int x)
{
	c.X = x;
}

void Player::setY(int y)
{
	c.Y = y;
}

void Player::increaselife()
{
	if (life < 5)
	{
		life++;	
	}
}

void Player::decreaselife()
{
	life--;
}

void Player::interact()
{

}

void Player::setLife(int x)
{
	life = x;
}

void Player::moveLEFT()
{
	if (getX() > 23 && getX() <= 113)
	{
		c.X -= speed;
	}
	else if (getX() <= 23 || getX() >= 113)
	{
		c.X -= speed;
	}
}

void Player::moveRIGHT()
{
	if (getX() < 113 && getX() >= 23)
	{
		c.X += speed;
	}
	else if (getX() <= 23 || getX() >= 113)
	{
		c.X += speed;
	}
}

void Player::moveUP()
{
	if (getY() > 21 && getY() <= 114)
	{
		c.Y -= speed;
	}
	else if (getY() <= 21 || getY() > 114)
	{
		c.Y -= speed;
	}
}

void Player::moveDOWN()
{
	if (getY() >= 21 && getY() <= 113)
	{
		c.Y += speed;
	}
	else if (getY() < 21 || getY() > 113)
	{
		c.Y += speed;
	}
}


