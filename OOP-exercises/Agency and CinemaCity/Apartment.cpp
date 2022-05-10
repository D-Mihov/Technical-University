#include "stdafx.h"
#include "Apartment.h"


Apartment::Apartment()
{
	rooms = 0;
	floor = 0;
}

Apartment::Apartment(int rooms, int floor, char* address, char* owner, double price, int area) :Estate(address, owner, price, area)
{
	this->rooms = rooms;
	this->floor = floor;
}

Apartment::~Apartment()
{
}

void Apartment::print()
{
	cout << "Rooms: " << rooms << endl;
	cout << "Floor: " << floor << endl;
	Estate::print();
}