#include "stdafx.h"
#include "GroupTicket.h"

bool hasDiscount = false;

GroupTicket::GroupTicket()
{
	groupTicketPrice = 0;
	visitorsCount = 0;
}

GroupTicket::GroupTicket(int _visitorsCount, int _rowNumber, int _seatNumber, char *_projectDate, double _price, Film *_film) :
Ticket(_rowNumber, _seatNumber, _projectDate, _price, _film)
{
	visitorsCount = _visitorsCount;
	groupTicketPrice = _price;
	groupTicketPrice *= visitorsCount;
	if (visitorsCount > 10 && visitorsCount <= 20)
	{
		groupTicketPrice -= groupTicketPrice * 0.1;
		hasDiscount = true;
	}
	else if (visitorsCount > 20 && visitorsCount <= 25)
	{
		groupTicketPrice -= groupTicketPrice * 0.2;
		hasDiscount = true;
	}
}

GroupTicket::~GroupTicket()
{
}


int GroupTicket::GetVisitorsCount()
{
	return visitorsCount;
}

void GroupTicket::print()
{
	cout << "Visitors Count: " << visitorsCount << endl;
	Ticket::print();
	if (hasDiscount)
	{
		cout << "Discount Group Ticket Price: " << groupTicketPrice << endl;
	}
	else
	{
		cout << "Group Ticket Price: " << groupTicketPrice << endl;
		cout << "Discount Ticket Price: No" << endl;
	}
}