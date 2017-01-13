#include "stdafx.h"
#include "ISolidShape.h"

ISolidShape::ISolidShape(string const& type, string const& fillColor, string const& outlineColor)
	:IShape(type, outlineColor),
	m_fillColor(fillColor)
{
}

string ISolidShape::GetFillColor() const
{
	return m_fillColor;
}