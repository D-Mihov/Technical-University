#include "stdafx.h"
#include "BankClientH.h"
#include <string.h>
#include <iostream>
using namespace std;

BankClientH::BankClientH()
{
	strcpy_s(this->firstName, 20, "");
	strcpy_s(this->lastName, 20, "");
	this->currentNumberOfBankAccounts = 0;
	clientNumber = 0;
}

BankClientH::BankClientH(const char* firstName, const char* lastName, int clientNum)
{
	strcpy_s(this->firstName, 20, firstName);
	strcpy_s(this->lastName, 20, lastName);
	clientNumber = clientNum;
	this->currentNumberOfBankAccounts = 0;
}

bool BankClientH::AddAccount(AccountInfoH accInfo){
	if (currentNumberOfBankAccounts < 10)
	{
		this->accountInfo[this->currentNumberOfBankAccounts] = accInfo;
		this->currentNumberOfBankAccounts++;
		return true;
	}
	return false;
}

bool BankClientH::RemoveAccount(AccountInfoH& accInfo){
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		if (this->accountInfo[i] == accInfo)
		{
			for (int j = i; j < currentNumberOfBankAccounts; j++)
			{
				this->accountInfo[j] = this->accountInfo[j++];

			}
			this->currentNumberOfBankAccounts--;
			return true;
		}
	}
	return false;
}

int BankClientH::FindByIBAN(const char* searchIBAN){
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		if (strcmp(searchIBAN, this->accountInfo[i].getIBAN()) == 0)
		{
			return i;
		}
	}
	return -1;
}

void BankClientH::AddBalance(double balance, const char* getIBAN){
	int position = FindByIBAN(getIBAN);
	if (position != -1)
	{
		this->accountInfo[position].AddAmount(balance);
	}
}

double BankClientH::AllAccountsBalance(){
	double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += this->accountInfo[i].getBalance();
	}
	return sum;
}

void BankClientH::PrintClient(){
	cout << this->firstName << endl;
	cout << this->lastName << endl;
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		cout << this->accountInfo[i].getAccountType() << endl;
		cout << this->accountInfo[i].getIBAN() << endl;
		cout << this->accountInfo[i].getBalance() << endl;
	}
}

void BankClientH::operator= (BankClientH& newAcc){
	strcpy_s(firstName, 20, newAcc.firstName);
	strcpy_s(lastName, 20, newAcc.lastName);
	clientNumber = newAcc.clientNumber;
}

int BankClientH::getClientNumber()
{
	return clientNumber;
}