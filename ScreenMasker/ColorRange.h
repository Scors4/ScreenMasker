#pragma once

class Color
{
public:
	Color(int r, int g, int b);
	Color();

	void UpdateColor(int r, int g, int b);

	bool operator>=(Color);
	bool operator<=(Color);
	bool operator==(Color);

private:
	int red;
	int green;
	int blue;
};

class ColorRange
{
public:
	ColorRange();
	ColorRange(Color target);
	ColorRange(Color upper, Color lower);

public:

	bool CompareColor(Color input);

private:

	Color upperColor;
	Color lowerColor;
};

