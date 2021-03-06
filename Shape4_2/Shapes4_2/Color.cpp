#include "stdafx.h"
#include "Color.h"

sf::Color HexToRGB(std::string const& hexColor)
{
	sf::Color result;
	try
	{
		result.r = sf::Uint8(std::stoi(hexColor.substr(0, 2), 0, 16));
		result.g = sf::Uint8(std::stoi(hexColor.substr(2, 2), 0, 16));
		result.b = sf::Uint8(std::stoi(hexColor.substr(4, 2), 0, 16));
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}
	return result;
}