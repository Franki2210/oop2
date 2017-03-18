#include "stdafx.h"
#include "CShape.h"

CShape::CShape(string color)
	: m_outlineColor(color)
{
}

string CShape::GetOutlineColor()const
{
	return m_outlineColor;
}
