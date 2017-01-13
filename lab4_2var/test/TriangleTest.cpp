#include "stdafx.h"
#include "..\lab4_2var\Triangle.h"
#include "PointTest.h"


struct TriangleFixture_
{
	CTriangle triangle;
	TriangleFixture_()
		:triangle({ 0, 0 }, { 0, 3 }, { 4, 3 }, "ff00ff", "0000ff")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle, TriangleFixture_)

BOOST_AUTO_TEST_CASE(triangle_has_a_perimeter)
{
	BOOST_CHECK(triangle.GetPerimeter() == 12);
}

BOOST_AUTO_TEST_CASE(triangle_has_a_area)
{
	BOOST_CHECK(triangle.GetArea() == 3 * 4 * 0.5);
}


BOOST_AUTO_TEST_CASE(triangle_get_vertex)
{
	IsPointsEqual(triangle.GetVertex1(), { 0, 0 });
	IsPointsEqual(triangle.GetVertex2(), { 0, 3 });
	IsPointsEqual(triangle.GetVertex3(), { 4, 3 });
}

BOOST_AUTO_TEST_CASE(triangle_get_fill_color)
{
	BOOST_CHECK(triangle.GetFillColor() == "0000ff");
}

BOOST_AUTO_TEST_CASE(triangle_get_outline_color)
{
	BOOST_CHECK(triangle.GetOutlineColor() == "ff00ff");
}

BOOST_AUTO_TEST_CASE(triangle_to_string)
{
	BOOST_CHECK(triangle.ToString() == "Triangle: S = 6, P = 12, ColorOutline = ff00ff, FillColor = 0000ff");
}

BOOST_AUTO_TEST_SUITE_END()

