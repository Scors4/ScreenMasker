#include "ColorRange.h"


Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}

void Color::UpdateColor(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}

bool Color::operator>=(Color input)
{
	return (input.red <= red &&
		input.green <= green &&
		input.blue <= blue);
}

bool Color::operator<=(Color input)
{
	return (input.red >= red &&
		input.green >= green &&
		input.blue >= blue);
}

bool Color::operator==(Color input)
{
	return (input.red == red &&
		input.green == green &&
		input.blue == blue);
}

ColorRange::ColorRange()
{
	upperColor = Color();
	lowerColor = Color();
}

ColorRange::ColorRange(Color target)
{
	upperColor = target;
	lowerColor = target;
}

ColorRange::ColorRange(Color lower, Color upper)
{
	upperColor = upper;
	lowerColor = lower;
}

bool ColorRange::CompareColor(Color input)
{
	return (input >= lowerColor && input <= upperColor);
}