#include "Player.h"

int Player::life = 5;

Player::Player() {
	location[0] = 2;
	location[1] = 5;
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
	return location[0];
}

int Player::getY()
{
	return location[1];
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
	location[0]--;
}

void Player::moveRIGHT()
{
	location[0]++;
}

void Player::moveUP()
{
	location[1]--;
}

void Player::moveDOWN()
{
	location[1]++;
}