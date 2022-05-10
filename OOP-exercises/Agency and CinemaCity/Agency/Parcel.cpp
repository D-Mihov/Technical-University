#include "stdafx.h"
#include "Parcel.h"


Parcel::Parcel()
{
	water = false;
	electricity = false;
	closeToRoad = false;
}

Parcel::Parcel(bool water, bool electricity, bool closeToRoad, char* address, char* owner, double price, int area) :Estate(address, owner, price, area)
{
	this->water = water;
	this->electricity = electricity;
	this->closeToRoad = closeToRoad;
}

Parcel::~Parcel()
{
}

void Parcel::print()
{
	if (water)
	{
		cout << "Water: Yes" << endl;
	}
	else
	{
		cout << "Water: No" << endl;
	}
	if (electricity)
	{
		cout << "Electricity: Yes" << endl;
	}
	else
	{
		cout << "Electricity: No" << endl;
	}
	if (closeToRoad)
	{
		cout << "Close to Road: Yes" << endl;
	}
	else
	{
		cout << "Close to Road: No" << endl;
	}
	Estate::print();
}
