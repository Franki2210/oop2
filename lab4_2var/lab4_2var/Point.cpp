#include "stdafx.h"
#include "Point.h"

Point::Point(double x, double y)
	: x(x)
	, y(y)
{
}

string Point::ToString() const
{
	return '(' + to_string(x) + ", " + to_string(y) + ')';
}