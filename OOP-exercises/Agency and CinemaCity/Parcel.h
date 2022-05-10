#pragma once
#include "Estate.h"
class Parcel :
	public Estate
{
	bool water;
	bool electricity;
	bool closeToRoad;
public:
	Parcel();
	Parcel(bool water, bool electricity, bool closeToRoad, char* address, char* owner, double price, int area);
	~Parcel();
	void print();
};

