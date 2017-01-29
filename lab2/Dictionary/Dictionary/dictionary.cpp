#include "stdafx.h"
#include "dictionary.h"

using namespace std;

bool IsEmptyFile(ifstream & file)
{
	return file.peek() == ifstream::traits_type::eof();
}

Dictionary GetDictionaryFromFile(const string & fileName)
{
	Dictionary dictionary;
	ifstream dictionaryFile(fileName);
	if (dictionaryFile.is_open() && !IsEmptyFile(dictionaryFile))
	{
		string buffer;
		while (getline(dictionaryFile, buffer))
		{
			vector<string> translation;
			boost::split(translation, buffer, bind2nd(equal_to<char>(), ':'));
			dictionary.insert(make_pair(translation[0], translation[1]));
		}
	}
	else
	{
		cout << "������� �� ��� ������, ������ ����� �������������� � ������ �������." << endl;
	}
	dictionaryFile.close();
	return dictionary;
}

string ToLower(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		input[i] = char(tolower(input[i]));
	}
	return input;
}

string FindTranslation(string & inputString, const Dictionary & dictionary)
{
	inputString = ToLower(inputString);
	auto translation = dictionary.find(inputString);
	if (translation != dictionary.end())
	{
		return translation->second;
	}
	else
	{
		return "";
	}
}

void AddNewTranslation(const string & word, string & translationWord, Dictionary & dictionary)
{
	translationWord = ToLower(translationWord);
	dictionary.insert(make_pair(word, translationWord));
}

void SaveDictionaryToFile(const string & dictionaryFileName, Dictionary & dictionary)
{
	ofstream dictionaryFile(dictionaryFileName);
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		dictionaryFile << it->first << ":" << it->second << endl;
	}
	dictionaryFile.close();
}

void RequestToSaveDictionaryFile(istream & input, ostream & output, const string &dictionaryFileName, Dictionary &dictionary)
{
	output << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������." << endl;
	output << ">";
	char userChoice;
	input >> userChoice;
	userChoice = char(tolower(userChoice));
	if (userChoice == 'y')
	{
		SaveDictionaryToFile(dictionaryFileName, dictionary);
		output << "��������� ���������. �� ��������." << endl;
	}
}

void ProcessingUserInput(istream & input, ostream & output, string & inputString, Dictionary & dictionary, bool & dictionaryHasChanged)
{
	string translationString = FindTranslation(inputString, dictionary);
	if (!translationString.empty())
	{
		output << translationString << endl;
	}
	else
	{
		output << "����������� ����� '" << inputString << "'. ������� ������� ��� ������ ������ ��� ������." << endl;
		output << ">";
		getline(input, translationString);
		if (translationString.empty())
		{
			output << "����� '" << inputString << "' ���������������." << endl;
		}
		else
		{
			AddNewTranslation(inputString, translationString, dictionary);
			output << "����� '" << inputString << "' ��������� � ������� ��� '" << translationString << "'." << endl;
			dictionaryHasChanged = true;
		}
	}
}

void EnterTranslationLoop(const string & dictionaryFileName, istream & input, ostream & output)
{
	bool dictionaryHasChanged = false;

	Dictionary dictionary = GetDictionaryFromFile(dictionaryFileName);

	string inputString;

	output << ">";
	while (getline(input, inputString) && inputString != EXIT)
	{
		if (!inputString.empty())
		{
			ProcessingUserInput(input, output, inputString, dictionary, dictionaryHasChanged);
		}
		output << ">";
	}
	if (dictionaryHasChanged)
	{
		RequestToSaveDictionaryFile(input, output, dictionaryFileName, dictionary);
	}
}