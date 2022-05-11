#pragma once
#include "Ticket.h"
#include "GroupTicket.h"
#include "StudentTicket.h"

class Cinema
{
	int seats[10][16];
	int soldTickets;
public:
	Cinema();
	~Cinema();
	void sellTicket(Ticket *ticket);
	void sellStudentTicket(StudentTicket *tudentTicket);
	void sellGroupTicket(GroupTicket *groupTicket);
	void print();
};

