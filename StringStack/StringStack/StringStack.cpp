#include "stdafx.h"
#include "StringStack.h"

CStringStack::CStringStack() = default;

CStringStack::CStringStack(const CStringStack &stack)
{
	*this = stack;
}

CStringStack::CStringStack(CStringStack &&stack)
{
	*this = std::move(stack);
}

CStringStack::~CStringStack()
{
	Clear();
}

void CStringStack::Push(const std::string &string)
{
	Node *newNode = new Node(string);
	newNode->next = m_top;
	m_top = newNode;
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::underflow_error("Can't pop element from empty stack");
	}

	Node *node = m_top;
	m_top = m_top->next;
	delete node;
	--m_size;
}

std::string CStringStack::GetTopElement() const
{
	if (IsEmpty())
	{
		throw std::underflow_error("Can't get last element from empty stack");
	}
	return m_top->data;
}


size_t CStringStack::GetSize() const
{
	return m_size;
}

void CStringStack::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

bool CStringStack::IsEmpty() const
{
	return m_size == 0;
}

CStringStack & CStringStack::operator =(const CStringStack &stack)
{
	if (std::addressof(stack) != this)
	{
		if (!stack.IsEmpty())
		{
			Node *tempNode = stack.m_top;
			Node *tempStack = new Node(tempNode->data);
			Node *headTempStack = tempStack;
			tempNode = tempNode->next;
			try
			{
				while (tempNode != nullptr)
				{
					tempStack->next = new Node(tempNode->data);

					tempStack = tempStack->next;
					tempNode = tempNode->next;
				}
			}
			catch (...)
			{
				while (headTempStack != nullptr)
				{
					Node *deleteNode = headTempStack;
					headTempStack = headTempStack->next;
					delete deleteNode;
				}
			}
			Clear();
			m_top = headTempStack;
			m_size = stack.GetSize();
		}
	}

	return *this;
}

CStringStack & CStringStack::operator =(CStringStack &&stack)
{
	if (std::addressof(stack) != this)
	{
		Node *temp_m_top = m_top;
		size_t temp_m_size = m_size;

		Node *stack_m_top = stack.m_top;
		size_t stack_m_size = stack.m_size;

		try
		{
			m_top = stack.m_top;
			m_size = stack.m_size;
			stack.m_top = nullptr;
			stack.m_size = 0;
		}
		catch (...)
		{
			m_top = temp_m_top;
			m_size = temp_m_size;
			stack.m_top = stack_m_top;
			stack.m_size = stack_m_size;
		}

		while (temp_m_top != nullptr)
		{
			Node *deleteNode = temp_m_top;
			temp_m_top = temp_m_top->next;
			delete deleteNode;
		}
	}

	return *this;
}