#include "stdafx.h"
#include "Triangle.h"
#include "ISolidShape.h"
#include "Point.h"


CTriangle::CTriangle(Point const& firstVertex, Point const& secondVertex, Point const& thirdVertex, string const& outlineColor, string const& fillColor)
	:ISolidShape("Triangle", fillColor, outlineColor)
{
	m_vertices.push_back(firstVertex);
	m_vertices.push_back(secondVertex);
	m_vertices.push_back(thirdVertex);
}

Point const& CTriangle::GetVertex1() const
{
	return m_vertices[0];
}

Point const& CTriangle::GetVertex2() const
{
	return m_vertices[1];
}

Point const& CTriangle::GetVertex3() const
{
	return m_vertices[2];
}

double CTriangle::GetArea() const
{
	double semiperimeter = GetPerimeter() * 0.5;
	return sqrt(semiperimeter*(semiperimeter - GetSideLength(m_vertices[0], m_vertices[1]))*
		(semiperimeter - GetSideLength(m_vertices[1], m_vertices[2]))*
		(semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))
	);
};

double CTriangle::GetSideLength(Point const& firstVertex, Point const& secondVertex) const
{
	double dx = firstVertex.x - secondVertex.x;
	double dy = firstVertex.y - secondVertex.y;
	return hypot(dx, dy);
};

double CTriangle::GetPerimeter() const
{
	return GetSideLength(m_vertices[0], m_vertices[1]) +
		GetSideLength(m_vertices[1], m_vertices[2]) +
		GetSideLength(m_vertices[2], m_vertices[0]);
};

void CTriangle::AppendProperties(ostream & strm) const
{
	strm << ", FillColor = " << ISolidShape::GetFillColor();
}