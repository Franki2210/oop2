#include "stdafx.h"
#include "StringStack.h"

CStringStack::CStringStack()
	: m_top(nullptr)
	, m_size(0)
{
}

CStringStack::~CStringStack() noexcept
{
	Node *currentNode = m_top;

	while (currentNode != nullptr)
	{
		Node *next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}

	m_top = nullptr;
}

void CStringStack::Push(const std::string &string)
{

	Node *newNode = new Node;
	newNode->data = string;

	if (m_top != nullptr)
	{
		newNode->next = m_top;
	}
	else
	{
		newNode->next = nullptr;
	}

	m_top = newNode;
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::domain_error("Can't pop last element from empty stack");
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
		throw std::domain_error("Can't get last element from empty stack");
	}
	return m_top->data;
}


size_t CStringStack::GetSize() const
{
	return m_size;
}

bool CStringStack::IsEmpty() const
{
	return m_size == 0;
}