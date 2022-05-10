#include "stdafx.h"
#include "House.h"


House::House()
{
	rooms = 0;
	floorsNumber = 0;
	yardArea = 0;
}

House::House(int rooms, int floorsNumber, int yardArea, char* address, char* owner, double price, int area) :Estate(address, owner, price, area)
{
	this->rooms = rooms;
	this->floorsNumber = floorsNumber;
	this->yardArea = yardArea;
}

House::~House()
{
}

void House::print()
{
	cout << "Rooms: " << rooms << endl;
	cout << "Floors Number: " << floorsNumber << endl;
	cout << "Yard Area: " << yardArea << endl;
	Estate::print();
}