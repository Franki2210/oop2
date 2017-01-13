#include "stdafx.h"
#include "PointTest.h"
#include "..\lab4_2var\Rectangle.h"

struct RectangleFixture_
{
	CRectangle rectangle;
	RectangleFixture_()
		:rectangle({ 10, 10 }, 100, 10, "ff00ff", "0000ff")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleFixture_)

BOOST_AUTO_TEST_CASE(rectangle_has_a_perimeter)
{
	BOOST_CHECK(rectangle.GetPerimeter() == 220);
}

BOOST_AUTO_TEST_CASE(rectangle_has_a_area)
{
	BOOST_CHECK(rectangle.GetArea() == 1000);
}


BOOST_AUTO_TEST_CASE(rectangle_get_vertex)
{
	IsPointsEqual(rectangle.GetLeftTop(), { 10, 10 });
	IsPointsEqual(rectangle.GetRightBottom(), { 110, 20 });
}

BOOST_AUTO_TEST_CASE(rectangle_get_fill_color)
{
	BOOST_CHECK(rectangle.GetFillColor() == "0000ff");
}

BOOST_AUTO_TEST_CASE(rectangle_get_outline_color)
{
	BOOST_CHECK(rectangle.GetOutlineColor() == "ff00ff");
}

BOOST_AUTO_TEST_CASE(rectangle_to_string)
{
	BOOST_CHECK_EQUAL(rectangle.ToString(), "Rectangle: S = 1000, P = 220, ColorOutline = ff00ff, FillColor = 0000ff, Width = 100, Height = 10");
}

BOOST_AUTO_TEST_SUITE_END()