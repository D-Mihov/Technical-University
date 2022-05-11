#pragma once
#include "Ticket.h"

class StudentTicket :
	public Ticket
{
	double studentTicketPrice;
public:
	StudentTicket();
	StudentTicket(int _rowNumber, int _seatNumber, char *_projectDate, double _price, Film *_film);
	~StudentTicket();
	void print();
};

