#include "stdafx.h"
#include "CPoint.h"
#include <string>

CPoint::CPoint(double x0, double y0)
	: x(x0)
	, y(y0)
{
}

std::string CPoint::ToString()const
{
	return std::to_string(x) + " " + std::to_string(y);
}

bool CPoint::operator ==(CPoint const &point)const
{
	return ((x == point.x) && (y == point.y));
}

bool CPoint::operator !=(CPoint const &point)const
{
	return !(*this == point);
}