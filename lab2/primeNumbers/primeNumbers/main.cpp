// primeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "generatePrimeNumbers.h"

using namespace std;

const int MAX_NUMBER = 100000000;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: primeNumbers.exe <upperBound>";
		return 1;
	}

	int upperBound = atoi(argv[1]);

	if ((upperBound == 0 && *argv[1] != '0') || upperBound > MAX_NUMBER || upperBound < 0)
	{
		cout << "Invalid upper bound\n";
		return 1;
	}

	set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

	cout << primeNumbers.size() << endl;

	//copy(primeNumbers.begin(), primeNumbers.end(), ostream_iterator<int>(std::cout, " "));

    return 0;
}

