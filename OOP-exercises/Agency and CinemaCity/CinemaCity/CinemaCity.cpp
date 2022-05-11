// CinemaCity.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Cinema cinema;
	Film film("Doctor Strange", "06/05/2022", "Fantasy", 20);
	Ticket ticket(0, 3, "06/05/2022", 20, &film);
	StudentTicket studentTicket(2, 3, "07/05/2022", 20, &film);
	GroupTicket groupTicket(22, 2, 8, "06/05/2022", 20, &film);
	ticket.print();
	cinema.sellTicket(&ticket);
	studentTicket.print();
	cinema.sellStudentTicket(&studentTicket);
	groupTicket.print();
	cinema.sellGroupTicket(&groupTicket);
	return 0;
}

