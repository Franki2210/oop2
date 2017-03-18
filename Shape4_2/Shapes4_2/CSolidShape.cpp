#include "stdafx.h"
#include "CSolidShape.h"
#include "CShape.h"

CSolidShape::CSolidShape(string outlineColor, string fillColor)
	:CShape(outlineColor)
	, m_fillColor(fillColor)
{
}

string CSolidShape::GetFillColor()const
{
	return m_fillColor;
}

string CSolidShape::GetOutlineColor()const
{
	return CShape::GetOutlineColor();
}