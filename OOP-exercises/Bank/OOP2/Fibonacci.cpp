#include "stdafx.h"
#include "Fibonacci.h"


Fibonacci::Fibonacci()
{
	num1 = 1;
	num2 = 1;
}

int Fibonacci::Get()
{
	int sum = num1 + num2;
	num1 = num2;
	num2 = sum;
	return sum;
}

int Fibonacci::Set(int number)
{
	if (num1 < number)
	{
		while (num1 < number)
		{
			Get();
		}
		return num2;
	}
	else
	{
		return num2;
	}

}

