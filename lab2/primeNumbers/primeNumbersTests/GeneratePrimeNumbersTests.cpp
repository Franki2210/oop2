#include "stdafx.h"
#include "..\primeNumbers\generatePrimeNumbers.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)
	BOOST_AUTO_TEST_CASE(generate_with_correct_data)
	{
		set<int> correctResult = {2, 3, 5, 7, 11, 13, 17, 19};
		set<int> result = GeneratePrimeNumbersSet(20);
		BOOST_CHECK(result == correctResult);
	}

	BOOST_AUTO_TEST_CASE(generate_with_upper_bound_is_0)
	{
		set<int> correctResult = {};
		set<int> result = GeneratePrimeNumbersSet(0);
		BOOST_CHECK(result == correctResult);
	}

	BOOST_AUTO_TEST_CASE(generate_with_upper_bound_is_out_of_range)
	{
		set<int> correctResult = {};
		set<int> result = GeneratePrimeNumbersSet(100000001);
		BOOST_CHECK(result == correctResult);
	}

	BOOST_AUTO_TEST_CASE(check_size_vector_with_prime_numbers)
	{
		BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(100000000).size(), 5761455);
	}

BOOST_AUTO_TEST_SUITE_END()