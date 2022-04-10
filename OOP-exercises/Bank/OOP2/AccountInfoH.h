#pragma once
class AccountInfoH
{
	private:
		char accountType[20];
		char IBAN[23];
		double balance;
	public:
		AccountInfoH();
		AccountInfoH(const char* accountType, const char* IBAN, double balance);
		void operator= (AccountInfoH& newAcc);
		bool operator== (AccountInfoH& existingAcc);
		char* getIBAN();
		double getBalance();
		char* getAccountType();
		void AddAmount(double add);
	};

