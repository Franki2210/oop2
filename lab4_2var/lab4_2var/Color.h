#pragma once
struct Color
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};
bool HexToRGB(string const& hexColor, Color & rgbColor);