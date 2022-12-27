#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	this->setName("");
	this->setAge(0);
	this->setSalary(0.0);
}

Player::Player(char* name, int age, double salary)
{
	this->setName(name);
	this->setAge(age);
	this->setSalary(salary);
}


Player::~Player()
{
}

Player& Player::operator=(Player& player)
{
	this->setName(player.getName());
	this->setAge(player.getAge());
	this->setSalary(player.getSalary());
	return *this;
}


void Player::setName(char* name)
{
	strcpy_s(this->playerName, 20, name);
}

void Player::setAge(int age)
{
	this->age = age;
}

void Player::setSalary(double salary)
{
	this->salary = salary;
}

char* Player::getName()
{
	return this->playerName;
}

int Player::getAge()
{
	return this->age;
}

double Player::getSalary()
{
	return this->salary;
}

bool Player::operator==(Player& player1)
{
	if (strcmp(player1.getName(), this->playerName) == 0 && player1.getAge() == this->age && player1.getSalary() == this->salary)
	{
		return true;
	}
	else
	{
		return false;
	}
}