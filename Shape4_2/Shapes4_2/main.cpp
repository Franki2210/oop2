#include "stdafx.h"
#include "string"
#include <iostream>
#include <fstream>
#include <vector>

#define _USE_MATH_DEFINES
#include "math.h"
#include "CLineSegment.h"
#include "CRemoteControl.h"
#include "CCircle.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count." << endl;
		cout << "Usage Shapes.exe <inputFile.txt>" << endl;

		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile)
	{
		cout << "Failed to open file: " << argv[1] << endl;
		return 1;
	}

	CRemoteControl remoteControl(inputFile, cout);

	while (!inputFile.eof() && !inputFile.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	remoteControl.PrintInfo(cout);
	remoteControl.DrawShapes();
	return 0;
}