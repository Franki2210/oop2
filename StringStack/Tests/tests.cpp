#include "stdafx.h"
#include "../StringStack/StringStack.h"
#include <iostream>

using namespace std;

struct EmptyStack
{
	CStringStack stringStack;
};

BOOST_FIXTURE_TEST_SUITE(Stack, EmptyStack)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty_by_default)
		{
			BOOST_CHECK(stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_not_get_top_element_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(stringStack.GetTopElement(), std::underflow_error);
		}

		BOOST_AUTO_TEST_CASE(can_not_pop_elements_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(stringStack.Pop(), std::underflow_error);
		}

		BOOST_AUTO_TEST_CASE(can_push_elements)
		{
			stringStack.Push("42");
			BOOST_CHECK(!stringStack.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_there_are_elements)

		BOOST_AUTO_TEST_CASE(can_pop_elements)
		{
			stringStack.Push("42");
			stringStack.Pop();
			BOOST_CHECK(stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_get_top_element)
		{
			stringStack.Push("push");
			BOOST_CHECK_EQUAL(stringStack.GetTopElement(), "push");
		}

		BOOST_AUTO_TEST_CASE(can_get_size_of_stack)
		{
			stringStack.Push("push");
			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(1));
		}

		BOOST_AUTO_TEST_CASE(can_delete_all_elements_in_stack)
		{
			stringStack.Push("a");
			stringStack.Push("b");
			stringStack.Push("c");

			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(3));

			stringStack.Clear();
			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(0));
		}

		BOOST_AUTO_TEST_CASE(can_be_copied)
		{
			// by constructor
			{
				stringStack.Push("a");
				stringStack.Push("b");
				stringStack.Push("c");

				CStringStack newStringStack = stringStack;

				BOOST_CHECK_EQUAL(stringStack.GetSize(), newStringStack.GetSize());
				for (size_t i = 0; i < stringStack.GetSize(); ++i)
				{
					BOOST_CHECK_EQUAL(stringStack.GetSize(), newStringStack.GetSize());
					stringStack.Pop();
					newStringStack.Pop();
				}
			}

			// by assignment operator
			{	
				stringStack.Push("a");
				stringStack.Push("b");
				stringStack.Push("c");

				CStringStack newStringStack;
				newStringStack = stringStack;

				BOOST_CHECK_EQUAL(stringStack.GetSize(), newStringStack.GetSize());
				while (!stringStack.IsEmpty())
				{
					BOOST_CHECK_EQUAL(stringStack.GetTopElement(), newStringStack.GetTopElement());
					stringStack.Pop();
					newStringStack.Pop();
				}
			}
		}

		BOOST_AUTO_TEST_CASE(can_be_moved)
		{
			// by constructor
			{
				stringStack.Push("a");
				stringStack.Push("b");
				stringStack.Push("c");

				size_t oldSize = stringStack.GetSize();

				CStringStack copy = stringStack;
				CStringStack acceptor = std::move(stringStack);

				BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(0));
				BOOST_CHECK_EQUAL(copy.GetSize(), oldSize);
				BOOST_CHECK_EQUAL(acceptor.GetSize(), oldSize);

				while (!copy.IsEmpty())
				{
					BOOST_CHECK_EQUAL(copy.GetTopElement(), acceptor.GetTopElement());
					copy.Pop();
					acceptor.Pop();
				}
			}

			// by assignment operator
			{
				stringStack.Push("a");
				stringStack.Push("b");
				stringStack.Push("c");

				size_t oldSize = stringStack.GetSize();

				CStringStack copy = stringStack;
				CStringStack acceptor;
				acceptor = std::move(stringStack);

				BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(0));
				BOOST_CHECK_EQUAL(copy.GetSize(), oldSize);
				BOOST_CHECK_EQUAL(acceptor.GetSize(), oldSize);

				while (!copy.IsEmpty())
				{
					BOOST_CHECK_EQUAL(copy.GetTopElement(), acceptor.GetTopElement());
					copy.Pop();
					acceptor.Pop();
				}
			}
		}

		BOOST_AUTO_TEST_CASE(can_not_be_moved_by_itself)
		{
			// copy
			{
				CStringStack stack1;
				CStringStack stack2;

				stack1.Push("a");
				stack1.Push("b");
				stack1.Push("c");

				stack2 = stack1;
				stack1 = stack2;

				BOOST_CHECK_EQUAL(stack1.GetSize(), stack2.GetSize());

				while (!stack1.IsEmpty())
				{
					BOOST_CHECK_EQUAL(stack1.GetTopElement(), stack2.GetTopElement());
					stack1.Pop();
					stack2.Pop();
				}
			}

			// move
			{
				CStringStack stack1;
				CStringStack stack2;

				size_t amount = 3;

				stack1.Push("a");
				stack1.Push("b");
				stack1.Push("c");

				stack2 = std::move(stack1);
				stack1 = std::move(stack2);

				BOOST_CHECK_EQUAL(stack1.GetSize(), amount);
				BOOST_CHECK(stack2.IsEmpty());

				BOOST_CHECK_EQUAL(stack1.GetTopElement(), "c");
				stack1.Pop();
				BOOST_CHECK_EQUAL(stack1.GetTopElement(), "b");
				stack1.Pop();
				BOOST_CHECK_EQUAL(stack1.GetTopElement(), "a");
				stack1.Pop();
			}
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()