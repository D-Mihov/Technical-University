#pragma once
#include <algorithm>
class Player
{
	char playerName[20];
	int age;
	double salary;
public:
	Player();
	Player(char* name, int age, double salary);
	~Player();
	Player& operator=(Player& player);
	char* getName();
	int getAge();
	double getSalary();
	void setName(char* name);
	void setAge(int age);
	void setSalary(double salary);
	bool operator==(Player& player1);
};

/*bool operator==(Player& player1, Player& player2) 
{
	if (strcmp(player1.getName(), player2.getName()) == 0 && player1.getAge() == player2.getAge() && player1.getSalary() == player2.getSalary())
	{
		return true;
	}
	else
	{
		return false;
	}
}*/
