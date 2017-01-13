#include "stdafx.h"
#include "../Solve4/Solve4.h"

bool RootsAreEqual(EquationRoots const &expectedRoots1, EquationRoots const &expectedRoots2)
{
	for (size_t i = 0; i < expectedRoots2.numRoots; ++i)
	{
		if (abs(expectedRoots2.roots[i] - expectedRoots1.roots[i]) < DBL_EPSILON)
		{
			return true;
		}
	}

	return false;
}

BOOST_AUTO_TEST_SUITE(solve4_function)

	BOOST_AUTO_TEST_CASE(can_find_equation_roots)
	{
		EquationRoots solution = Solve4(1, 4, 6, 4, 1);

		EquationRoots expectedRoots;
		expectedRoots.numRoots = 2;
		expectedRoots.roots[0] = -1;
		expectedRoots.roots[1] = -1;

		BOOST_CHECK(RootsAreEqual(expectedRoots, solution));

		solution = Solve4(1, 4, 2, 4, 0);

		expectedRoots.numRoots = 2;
		expectedRoots.roots[0] = -3.7511;
		expectedRoots.roots[1] = 0;

		BOOST_CHECK(RootsAreEqual(expectedRoots, solution));
	}

	BOOST_AUTO_TEST_CASE(first_coefficient_must_be_not_equal_zero)
	{
		BOOST_CHECK_THROW(Solve4(0, 1, 2, 3, 4), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(may_have_not_real_roots)
	{
		BOOST_CHECK_THROW(Solve4(1, 2, 3, 4, 5), domain_error);
	}

BOOST_AUTO_TEST_SUITE_END()