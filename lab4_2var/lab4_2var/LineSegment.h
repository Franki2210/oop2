#pragma once
#include "IShape.h"
#include "Point.h"
using namespace std;

class CLineSegment: public IShape
{
public:
	CLineSegment(Point const& startPosition, Point const& endPosition, std::string const& outlineColor);
	~CLineSegment() = default;
	double GetArea() const;
	double GetPerimeter() const;
	Point GetStartPoint() const;
	Point GetEndPoint() const;
protected:
	void AppendProperties(ostream & strm) const override;
private:
	Point m_startPoint;
	Point m_endPoint;
};

