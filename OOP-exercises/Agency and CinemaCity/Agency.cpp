#include "stdafx.h"
#include "Agency.h"
#include <string.h>
#include <stdlib.h>

Agency::Agency()
{
	strcpy_s(agencyName, 20, "");
	estatesCount = 0;
}


Agency::~Agency()
{
}


void Agency::addEstate(Estate *estate)
{
	if (estatesCount < 100) 
	{
		estates[estatesCount] = estate;
		estatesCount++;
	}
}

void Agency::removeEstate(Estate *estate)
{
	for (int i = 0; i < estatesCount; i++)
	{
		if (estates[i] == estate)
		{
			estates[i] = estates[estatesCount - 1];
			estates[estatesCount - 1] = NULL;
			estatesCount--;
			break;
		}
	}
}


void Agency::searchByPrice(double min, double max)
{
	for (int i = 0; i < estatesCount; i++)
	{
		if (estates[i]->getPrice() >= min && estates[i]->getPrice() <= max)
		{
			estates[i]->print();
		}
	}
}

int compareByPrice(const void *price1, const void *price2)
{
	if ((*(Estate**)price1)->getPrice() < (*(Estate**)price2)->getPrice())
	{
	return -1;
	}
	else if ((*(Estate**)price1)->getPrice() > (*(Estate**)price2)->getPrice())
	{
	return 1;
	}
	else if ((*(Estate**)price1)->getPrice() == (*(Estate**)price2)->getPrice())
	{
	return 0;
	}
}


void Agency::print()
{
	qsort(estates, estatesCount, sizeof(estates[0]), compareByPrice);
	for (int i = 0; i < estatesCount; i++)
	{
		estates[i]->print();
	}
}
