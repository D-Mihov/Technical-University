#pragma once
#include "Estate.h"
class Apartment :
	public Estate
{
	int rooms;
	int floor;
public:
	Apartment();
	Apartment(int rooms, int floor, char* address, char* owner, double price, int area);
	~Apartment();
	void print();
};

