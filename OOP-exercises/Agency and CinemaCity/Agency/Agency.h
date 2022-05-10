#pragma once
#include "Estate.h"

class Agency
{
	char agencyName[20];
	Estate* estates[100];
	int estatesCount;
public:
	Agency();
	~Agency();
	void addEstate(Estate* estate);
	void removeEstate(Estate* estate);
	void searchByPrice(double minPrice, double maxPrice);
	void print();
};

