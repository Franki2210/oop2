#pragma once
#include "ISolidShape.h"
#include "CShape.h"

using namespace std;

class CSolidShape : public CShape, public ISolidShape
{
public:
	CSolidShape() = default;
	CSolidShape(string outlineColor, string fillColor);

	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual string ToString()const = 0;

	virtual string GetFillColor()const;
	string GetOutlineColor()const;
private:
	string m_fillColor;
};