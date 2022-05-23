#pragma once
#include "VirusInfo.h"
class HumanVirus
{
protected:
	//char virusName[30];
	int firstCaseYear;
	VirusInfo table[365];
	double totalNumberOfInfected;
	double totalNumberOfCured;
	double totalNumberOfDied;
	double DiedInfectedRatio;
public:
	char virusName[30];
	HumanVirus();
	HumanVirus(char* _virusName, int _firstCaseYear);
	~HumanVirus();
	void SetData(int Day, int Infected, int Healed, int Died);
	void doubleCalc();
	double FindRatio();
	friend char* FindTheDeadliestVirus(HumanVirus* virus[], int virusesNumber);
	HumanVirus& operator= (HumanVirus& virus);
	int operator> (HumanVirus& virus);
};

