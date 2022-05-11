#pragma once
#include "Film.h"

class Ticket
{
	int rowNumber;
	int seatNumber;
	char projectDate[30];
	Film *film;
	double price;
public:
	Ticket();
	Ticket(int _rowNumber, int _seatNumber, char *_projectDate, double _price, Film *_film);
	~Ticket();
	int GetRowNumber();
	int GetSeatNumber();
	virtual void print();
};

