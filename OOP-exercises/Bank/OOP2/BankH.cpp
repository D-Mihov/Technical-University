#include "stdafx.h"
#include "BankH.h"
#include "BankClientH.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Fibonacci.h"
using namespace std;


BankH::BankH(int max)
{
	Fnumber = *new Fibonacci();
	maxNumberOfClients = Fnumber.Set(max);
	current = 0;
	bank = new BankClientH[maxNumberOfClients];
}

BankH::~BankH()
{
	delete[]bank;
}

void BankH::Append(BankClientH client)
{
	if (current<maxNumberOfClients)
	{
		bank[current] = client;
		
	}
	else
	{
		BankClientH* temp = new BankClientH[maxNumberOfClients];
		temp = bank;
		maxNumberOfClients = Fnumber.Set(maxNumberOfClients);
		bank = new BankClientH[maxNumberOfClients];
		for (int i = 0; i < current; i++)
		{
			bank[i] = temp[i];
		}
		bank[current] = client;
	}
	current++;
}

void BankH::Delete(int clientNumber)
{
	for (int i = 0; i < current; i++)
	{
		if (bank[i].getClientNumber() == clientNumber)
		{
			if (current == maxNumberOfClients - 1)
			{
				bank[current] = *new BankClientH("", "", 0);
			}
			else
			{
				for (int j = i; j < current; j++)
				{
					bank[j] = bank[j++];
				}
				current--;
			}
		}
	}
}