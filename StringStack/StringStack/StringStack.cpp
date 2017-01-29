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
			while (tempNode != nullptr)
			{
				tempStack->next = new Node(tempNode->data);

				tempStack = tempStack->next;
				tempNode = tempNode->next;
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
		m_top = stack.m_top;
		m_size = stack.m_size;
		stack.m_top = nullptr;
		stack.m_size = 0;
	}

	return *this;
}