#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CRectangle final: public CSolidShape
{
public:
	CRectangle(CPoint leftTopPoint, double width, double height, string outlineColor, string fillColor);
	~CRectangle() = default;

	double GetArea() const;
	double GetPerimeter() const;

	string ToString() const;
	string GetOutlineColor() const;
	string GetFillColor() const;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

	void Draw(ICanvas & canvas) const override;
private:
	string m_name = "rectangle";

	CPoint m_leftTop;
	double m_width;
	double m_height;
};