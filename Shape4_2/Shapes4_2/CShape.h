#pragma once
#include <string>
#include "IShape.h"

using namespace std;

class CShape : public virtual IShape
{
public:
	CShape() = default;
	CShape(string color);

	~CShape() = default;

	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual string ToString()const = 0;
	virtual string GetOutlineColor()const;

private:
	string m_outlineColor;
};