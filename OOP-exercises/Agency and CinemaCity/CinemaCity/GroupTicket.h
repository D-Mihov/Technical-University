#pragma once
#include "Ticket.h"
class GroupTicket :
	public Ticket
{
	double groupTicketPrice;
	int visitorsCount;
public:
	GroupTicket();
	GroupTicket(int _visitorsCount, int _rowNumber, int _seatNumber, char *_projectDate, double _price, Film *_film);
	~GroupTicket();
	int GetVisitorsCount();
	void print();
};

