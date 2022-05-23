// Viruses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char* FindTheDeadliestVirus(HumanVirus* virus[], int virusesNumber);

int _tmain(int argc, _TCHAR* argv[])
{
	HumanVirus* array[4];
	array[0] = new HumanVirus("Virus1", 2000);
	array[1] = new HumanVirus("Virus2", 2005);
	array[2] = new HumanVirus("Virus3", 2010);
	array[3] = new HumanVirus("Covid-19", 2019);
	array[0]->SetData(3, 2000, 20, 5);
	array[0]->SetData(32, 20008, 231, 45);
	array[0]->SetData(45, 13000, 142, 34);
	array[0]->SetData(200, 100000, 5242, 203);
	
	array[1]->SetData(12, 200, 14, 2);
	array[1]->SetData(56, 3000, 324, 34);
	array[1]->SetData(145, 10032, 765, 64);
	array[1]->SetData(243, 32415, 1745, 175);

	array[2]->SetData(23, 45, 13, 3);
	array[2]->SetData(67, 153, 45, 24);
	array[2]->SetData(156, 1534, 342, 45);
	array[2]->SetData(267, 4534, 874, 203);

	array[3]->SetData(32, 4251, 305, 5);
	array[3]->SetData(89, 31414, 2953, 45);
	array[3]->SetData(178, 89348, 6395, 2914);
	array[3]->SetData(324, 248195, 20391, 7958);

	array[0]->doubleCalc();
	array[1]->doubleCalc();
	array[2]->doubleCalc();
	array[3]->doubleCalc();

	cout << FindTheDeadliestVirus(array, 4) << " is the deadliest virus!" << endl;

	if (*array[3] > *array[1])
	{
		printf_s("adawd");
	}
	return 0;
}


char* FindTheDeadliestVirus(HumanVirus* virus[], int virusesNumber)
{
	HumanVirus* deadliestVirus = virus[0];
	for (int i = 1; i < virusesNumber; i++)
	{
		if (virus[i]->FindRatio() > deadliestVirus->FindRatio())
		{
			deadliestVirus = virus[i];
		}
	}
	return deadliestVirus->virusName;
}
