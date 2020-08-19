#include "Player.h"

int Player::life = 5;

Player::Player() {
	c.X = 2;
	c.Y = 5;
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

void Player::moveLEFT()
{
	c.X--;
}

void Player::moveRIGHT()
{
	c.X++;
}

void Player::moveUP()
{
	c.Y--;
}

void Player::moveDOWN()
{
	c.Y++;
}