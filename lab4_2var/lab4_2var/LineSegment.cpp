#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment(Point const& startPoint, Point const& endPoint, string const& outlineColor)
	:IShape("Line", outlineColor),
	m_startPoint(startPoint),
	m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
	return 0;
};

Point CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetPerimeter() const
{
	double dx = m_startPoint.x - m_endPoint.x;
	double dy = m_startPoint.y - m_endPoint.y;
	return hypot(dx, dy);
};

void CLineSegment::AppendProperties(ostream & strm) const
{
}