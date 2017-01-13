// crypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char MixByte(const char &ch)
{
	char result = 0x00;
	result = result | ((ch & 0b00000111) << 2);
	result = result | ((ch & 0b00011000) << 3);
	result = result | ((ch & 0b01100000) >> 5);
	result = result | ((ch & 0b10000000) >> 2);
	return result;
}

char ReverseMixByte(const char &ch)
{
	char result = 0x00;
	result = result | ((ch & 0b00011100) >> 2);
	result = result | ((ch & 0b11000000) >> 3);
	result = result | ((ch & 0b00000011) << 5);
	result = result | ((ch & 0b00100000) << 2);
	return result;
}

void Encrypt(ifstream & inputFile, ofstream & outputFile, const int &key)
{
	char ch;
	while (inputFile.read(&ch, sizeof(ch)))
	{
		char resultCh = MixByte(ch ^ key);
		outputFile.write(&resultCh, sizeof(resultCh));
	}
	cout << endl;
}

void Decrypt(ifstream & inputFile, ofstream & outputFile, const int &key)
{
	char ch;
	while (inputFile.read(&ch, sizeof(ch)))
	{
		char resultCh = ReverseMixByte(ch) ^ key;
		outputFile.write(&resultCh, sizeof(resultCh));
	}
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n";
		cout << "For encryption usage: crypt.exe crypt <input file> <output file> key\n";
		cout << "For decryption usage: crypt.exe decrypt <input file> <output file> key\n";
		return 1;
	}

	ifstream inputFile(argv[2], ios::in | ios::binary);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}
	if (inputFile.peek() == ifstream::traits_type::eof())
	{
		cout << "File " << argv[2] << " is empty" << "\n";
		return 1;
	}

	ofstream outputFile(argv[3], ios::out | ios::binary);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing\n";
		return 1;
	}

	int key = atoi(argv[4]);

	if (*argv[4] != '0' && key == 0)
	{
		cout << "Invalid key input\n";
		cout << "Key not a number\n";
		return 1;
	}

	if (key < 0 || key > 255)
	{
		cout << "Invalid key input\n";
		cout << "Key must be in the range from 0 to 255";
		return 1;
	}

	string mode = argv[1];
	if (mode == "crypt")
	{
		Encrypt(inputFile, outputFile, key);
	}
	else if (mode == "decrypt")
	{
		Decrypt(inputFile, outputFile, key);
	}
	else
	{
		cout << "Wrong operating input, use <crypt> or <decrypt>\n";
		return 1;
	}

    return 0;
}

