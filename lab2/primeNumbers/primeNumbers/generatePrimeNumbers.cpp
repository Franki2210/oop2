#include "stdafx.h"
#include "generatePrimeNumbers.h"

using namespace std;

const int MAX_NUMBER = 100000000;
const int MIN_PRIME = 2;

vector<bool> CreateSieve(int upperBound)
{
	vector<bool> sieve(upperBound + 1, true);
	for (int i = MIN_PRIME; i * i <= upperBound; ++i)
	{
		if (sieve[i])
		{
			for (int j = i * i; j <= upperBound; j += i)
			{
				sieve[j] = false;
			}
		}
	}
	return sieve;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> sieve = CreateSieve(upperBound);
	set<int> primeNumbers;
	if (upperBound >= MIN_PRIME && upperBound <= MAX_NUMBER)
	{
		for (int i = MIN_PRIME; i < upperBound; ++i)
		{
			if (sieve[i])
			{
				primeNumbers.insert(i);
			}
		}
	}
	return primeNumbers;
}