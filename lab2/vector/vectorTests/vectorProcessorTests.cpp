#include "stdafx.h"
#include "..\vector\vectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(vector_when_max_element_is_0)
	{
		vector<double> numbers = { 0, -13 };
		ProcessVector(numbers);
		BOOST_CHECK(isnan(numbers[0]) && isinf(numbers[1]));
	}

	BOOST_AUTO_TEST_CASE(vector_processing_by_dividing_each_element_on_the_half_of_the_maximum_element)
	{
		vector<double> numbers = { 4.5, 5, -5, 10};
		vector<double> numbersAfterProcessing = { (4.5 / 5), (5 / 5), (-5 / 5), (10 / 5) };
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, numbersAfterProcessing));
	}

BOOST_AUTO_TEST_SUITE_END()


