#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

using namespace std;

class CTriangle final: public CSolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, string outlineColor, string fillColor);
	~CTriangle() = default;

	double GetArea() const;
	double GetPerimeter() const;

	string ToString() const;
	string GetOutlineColor() const;
	string GetFillColor() const;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	void Draw(ICanvas & canvas) const override;
private:
	string m_name = "triangle";
	vector<CPoint> m_vertices;
};
