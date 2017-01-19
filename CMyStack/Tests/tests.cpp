#include "stdafx.h"
#include "../CMyStack/CMyStack.h"

struct EmptyStack
{
	CMyStack<std::string> stringStack;
	CMyStack<int> intStack;
};

BOOST_FIXTURE_TEST_SUITE(Stack, EmptyStack)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty_by_default)
		{
			BOOST_CHECK(stringStack.IsEmpty());
			BOOST_CHECK(intStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_not_get_top_element_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(intStack.GetTopElement(), std::underflow_error);
			BOOST_CHECK_THROW(stringStack.GetTopElement(), std::underflow_error);
		}

		BOOST_AUTO_TEST_CASE(can_not_pop_elements_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(intStack.Pop(), std::underflow_error);
			BOOST_CHECK_THROW(stringStack.Pop(), std::underflow_error);
		}

		BOOST_AUTO_TEST_CASE(can_push_elements)
		{
			intStack.Push(12);
			BOOST_CHECK(!intStack.IsEmpty());

			stringStack.Push("42");
			BOOST_CHECK(!stringStack.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_there_are_elements)

		BOOST_AUTO_TEST_CASE(can_pop_elements)
		{
			intStack.Push(19);
			intStack.Pop();
			BOOST_CHECK(intStack.IsEmpty());

			stringStack.Push("42");
			stringStack.Pop();
			BOOST_CHECK(stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_get_top_element)
		{
			intStack.Push(42);
			BOOST_CHECK_EQUAL(intStack.GetTopElement(), 42);

			stringStack.Push("push");
			BOOST_CHECK_EQUAL(stringStack.GetTopElement(), "push");
		}

		BOOST_AUTO_TEST_CASE(can_get_size_of_stack)
		{
			intStack.Push(1);
			BOOST_CHECK_EQUAL(intStack.GetSize(), 1);

			stringStack.Push("push");
			BOOST_CHECK_EQUAL(stringStack.GetSize(), 1);
		}

		BOOST_AUTO_TEST_CASE(can_delete_all_elements_in_stack)
		{
			for (int i = 0; i < 5; ++i)
			{
				intStack.Push(i);
			}
			BOOST_CHECK_EQUAL(intStack.GetSize(), 5);

			intStack.Clear();
			BOOST_CHECK_EQUAL(intStack.GetSize(), 0);

			for (size_t i = 0; i < 5; ++i)
			{
				stringStack.Push("42");
			}
			BOOST_CHECK_EQUAL(stringStack.GetSize(), 5);

			stringStack.Clear();
			BOOST_CHECK_EQUAL(stringStack.GetSize(), 0);
		}

		BOOST_AUTO_TEST_CASE(can_be_copied)
		{
			// by constructor
			{
				for (int i = 0; i < 10; ++i)
				{
					intStack.Push(i);
				}
				CMyStack<int> newIntStack = intStack;

				BOOST_CHECK_EQUAL(intStack.GetSize(), newIntStack.GetSize());
				for (std::size_t i = 0; i < intStack.GetSize(); ++i)
				{
					BOOST_CHECK_EQUAL(intStack.GetSize(), newIntStack.GetSize());
					intStack.Pop();
					newIntStack.Pop();
				}
			}

			// by assignment operator
			{
				for (int i = 0; i < 10; ++i)
				{
					intStack.Push(i);
				}
				CMyStack<int> newIntStack;
				newIntStack = intStack;

				BOOST_CHECK_EQUAL(intStack.GetSize(), newIntStack.GetSize());
				while (!intStack.IsEmpty())
				{
					BOOST_CHECK_EQUAL(intStack.GetTopElement(), newIntStack.GetTopElement());
					intStack.Pop();
					newIntStack.Pop();
				}
			}
		}

		BOOST_AUTO_TEST_CASE(can_be_moved)
		{
			// by constructor
			{
				for (int i = 0; i < 10; ++i)
				{
					intStack.Push(i);
				}
				std::size_t oldSize = intStack.GetSize();

				CMyStack<int> copy = intStack;
				CMyStack<int> acceptor = std::move(intStack);

				BOOST_CHECK_EQUAL(intStack.GetSize(), 0);
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
				for (int i = 0; i < 10; ++i)
				{
					intStack.Push(i);
				}
				std::size_t oldSize = intStack.GetSize();

				CMyStack<int> copy = intStack;
				CMyStack<int> acceptor;
				acceptor = std::move(intStack);

				BOOST_CHECK_EQUAL(intStack.GetSize(), 0);
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
				CMyStack<int> stack1;
				CMyStack<int> stack2;

				for (int i = 0; i < 10; ++i)
				{
					stack1.Push(i);
				}

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
				CMyStack<int> stack1;
				CMyStack<int> stack2;

				int amount = 10;

				for (int i = 0; i < amount; ++i)
				{
					stack1.Push(i);
				}

				stack2 = std::move(stack1);
				stack1 = std::move(stack2);

				BOOST_CHECK_EQUAL(stack1.GetSize(), amount);
				BOOST_CHECK(stack2.IsEmpty());

				while (!stack1.IsEmpty())
				{
					BOOST_CHECK_EQUAL(stack1.GetTopElement(), amount - 1);
					stack1.Pop();
					--amount;
				}
			}
		}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()