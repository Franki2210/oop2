#include "stdafx.h"
#include "..\lab4_2var\LineSegment.h"
#include "PointTest.h"

struct LineFixture_
{
	CLineSegment line;
	LineFixture_()
		:line({ 10, 20 }, { 15, 20 }, "ff00ff")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Line, LineFixture_)
BOOST_AUTO_TEST_CASE(line_has_zero_area)
{
	BOOST_CHECK(line.GetArea() == 0);
}

BOOST_AUTO_TEST_CASE(line_has_a_perimeter)
{
	BOOST_CHECK(line.GetPerimeter() == 5);
}

BOOST_AUTO_TEST_CASE(line_get_start_point)
{
	IsPointsEqual(line.GetStartPoint(), { 10, 20 });
}

BOOST_AUTO_TEST_CASE(line_get_end_point)
{
	IsPointsEqual(line.GetEndPoint(), { 15, 20 });
}

BOOST_AUTO_TEST_CASE(line_to_string)
{
	BOOST_CHECK_EQUAL(line.ToString(), "Line: S = 0, P = 5, ColorOutline = ff00ff");
}
BOOST_AUTO_TEST_SUITE_END()

