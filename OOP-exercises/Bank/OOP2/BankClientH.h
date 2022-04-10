#pragma once
#include "AccountInfoH.h"
class BankClientH

{
private:
	char firstName[20];
	char lastName[20];
	int clientNumber;
	int currentNumberOfBankAccounts;
	AccountInfoH accountInfo[10];
	int CheckForAcc(AccountInfoH& accToRemove);
public:
	int getClientNumber();
	BankClientH();
	BankClientH(const char* firstName, const char* lastName, int clientNumber);
	bool AddAccount(AccountInfoH accInfo);
	bool RemoveAccount(AccountInfoH& accInfo);
	int FindByIBAN(const char* searchIBAN);
	void AddBalance(double balance, const char* getIBAN);
	double AllAccountsBalance();
	void PrintClient();
	void operator= (BankClientH& newAcc);
};
