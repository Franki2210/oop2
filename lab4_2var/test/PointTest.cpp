#include "stdafx.h"
#include "PointTest.h"

void IsPointsEqual(const Point &point1, const Point &point2)
{
	BOOST_CHECK_CLOSE_FRACTION(point1.x, point2.x, 0.001);
	BOOST_CHECK_CLOSE_FRACTION(point1.y, point2.y, 0.001);
}

struct PointFixture_
{
	Point point;
	PointFixture_()
		:point({ 10.2, 23.4 })
	{}
};

BOOST_FIXTURE_TEST_SUITE(PointFixture, PointFixture_)
BOOST_AUTO_TEST_CASE(can_return_point)
{
	Point referencePoint = { 10.2, 23.4 };
	IsPointsEqual(point, referencePoint);
}
BOOST_AUTO_TEST_SUITE_END()