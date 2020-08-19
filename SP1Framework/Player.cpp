#include "Player.h"

int Player::life = 5;

Player::Player()
{
	p_screen.X = 23;
	p_screen.Y = 21;
	p_map.X = 23;
	p_map.Y = 21;
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
	return (p_screen.X + p_map.X);
}

int Player::getY()
{
	return (p_screen.Y + p_map.Y);
}

int Player::getscreenX()
{
	return p_screen.X;
}

int Player::getscreenY()
{
	return p_screen.Y;
}

int Player::getmapX()
{
	return p_map.X;
}

int Player::getmapY()
{
	return p_map.Y;
}

int Player::getlife()
{
	return life;
}

bool Player::is_Active()
{
	return Active;
}

void Player::moveLEFT()
{
	if (getX() > 23 && getX() <= 113)
	{
		p_map.X--;
	}
	else if (getX() <= 23 || getX() >= 113)
	{
		p_screen.X--;
	}
}

void Player::moveRIGHT()
{
	if (getX() < 113 && getX() >= 23)
	{
		p_map.X++;
	}
	else if (getX() <= 23 || getX() >= 113)
	{
		p_screen.X++;
	}
}

void Player::moveUP()
{
	if (getY() > 21 && getY() <= 114)
	{
		p_map.Y--;
	}
	else if (getY() <= 21 || getY() > 114)
	{
		p_screen.Y--;
	}
}

void Player::moveDOWN()
{
	if (getY() >= 21 && getY() <= 113)
	{
		p_map.Y++;
	}
	else if (getY() < 21 || getY() > 113)
	{
		p_screen.Y++;
	}
}