#pragma once
#include "BankClientH.h"
#include "stdafx.h"
#include "Fibonacci.h"

class BankH
{
private:
	BankClientH* bank;
	int maxNumberOfClients;
	int current;
	Fibonacci Fnumber;
public:
	BankH(int max);
	~BankH();
	void Append(BankClientH client);
	void Delete(int clientNumber);
};

