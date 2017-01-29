#include "stdafx.h"
#include "dictionary.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n"
				  << "Usage: dictionary.exe <dictionary file>\n";
		return 1;
	}

	std::string dictionaryFileName = argv[1];

	if (!dictionaryFileName.empty())
	{
		//¬ход в функцию
		EnterTranslationLoop(dictionaryFileName, std::cin, std::cout);
	}
	else
	{
		std::cout << "Empty file name!\n";
		return 1;
	}
	return 0;
}

