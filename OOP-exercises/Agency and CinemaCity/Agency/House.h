#pragma once
#include "Estate.h"
class House :
	public Estate
{
	int rooms;
	int floorsNumber;
	int yardArea;
public:
	House();
	House(int rooms, int floorsNumber, int yardArea, char* address, char* owner, double price, int area);
	~House();
	void print();
};

