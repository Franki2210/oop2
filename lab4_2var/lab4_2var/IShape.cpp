#include "stdafx.h"
#include "IShape.h"

IShape::IShape(string const& type, string const& outlineColor)
	:m_type(type),
	m_outlineColor(outlineColor)
{
}

string IShape::GetOutlineColor() const
{
	return m_outlineColor;
};

string IShape::ToString() const
{
	ostringstream strm;
	strm << m_type + ": "
		<< "S = " << GetArea()
		<< ", P = " << GetPerimeter()
		<< ", ColorOutline = " << GetOutlineColor();
	AppendProperties(strm);
	return strm.str();
}