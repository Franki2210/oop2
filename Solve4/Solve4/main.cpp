// Solve4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solve4.h"

int main()
{
	EquationRoots equationRoots;

	vector<double> numbers;

	while (!cin.eof())
	{
		double number;
		cin >> number;

		if (numbers.size() != 5)
		{
			numbers.push_back(number);
		}
	}

	try
	{
		if (numbers.size() != 5)
		{
			throw domain_error("Invalid arguements count.\nCount of arguements must be equal to 5.");
		}

		equationRoots = Solve4(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	}
	catch (invalid_argument const &e)
	{
		cout << e.what() << endl;
	}
	catch (domain_error const &e)
	{
		cout << e.what() << endl;
	}

	PrintRoots(equationRoots, cout);
    return 0;
}

