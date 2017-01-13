#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FindText(ifstream & inputText, string const & searchString)
{
	string line;
	bool found = false;
	int lineNumber = 0;
	while (getline(inputText, line))
	{
		lineNumber++;
		if (line.find(searchString) != string::npos)
		{
			cout << lineNumber << endl;
			found = true;
		}
	}
	return found;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	string needle = argv[2];

	if (needle.empty())
	{
		cout << "Needle line is empty\n";
		return 1;
	}

	if (!FindText(inputFile, needle))
	{
		cout << "Text not found\n";
		return 1;
	}

	inputFile.close();

	return 0;
}

