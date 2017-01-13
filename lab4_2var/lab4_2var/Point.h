#pragma once

class Point
{
public:
	Point() = default;
	Point(double x, double y);
	~Point() = default;
	string ToString() const;
	double x;
	double y;
};