#pragma once

template <typename T>
class CMyStack
{
	struct Node
	{
		Node(const T & data)
			:data(data)
			, next(nullptr)
		{};
		T data;
		Node *next;
	};
public:
	CMyStack() = default;

	CMyStack(CMyStack<T> const & stack)
	{
		*this = stack;
	}

	CMyStack(CMyStack<T> && stack)
	{
		*this = std::move(stack);
	}

	~CMyStack()
	{
		Clear();
	}

	void Push(const T & data)
	{
		Node *node = new Node(data);
		node->next = m_top;
		m_top = node;
		++m_size;
	}

	void Pop()
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

	T GetTopElement() const
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Can't get element from empty stack");
		}

		return m_top->data;
	}

	bool IsEmpty() const
	{
		return m_size == 0;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	std::size_t GetSize() const
	{
		return m_size;
	}

	CMyStack & operator =(const CMyStack<T> & stack)
	{
		if (std::addressof(stack) != this)
		{
			Copy(stack);
		}

		return *this;
	}

	CMyStack & operator =(CMyStack && stack)
	{
		if (std::addressof(stack) != this)
		{
			Clear();
			m_top = stack.m_top;
			m_size = stack.m_size;
			stack.m_top = nullptr;
			stack.m_size = 0;
		}

		return *this;
	}

private:
	void Copy(const CMyStack<T> & stack)
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
				Clear();
				m_top = headTempStack;
				m_size = stack.GetSize();
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
		}
		else
		{
			Clear();
		}
	}

	Node *m_top = nullptr;
	size_t m_size = 0;
};