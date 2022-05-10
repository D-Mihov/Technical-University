#include "stdafx.h"
#include "Estate.h"
#include <string.h>

Estate::Estate()
{
	strcpy_s(address, 20,  "");
	strcpy_s(owner, 20, "");
	price = 0;
	area = 0;
}

Estate::Estate(char* address, char* owner, double price, int area)
{
	strcpy_s(this->address, 20, address);
	strcpy_s(this->owner, 20, owner);
	this->price = price;
	this->area = area;
}

Estate::~Estate()
{
}

double Estate::getPrice()
{
	return price;
}

void Estate::print()
{
	cout << "Address: " << address << endl;
	cout << "Owner: " << owner << endl;
	cout << "Price: " << price << endl;
	cout << "Area: " << area << endl;
	cout << " " << endl;
}