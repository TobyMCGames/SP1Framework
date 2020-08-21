#include "Player.h"

int Player::life = 5;

Player::Player() :
	charColor(0x4C),
	model("  "),
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

bool Player::is_Active()
{
	return Active;
}

void Player::setmodel(char direction)
{
	std::ostringstream ss;
	switch (direction)
	{
	case 'W':
		ss << char(223) << char(223);
		break;
	case 'S':
		ss << char(220) << char(220);
		break;
	case 'A':
		ss << char(219) << char(255);
		break;
	case 'D':
		ss << char(255) << char(219);
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


