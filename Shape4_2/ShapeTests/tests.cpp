#include "stdafx.h"

#include "../Shapes4_2/CPoint.h"
#include "../Shapes4_2/CLineSegment.h"
#include "../Shapes4_2/CTriangle.h"
#include "../Shapes4_2/CRectangle.h"
#include "../Shapes4_2/CCircle.h"
#include "../Shapes4_2/CRemoteControl.h"

#define _USE_MATH_DEFINES
#include "math.h"

struct RemoteControlDependencies
{
	std::stringstream input;
	std::stringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlFixture()
		: remoteControl(input, output)
	{
	}

	void VerifyCommandHandling(const std::string& command, const std::string& expectedOutput)
	{
		output = std::stringstream();
		input = std::stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};


struct DefaultShapes
{
	CLineSegment segment = CLineSegment(CPoint(1, 0), CPoint(15, 0), "ff0000");
	CTriangle triangle = CTriangle(CPoint(0, 0), CPoint(0, 3), CPoint(4, 0), "0000ff", "ff0000");
	CRectangle rectangle = CRectangle(CPoint(0, 0), 10, 20, "000000", "ffffff");
	CCircle circle = CCircle(CPoint(0, 0), 0.5 , "ff0000", "00ff00");
};

BOOST_FIXTURE_TEST_SUITE(Shapes, DefaultShapes)
	BOOST_AUTO_TEST_SUITE(Point)
		BOOST_AUTO_TEST_CASE(can_convert_point_data_to_string)
		{
			CPoint point(1.42, 18.55);
			std::string expectedString = "1.420000 18.550000";
			BOOST_CHECK_EQUAL(expectedString, point.ToString());
		}
		BOOST_AUTO_TEST_CASE(can_be_compared)
		{
			CPoint point(1, 2);
			CPoint samePoint(1, 2);
			CPoint anotherPoint(2, 3);
			BOOST_CHECK(point == samePoint);
			BOOST_CHECK(point != anotherPoint);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(LineSegment)
		BOOST_AUTO_TEST_CASE(can_get_start_point)
		{
			CPoint expectedPoint(1, 0);
			BOOST_CHECK(expectedPoint == segment.GetStartPoint());
		}

		BOOST_AUTO_TEST_CASE(can_get_end_point)
		{
			CPoint expectedPoint(15, 0);
			BOOST_CHECK(expectedPoint == segment.GetEndPoint());
		}

		BOOST_AUTO_TEST_CASE(can_get_outline_color)
		{
			std::string expectedColor = "ff0000";
			BOOST_CHECK_EQUAL(expectedColor, segment.GetOutlineColor());
		}

		BOOST_AUTO_TEST_CASE(can_get_area)
		{
			double expectedArea = 0;
			BOOST_CHECK_EQUAL(expectedArea, segment.GetArea());
		}

		BOOST_AUTO_TEST_CASE(can_get_segment_perimeter)
		{
			double expectedPerimeter = 14;
			BOOST_CHECK_EQUAL(expectedPerimeter, segment.GetPerimeter());
		}

		BOOST_AUTO_TEST_CASE(can_convert_segment_data_to_string)
		{
			std::string expectedString = "line segment 1.000000 0.000000 15.000000 0.000000 ff0000";
			BOOST_CHECK_EQUAL(expectedString, segment.ToString());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Triangle)
		BOOST_AUTO_TEST_CASE(can_get_perimeter)
		{
			double expectedPerimeter = 12;
			BOOST_CHECK_EQUAL(expectedPerimeter, triangle.GetPerimeter());
		}

		BOOST_AUTO_TEST_CASE(can_get_area)
		{
			double expectedArea = 6;
			BOOST_CHECK_EQUAL(expectedArea, triangle.GetArea());
		}

		BOOST_AUTO_TEST_CASE(can_get_triangle_vertexes)
		{
			CPoint expectedVertex1(0, 0);
			CPoint expectedVertex2(0, 3); 
			CPoint expectedVertex3(4, 0);

			BOOST_CHECK(expectedVertex1 == triangle.GetVertex1());
			BOOST_CHECK(expectedVertex2 == triangle.GetVertex2());
			BOOST_CHECK(expectedVertex3 == triangle.GetVertex3());
		}

		BOOST_AUTO_TEST_CASE(can_get_outline_color)
		{
			std::string expectedColor = "0000ff";
			BOOST_CHECK_EQUAL(expectedColor, triangle.GetOutlineColor());
		}

		BOOST_AUTO_TEST_CASE(can_get_fill_color)
		{
			std::string expectedColor = "ff0000";
			BOOST_CHECK_EQUAL(expectedColor, triangle.GetFillColor());
		}

		BOOST_AUTO_TEST_CASE(can_convert_triangle_data_to_string)
		{
			std::string expectedString = 
				"triangle 0.000000 0.000000 0.000000 3.000000 4.000000 0.000000 0000ff ff0000";
			BOOST_CHECK_EQUAL(expectedString, triangle.ToString());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Rectangle)
		BOOST_AUTO_TEST_CASE(can_get_perimeter)
		{
			double expectedPerimeter = 60;
			BOOST_CHECK_EQUAL(expectedPerimeter, rectangle.GetPerimeter());
		}

		BOOST_AUTO_TEST_CASE(can_get_area)
		{
			double expectedArea = 200;
			BOOST_CHECK_EQUAL(expectedArea, rectangle.GetArea());
		}

		BOOST_AUTO_TEST_CASE(can_get_outline_color)
		{
			std::string expectedColor = "000000";
			BOOST_CHECK_EQUAL(expectedColor, rectangle.GetOutlineColor());
		}

		BOOST_AUTO_TEST_CASE(can_get_fill_color)
		{
			std::string expectedColor = "ffffff";
			BOOST_CHECK_EQUAL(expectedColor, rectangle.GetFillColor());
		}

		BOOST_AUTO_TEST_CASE(can_get_left_top_point)
		{
			CPoint expectedPoint(0, 0);
			BOOST_CHECK(expectedPoint == rectangle.GetLeftTop());
		}

		BOOST_AUTO_TEST_CASE(can_get_right_bottom_point)
		{
			CPoint expectedPoint(10, 20);
			BOOST_CHECK(expectedPoint == rectangle.GetRightBottom());
		}

		BOOST_AUTO_TEST_CASE(can_get_width)
		{
			double expectedWidth = 10;
			BOOST_CHECK_EQUAL(expectedWidth, rectangle.GetWidth());
		}

		BOOST_AUTO_TEST_CASE(can_get_height)
		{
			double expectedHeight = 20;
			BOOST_CHECK_EQUAL(expectedHeight, rectangle.GetHeight());
		}

		BOOST_AUTO_TEST_CASE(can_convert_rectangle_data_to_string)
		{
			std::string expectedString =
				"rectangle 0.000000 0.000000 10.000000 20.000000 000000 ffffff";
			BOOST_CHECK_EQUAL(expectedString, rectangle.ToString());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Circle)
		BOOST_AUTO_TEST_CASE(can_get_perimeter)
		{
			double expectedPerimeter = M_PI;
			BOOST_CHECK_EQUAL(expectedPerimeter, circle.GetPerimeter());
		}
		
		BOOST_AUTO_TEST_CASE(can_get_area)
		{
			double expectedArea = M_PI * circle.GetRadius() * circle.GetRadius();
			BOOST_CHECK_EQUAL(expectedArea, circle.GetArea());
		}

		BOOST_AUTO_TEST_CASE(can_get_outline_color)
		{
			std::string expectedColor = "ff0000";
			BOOST_CHECK_EQUAL(expectedColor, circle.GetOutlineColor());
		}

		BOOST_AUTO_TEST_CASE(can_get_fill_color)
		{
			std::string expectedColor = "00ff00";
			BOOST_CHECK_EQUAL(expectedColor, circle.GetFillColor());
		}

		BOOST_AUTO_TEST_CASE(can_get_center)
		{
			CPoint expectedPoint(0, 0);
			BOOST_CHECK(expectedPoint == circle.GetCenter());
		}

		BOOST_AUTO_TEST_CASE(can_get_radius)
		{
			double expectedRadius = 0.5;
			BOOST_CHECK_EQUAL(expectedRadius, circle.GetRadius());
		}

		BOOST_AUTO_TEST_CASE(can_convert_circle_data_to_string)
		{
			std::string expectedString = "circle 0.000000 0.000000 0.500000 ff0000 00ff00";
			BOOST_CHECK_EQUAL(expectedString, circle.ToString());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(HexToRGB_function)
	BOOST_AUTO_TEST_CASE(cant_convert_wrong_hex_string)
	{
		BOOST_REQUIRE_THROW(HexToRGB(""), std::exception);
	}
	BOOST_AUTO_TEST_CASE(can_convert_valid_hex_string)
	{
		BOOST_CHECK(HexToRGB("000000") == sf::Color(0, 0, 0));
		BOOST_CHECK(HexToRGB("FF0000") == sf::Color(255, 0, 0));
		BOOST_CHECK(HexToRGB("00FF00") == sf::Color(0, 255, 0));
		BOOST_CHECK(HexToRGB("0000FF") == sf::Color(0, 0, 255));
		BOOST_CHECK(HexToRGB("FFFFFF") == sf::Color(255, 255, 255));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)
	BOOST_AUTO_TEST_CASE(can_handle_correct_line_command)
	{
		VerifyCommandHandling("line 0 0 1 1 #ffffff", "line segment was created\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_incorrect_line_command)
	{
		VerifyCommandHandling("line a s d s a q w e r", "Invalid parameters count.\n"
			"Usage line <x1> <y1> <x2> <y2> <outlineColor>\n");
		VerifyCommandHandling("line", "Invalid parameters count.\n"
			"Usage line <x1> <y1> <x2> <y2> <outlineColor>\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_correct_circle_command)
	{
		VerifyCommandHandling("circle 0 0 12 #fafafa #ababab", "circle was created\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_incorrect_circle_command)
	{
		VerifyCommandHandling("circle line", "Invalid parameters count.\n"
			"Usage circle <x1> <y1> <radius> <outlineColor> <fillColor>\n");
		VerifyCommandHandling("circle 0 0 A", "Invalid parameters count.\n"
			"Usage circle <x1> <y1> <radius> <outlineColor> <fillColor>\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_correct_triangle_command)
	{
		VerifyCommandHandling("triangle 0 0 0 5 3 0 #fafafa #ababab", "triangle was created\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_incorrect_triangle_command)
	{
		VerifyCommandHandling("triangle ababab", "Invalid parameters count.\n"
			"Usage triangle <x1> <y1> <x2> <y2> <x3> <y3> <outlineColor> <fillColor>\n");
		VerifyCommandHandling("triangle 42 42", "Invalid parameters count.\n"
			"Usage triangle <x1> <y1> <x2> <y2> <x3> <y3> <outlineColor> <fillColor>\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_correct_rectangle_command)
	{
		VerifyCommandHandling("rectangle 0 0 30 40 #fafafa #ababab", "rectangle was created\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_incorrect_rectangle_command)
	{
		VerifyCommandHandling("rectangle 32 A 28 C", "Invalid parameters count.\n"
			"Usage rectangle <x1> <y1> <width> <height> <outlineColor> <fillColor>\n");
		VerifyCommandHandling("rectangle", "Invalid parameters count.\n"
			"Usage rectangle <x1> <y1> <width> <height> <outlineColor> <fillColor>\n");
	}
BOOST_AUTO_TEST_SUITE_END()