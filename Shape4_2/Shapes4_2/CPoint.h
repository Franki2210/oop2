#pragma once
#include <string>

class CPoint final
{
public:
	CPoint() = default;
	~CPoint() = default;

	CPoint(double x0, double y0);

	std::string ToString()const;

	bool operator ==(CPoint const &point)const;
	bool operator !=(CPoint const &point)const;

	double x;
	double y;
};