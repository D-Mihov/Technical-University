#include "stdafx.h"
#include "HumanVirus.h"


HumanVirus::HumanVirus()
{
	strcpy_s(virusName, 30, "");
	firstCaseYear = 0;
	for (int i = 0; i < 365; i++)
	{
		table[i].dayFromTheYear = i + 1;
		table[i].infectedCount = -1;
		table[i].curedCount = -1;
		table[i].deadCount = -1;
	}
	totalNumberOfInfected = 0;
	totalNumberOfCured = 0;
	totalNumberOfDied = 0;
	DiedInfectedRatio = 0;
}


HumanVirus::HumanVirus(char* _virusName, int _firstCaseYear)
{
	strcpy_s(virusName, 30, _virusName);
	firstCaseYear = _firstCaseYear;
	for (int i = 0; i < 365; i++)
	{
		table[i].dayFromTheYear = i + 1;
		table[i].infectedCount = -1;
		table[i].curedCount = -1;
		table[i].deadCount = -1;
	}
	totalNumberOfInfected = 0;
	totalNumberOfCured = 0;
	totalNumberOfDied = 0;
	DiedInfectedRatio = 0;
}

HumanVirus::~HumanVirus()
{
}


void HumanVirus::SetData(int Day, int Infected, int Healed, int Died)
{
	table[Day].infectedCount = Infected;
	table[Day].curedCount = Healed;
	table[Day].deadCount = Died;
}


void HumanVirus::doubleCalc()
{
	for (int i = 0; i < 365; i++)
	{
		if (table[i].infectedCount != -1)
		{
			totalNumberOfInfected += table[i].infectedCount;
			totalNumberOfCured += table[i].curedCount;
			totalNumberOfDied += table[i].deadCount;
		}
	}
}


double HumanVirus::FindRatio()
{
	DiedInfectedRatio = totalNumberOfDied / totalNumberOfInfected;
	return DiedInfectedRatio;
}


HumanVirus& HumanVirus::operator=(HumanVirus& virus)
{
	strcpy_s(virusName, 30, virus.virusName);
	firstCaseYear = virus.firstCaseYear;
	for (int i = 0; i < 365; i++)
	{
		table[i].dayFromTheYear = virus.table[i].dayFromTheYear;
		table[i].infectedCount = virus.table[i].infectedCount;
		table[i].curedCount = virus.table[i].curedCount;
		table[i].deadCount = virus.table[i].deadCount;
	}
	totalNumberOfInfected = virus.totalNumberOfInfected;
	totalNumberOfCured = virus.totalNumberOfCured;
	totalNumberOfDied = virus.totalNumberOfDied;
	DiedInfectedRatio = virus.DiedInfectedRatio;
	return virus;
}


int HumanVirus::operator>(HumanVirus& virus)
{
	if (DiedInfectedRatio > virus.DiedInfectedRatio)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}