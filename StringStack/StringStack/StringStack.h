#pragma once

class CStringStack
{
	struct Node
	{
		Node(const std::string &data)
			:data(data)
			, next(nullptr)
		{};
		std::string data;
		Node *next;
	};
public:
	CStringStack();
	CStringStack(const CStringStack &stack);
	CStringStack(CStringStack &&stack);
	~CStringStack();

	void Push(const std::string &string);
	void Pop();
	std::string GetTopElement() const;
	size_t GetSize() const;
	void Clear();
	bool IsEmpty() const;
	CStringStack & operator =(const CStringStack &stack);
	CStringStack & operator =(CStringStack &&stack);
private:
	Node *m_top = nullptr;
	size_t m_size = 0;
};