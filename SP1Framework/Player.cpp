#include "Player.h"

int Player::life = 5;

Player::Player() :
	charColor(0x4C),
	model("  "),
	inventory{ },
	speed(1),
	Active(false),
	icon('P'),
	facing('W')
{
	c.X = 2;
	c.Y = 2;
};

Player::~Player()
{

}

void Player::changeActive()
{
	Active = !Active;
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

char Player::getFacing()
{
	return facing;
}

bool Player::is_Active()
{
	return Active;
}

Item* Player::getInventory(int slot)
{
	return inventory[slot];
}

void Player::addInventory(char item)
{
	bool added = false;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i] && !added)
		{
			switch (item)
			{
			case '0':
				inventory[i] = new HealthPotion;
				inventory[i]->increase();
				added = true;
				break;
			}
		}
		else if(inventory[i])
		{
			if (inventory[i]->GetType() == Item::ITEM_TYPE::HP && inventory[i]->getamt() < inventory[i]->getmaxstacks())
			{
				inventory[i]->increase();
				added = true;
			}
			
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
	life++;
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


