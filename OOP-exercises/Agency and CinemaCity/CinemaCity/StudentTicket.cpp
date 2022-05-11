#include "stdafx.h"
#include "StudentTicket.h"


StudentTicket::StudentTicket()
{
	studentTicketPrice = 0;
}

StudentTicket::StudentTicket(int _rowNumber, int _seatNumber, char *_projectDate, double _price, Film *_film) :Ticket(_rowNumber, _seatNumber, _projectDate, _price, _film)
{
	studentTicketPrice = _price - _price * 0.2;
}

StudentTicket::~StudentTicket()
{
}


void StudentTicket::print()
{
	Ticket::print();
	cout << "Discount Ticket Price: " << studentTicketPrice << endl;
}