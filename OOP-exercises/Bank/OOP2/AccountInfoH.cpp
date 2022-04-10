#include "stdafx.h"
#include "AccountInfoH.h"
#include <string.h>

AccountInfoH::AccountInfoH(){
	strcpy_s(this->accountType, 20, "accType");
	strcpy_s(this->IBAN, 23, "iban");
	this->balance = 0;
}

AccountInfoH::AccountInfoH(const char* accountType, const char* IBAN, double balance){
	strcpy_s(this->accountType, 20, accountType);
	strcpy_s(this->IBAN, 23, IBAN);
	this->balance = balance;
}

void AccountInfoH::operator= (AccountInfoH& newAcc){
	strcpy_s(this->accountType, 20, newAcc.accountType);
	strcpy_s(this->IBAN, 23, newAcc.IBAN);
	this->balance = newAcc.balance;
}

bool AccountInfoH::operator== (AccountInfoH& existingAcc){
	if (strcmp(this->accountType, existingAcc.accountType) == 0 &&
		strcmp(this->IBAN, existingAcc.IBAN) == 0 &&
		this->balance == existingAcc.balance)
	{
		return true;
	}
	return false;
}

char* AccountInfoH::getIBAN(){
	return this->IBAN;
}

double AccountInfoH::getBalance(){
	return this->balance;
}

char* AccountInfoH::getAccountType(){
	return this->accountType;
}

void AccountInfoH::AddAmount(double add)
{
	this->balance += add;
}