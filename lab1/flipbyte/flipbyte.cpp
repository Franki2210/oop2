#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <input byte>\n";
		return 1;
	}

	int number = atoi(argv[1]);

	if (*argv[1] != '0' && number == 0)
	{
		cout << "Invalid input \n";
		return 1;
	}

	if (number < 0 || number > 255)
	{
		cout << "Number goes beyond\n";
		return 1;
	}

	int result = 0x00;
	int mask1 = 0x01;
	int mask2 = 0x80;
	for (int i = 0; i < 8; i++)
	{
		if ((number & mask1) != 0)
		{
			result = result | mask2;
		}
		mask1 = mask1 << 1;
		mask2 = mask2 >> 1;
	}
	cout << result << "\n";
	return 0;
}

