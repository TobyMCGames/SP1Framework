#include "Player.h"

int Player::life = 5;

Player::Player()
{
	c.X = 0;
	c.Y = 0;
	Active = false;
	facing = 'W';
}

Player::~Player()
{

}

void Player::changeActive()
{
	Active = !Active;
}

int Player::getX()
{
	return c.X;
}

int Player::getY()
{
	return c.Y;
}



int Player::getlife()
{
	return life;
}

bool Player::is_Active()
{
	return Active;
}

void Player::setX(int x)
{
	c.X = x;
}

void Player::setY(int y)
{
	c.Y = y;
}

void Player::moveLEFT()
{
	if (getX() > 23 && getX() <= 113)
	{
		c.X--;
	}
	else if (getX() <= 23 || getX() >= 113)
	{
		c.X--;
	}
}

void Player::moveRIGHT()
{
	if (getX() < 113 && getX() >= 23)
	{
		c.X++;
	}
	else if (getX() <= 23 || getX() >= 113)
	{
		c.X++;
	}
}

void Player::moveUP()
{
	if (getY() > 21 && getY() <= 114)
	{
		c.Y--;
	}
	else if (getY() <= 21 || getY() > 114)
	{
		c.Y--;
	}
}

void Player::moveDOWN()
{
	if (getY() >= 21 && getY() <= 113)
	{
		c.Y++;
	}
	else if (getY() < 21 || getY() > 113)
	{
		c.Y++;
	}
}


