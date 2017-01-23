#include "stdafx.h"
#include "../StringStack/StringStack.h"

struct StringStack_
{
	CStringStack stack;
};

BOOST_FIXTURE_TEST_SUITE(StringStack, StringStack_)

	BOOST_AUTO_TEST_CASE(is_empty_by_default)
	{
		BOOST_CHECK_EQUAL(stack.GetSize(), 0);
		BOOST_CHECK(stack.IsEmpty());
	}

	BOOST_AUTO_TEST_SUITE(throw_exception_if)

		BOOST_AUTO_TEST_CASE(get_element_from_empty_stack)
		{
			BOOST_REQUIRE_THROW(stack.GetTopElement(), std::domain_error);
		}

		BOOST_AUTO_TEST_CASE(pop_from_empty_stack)
		{
			BOOST_REQUIRE_THROW(stack.Pop(), std::domain_error);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_return_element)
	{
		stack.Push("top");
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "top");
		BOOST_CHECK_EQUAL(stack.GetSize(), 1);
	}

	BOOST_AUTO_TEST_CASE(can_add_element)
	{
		stack.Push("top");
		BOOST_CHECK_EQUAL(stack.GetSize(), 1);
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "top");
	}
	BOOST_AUTO_TEST_CASE(can_delete_element)
	{
		stack.Push("a");
		stack.Push("b");
		stack.Push("c");
		stack.Push("d");
		stack.Push("e");
		BOOST_CHECK_EQUAL(stack.GetSize(), 5);
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "e");
		stack.Pop();
		BOOST_CHECK_EQUAL(stack.GetSize(), 4);
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "d");
	}

BOOST_AUTO_TEST_SUITE_END()
