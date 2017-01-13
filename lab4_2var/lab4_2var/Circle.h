#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CCircle: public ISolidShape
{
public:
	CCircle(Point const& center, double radius, string const& outlineColor, string const& fillColor);
	~CCircle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	Point GetCenter() const;
	double GetRadius() const;
protected:
	void AppendProperties(ostream & strm) const;
private:
	Point m_center;
	double m_radius = 0;
};

