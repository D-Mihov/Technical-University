// Agency.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	Agency agency;
	Estate estate("Hristo Botev 13", "Stoyan Yorukov", 50000, 100);
	Apartment ap(4, 5, "Odrin 23", "Daniel Mihov", 100000, 80);
	House house(8, 2, 100, "Perushtitsa 54", "Petur Mlekarov", 300000, 150);
	Parcel parcel(true, true, true, "Han Krum 7", "Filip Kardjaliiski", 45000.50, 200);
	Estate *est;
	agency.addEstate(&ap);
	agency.addEstate(&estate);
	agency.addEstate(&house);
	agency.addEstate(&parcel);
	agency.searchByPrice(0, 99999);
	cout << "------------------------------------------" << endl;
	agency.removeEstate(&parcel);
	agency.print();
	return 0;
}

