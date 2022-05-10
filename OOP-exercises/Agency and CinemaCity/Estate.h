#pragma once
#include <iostream>
using namespace std;

class Estate
{
	char address[20];
	char owner[20];
	double price;
	int area;
public:
	Estate();
	Estate(char* address, char* owner, double price, int area);
	~Estate();
	double getPrice();
	virtual void print();
};

