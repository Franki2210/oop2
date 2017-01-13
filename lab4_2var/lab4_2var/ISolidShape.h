#pragma once
#include "IShape.h"
using namespace std;

class ISolidShape : public IShape
{
public:
	ISolidShape(string const& type, string const& fillColor, string const& outlineColor);
	virtual ~ISolidShape() = default;
	string GetFillColor() const;
private:
	string m_fillColor;
};

