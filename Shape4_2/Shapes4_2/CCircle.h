#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CCircle final : public CSolidShape
{
public:
	CCircle(CPoint center, double radius, string outlineColor, string fillColor);
	~CCircle() = default;

	double GetArea() const;
	double GetPerimeter() const;

	string ToString() const override;
	string GetOutlineColor() const override;
	string GetFillColor() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

	void Draw(ICanvas & canvas) const override;
private:
	string m_name = "circle";

	CPoint m_center;
	double m_radius;
};