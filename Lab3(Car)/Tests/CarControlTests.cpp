#include "stdafx.h"
#include "../Lab3(Car)/ControlCar.h"
#include "../Lab3(Car)/Car.h"
#include <sstream>
#include <boost/optional.hpp>

using boost::optional;
using boost::none;

struct CCarControllerDependencies
{
	CCar car;
	stringstream input;
	stringstream output;
};

struct CarControllerFixture : CCarControllerDependencies
{
	CControlCar controlCar;

	CarControllerFixture()
		: controlCar(car, input, output)
	{
	}

	void VerifyCommandHandling(const string & command, const string & expectedOutput)
	{
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(controlCar.HandleCommand());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Car_controller, CarControllerFixture)

	BOOST_AUTO_TEST_CASE(can_handle_EngineOn_command)
	{
		VerifyCommandHandling("EngineOn", "Engine is turned on\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_Info_command)
	{
		VerifyCommandHandling("Info", "Engine is turned off\nCar standing still\nSpeed 0 km/h\n0 gear\n");
	}

	BOOST_AUTO_TEST_CASE(can_print_errors_message)
	{
		VerifyCommandHandling("SetGear 1", "Could not enable gear\n");
	}

BOOST_AUTO_TEST_SUITE_END()