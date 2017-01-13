#include "stdafx.h"
#include "../Lab3(Car)/Car.h"


struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	BOOST_AUTO_TEST_CASE(is_engine_turned_off_by_default)
	{
		BOOST_CHECK(!car.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(must_be_in_neutral_gear_and_standing_still_and_speed_is_0)
	{
		BOOST_CHECK_EQUAL(car.GetGear(), 0);
		BOOST_CHECK_EQUAL(car.GetDirection(), Direction::STANDING_STILL);
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}

	BOOST_AUTO_TEST_CASE(engine_can_be_turned_on)
	{
		BOOST_CHECK(car.TurnOnEngine() == true);
	}

	BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off)
	{
		BOOST_CHECK(!car.TurnOffEngine());
	}

	BOOST_AUTO_TEST_CASE(switches_to_neutral_gear)
	{
		BOOST_CHECK(car.SetGear(0) == true);
	}

	BOOST_AUTO_TEST_CASE(non_switches_to_non_neutral_gear)
	{
		BOOST_CHECK(car.SetGear(1) == false);
	}

	BOOST_AUTO_TEST_CASE(cant_change_speed)
	{
		BOOST_CHECK(car.SetSpeed(5) == false);
	}

	struct when_engine_turned_on_ : CarFixture
	{
		when_engine_turned_on_()
		{
			car.TurnOnEngine();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(if_engine_turned_on, when_engine_turned_on_)

		BOOST_AUTO_TEST_CASE(engine_cant_be_turned_on)
		{
			BOOST_CHECK(car.TurnOnEngine() == false);
		}

		BOOST_AUTO_TEST_CASE(should_be_neutral_gear_by_default)
		{
			BOOST_CHECK(car.GetGear() == 0);
		}

			BOOST_AUTO_TEST_SUITE(set_gear_function)

				BOOST_AUTO_TEST_CASE(can_set_rear_gear)
				{
					BOOST_CHECK(car.SetGear(-1) == true);
				}

				BOOST_AUTO_TEST_CASE(can_set_first_gear)
				{
					BOOST_CHECK(car.SetGear(1) == true);
				}

				BOOST_AUTO_TEST_CASE(cant_set_gear_without_required_speed)
				{
					BOOST_CHECK(!car.SetGear(3));
				}

				BOOST_AUTO_TEST_CASE(can_set_rear_gear_from_neutral_gear_and_zero_speed)
				{
					BOOST_CHECK(car.SetGear(-1));
				}

				BOOST_AUTO_TEST_CASE(can_set_rear_gear_from_first_gear_and_zero_speed)
				{
					car.SetGear(1);
					car.SetSpeed(0);
					BOOST_CHECK(car.SetGear(-1));
				}

				BOOST_AUTO_TEST_CASE(cant_set_rear_gear_from_other_gears)
				{
					car.SetGear(1);
					car.SetSpeed(30);
					car.SetGear(2);
					BOOST_CHECK(!car.SetGear(-1));
				}

				BOOST_AUTO_TEST_CASE(can_set_first_gear_from_rear_gear_and_zero_speed)
				{
					car.SetGear(-1);
					car.SetSpeed(0);
					BOOST_CHECK(car.SetGear(1));
				}

				BOOST_AUTO_TEST_CASE(cant_set_first_gear_after_rear_gear_and_non_zero_speed)
				{
					car.SetGear(-1);
					car.SetSpeed(10);
					car.SetGear(0);
					BOOST_CHECK(!car.SetGear(1));
				}

				BOOST_AUTO_TEST_CASE(can_set_first_gear_after_rear_gear_and_zero_speed)
				{
					car.SetGear(-1);
					car.SetSpeed(10);
					car.SetGear(0);
					car.SetSpeed(0);
					BOOST_CHECK(car.SetGear(1));
				}

			BOOST_AUTO_TEST_SUITE_END()

			BOOST_AUTO_TEST_SUITE(set_speed_function)

				BOOST_AUTO_TEST_CASE(can_set_allowed_speed_for_gear)
				{
					car.SetGear(1);
					BOOST_CHECK(car.SetSpeed(10));
				}

				BOOST_AUTO_TEST_CASE(cant_set_speed_out_of_gear_speed_range)
				{
					car.SetGear(1);
					BOOST_CHECK(!car.SetSpeed(100));
				}

				BOOST_AUTO_TEST_CASE(cant_accelerate_at_neutral_gear)
				{
					car.SetGear(1);
					car.SetSpeed(10);
					car.SetGear(0);
					BOOST_CHECK(!car.SetSpeed(15));
				}

				BOOST_AUTO_TEST_CASE(can_slow_down_at_neutral_gear)
				{
					car.SetGear(1);
					car.SetSpeed(20);
					car.SetGear(0);
					BOOST_CHECK(car.SetSpeed(10));
				}

			BOOST_AUTO_TEST_SUITE_END()

			BOOST_AUTO_TEST_SUITE(Turn_off_function)

				BOOST_AUTO_TEST_CASE(engine_can_be_turned_off_at_neutral_gear_and_with_zero_speed)
				{
					BOOST_CHECK(car.TurnOffEngine());
				}

				BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off_at_neutral_gear_and_with_non_zero_speed)
				{
					car.SetGear(1);
					car.SetSpeed(20);
					car.SetGear(0);
					BOOST_CHECK(!car.TurnOffEngine());
				}

				BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off_at_non_neutral_gear)
				{
					car.SetGear(1);
					BOOST_CHECK(!car.TurnOffEngine());
				}

			BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()