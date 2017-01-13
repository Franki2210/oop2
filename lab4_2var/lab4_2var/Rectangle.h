#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(Point const& leftTop, double width, double height, string const& outlineColor, string const& fillColor);
	virtual ~CRectangle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
protected:
	void AppendProperties(ostream & strm) const;
private:
	Point m_leftTop, m_rightBottom;
	double m_width, m_height;
};

