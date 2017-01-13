#include "stdafx.h"
#include "Color.h"

bool HexToRGB(string const& hexColor, Color & rgbColor)
{
	bool isConverted = true;
	try
	{
		rgbColor.red = stoi(hexColor.substr(0, 2), nullptr, 16);
		rgbColor.green = stoi(hexColor.substr(2, 2), nullptr, 16);
		rgbColor.blue = stoi(hexColor.substr(4, 2), nullptr, 16);
	}
	catch (exception const& e)
	{
		cout << e.what() << endl;
		isConverted = false;
	}
	return isConverted;
}