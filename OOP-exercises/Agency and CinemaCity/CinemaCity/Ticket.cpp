#include "stdafx.h"
#include "Ticket.h"
#include <string.h>

Ticket::Ticket()
{
	rowNumber = 0;
	seatNumber = 0;
	strcpy_s(projectDate, 30, "");
	price = 0;
}


Ticket::Ticket(int _rowNumber, int _seatNumber, char *_projectDate, double _price, Film *_film)
{
	rowNumber = _rowNumber;
	seatNumber = _seatNumber;
	strcpy_s(projectDate, 30, _projectDate);
	price = _price;
	film = _film;
}

Ticket::~Ticket()
{
}


int Ticket::GetRowNumber()
{
	return rowNumber;
}

int Ticket::GetSeatNumber()
{
	return seatNumber;
}

void Ticket::print()
{
	cout << "Row Number: " << rowNumber << endl;
	cout << "Seat Number: " << seatNumber << endl;
	cout << "Project Date: " << projectDate << endl;
	cout << "Ticket Price: " << price << endl;
}