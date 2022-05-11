#include "stdafx.h"
#include "Cinema.h"

Cinema::Cinema()
{
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 16; col++)
		{
			seats[row][col] = 0;
		}
	}
	soldTickets = 0;
}


Cinema::~Cinema()
{
}


void Cinema::sellTicket(Ticket *ticket)
{
	int row = ticket->GetRowNumber();
	int col = ticket->GetSeatNumber();
	if (seats[row][col] != 1)
	{
		seats[row][col] = 1;
		cout << "Seat reserved!\n" << endl;
		Cinema::print();
	}
	else
	{
		cout << "This seat is taken!\n" << endl;
	}
}

void Cinema::sellStudentTicket(StudentTicket *studentTicket)
{
	int row = studentTicket->GetRowNumber();
	int col = studentTicket->GetSeatNumber();
	if (seats[row][col] != 1)
	{
		seats[row][col] = 1;
		cout << "Seat reserved!\n" << endl;
		Cinema::print();
	}
	else
	{
		cout << "This seat is taken!\n" << endl;
	}
}

void Cinema::sellGroupTicket(GroupTicket *groupTicket)
{
	bool isFree = true;
	int row = groupTicket->GetRowNumber();
	int seat = groupTicket->GetSeatNumber();
	int visitorsCount = groupTicket->GetVisitorsCount();
	int seatsToReserve = 0;
	for (int firstSeat = seat; firstSeat < seat + visitorsCount; firstSeat++)
	{
		if (seatsToReserve <= visitorsCount)
		{
			if (firstSeat <= 16)
			{
				if (seats[row][firstSeat] != 0)
				{
					isFree = false;
					break;
				}
				else
				{
					seatsToReserve++;
				}
			}
			else
			{
				row++;
				firstSeat = -1;
			}
		}
		else
		{
			break;
		}
	}
	
	seatsToReserve = 0;
	row = groupTicket->GetRowNumber();

	if (isFree)
	{
		for (int firstSeat = seat; firstSeat < seat + visitorsCount; firstSeat++)
		{
			if (seatsToReserve <= visitorsCount)
			{
				if (firstSeat <= 16)
				{
					seats[row][firstSeat] = 1;
					seatsToReserve++;

				}
				else
				{
					row++;
					firstSeat = -1;
				}
			}
			else
			{
				break;
			}
		}
		cout << "Seats reserved!\n" << endl;
		Cinema::print();
	}
	else
	{
		cout << "One or more seats are taken!\n" << endl;
	}
}

void Cinema::print()
{
	printf_s("      ----------------------------------\n\n");
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 16; col++)
		{
			printf_s("%d  ", seats[row][col]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}