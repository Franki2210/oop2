#pragma once
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CLineSegment final: public CShape
{
public:
	CLineSegment() = default;
	~CLineSegment() = default;

	CLineSegment(CPoint startPoint, CPoint endPoint, string outlineColor);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const;
	double GetPerimeter() const;
	string ToString() const;
	string GetOutlineColor() const;
	void Draw(ICanvas & canvas) const override;
private:
	string m_name = "line segment";

	CPoint m_startPoint;
	CPoint m_endPoint;
};