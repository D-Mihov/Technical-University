#include "stdafx.h"
#include <iostream>
#include "AccountInfoH.h"
#include "BankClientH.h"
#include "BankH.h"
using namespace std;



int main()
{
	BankClientH BankClient1 = *new BankClientH("Ivan", "ASD", 11);
	BankClientH BankClient2 = *new BankClientH("asd", "ASD", 22);
	BankClientH BankClient3 = *new BankClientH("dsa", "ASD", 33);
	AccountInfoH accountInfo1 = *new AccountInfoH("asd", "123123", 10);
	AccountInfoH accountInfo2 = *new AccountInfoH("dsa", "111", 19);
	AccountInfoH accountInfo3 = *new AccountInfoH("qwe", "1343", 18);
	BankClient1.AddAccount(accountInfo1);
	BankClient1.AddAccount(accountInfo2);
	BankClient1.AddAccount(accountInfo3);
	BankClient1.AddBalance(5, "123123");
	BankClient1.RemoveAccount(accountInfo1);
	BankClient1.PrintClient();
	BankH bank1 = *new BankH(1);
	bank1.Append(BankClient1); 
	bank1.Append(BankClient2);
	bank1.Append(BankClient3);
	bank1.Delete(11);
	return 0;
}