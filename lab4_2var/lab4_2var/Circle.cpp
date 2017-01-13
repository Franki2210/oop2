#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(Point const& center, double radius, string const& outlineColor, string const& fillColor)
	: m_center(center)
	, m_radius(radius)
	, ISolidShape("Circle", fillColor, outlineColor)
{
	if (m_radius < 0)
	{
		m_radius = 0;
	}
}

Point CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
};

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
};

void CCircle::AppendProperties(ostream & strm) const
{
	strm << ", FillColor = " << ISolidShape::GetFillColor();
	strm << ", Radius = " << m_radius;
}
