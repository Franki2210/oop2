#pragma once
#include "Point.h"
#include "ISolidShape.h"

using namespace std;

class CTriangle : public ISolidShape
{
public:
	CTriangle(Point const& firstVertex, Point const& secondVertex, Point const& thirdVertex, string const& outlineColor, string const& fillColor);
	~CTriangle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	double GetSideLength(Point const& firstVertex, Point const& secondVertex) const;
	Point const& GetVertex1() const;
	Point const& GetVertex2() const;
	Point const& GetVertex3() const;
protected:
	void AppendProperties(ostream & strm) const override;
private:
	vector<Point> m_vertices;
};

