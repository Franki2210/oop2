#pragma once

class CStringStack
{
	struct Node
	{
		std::string data;
		Node *next;
	};
public:
	CStringStack();
	~CStringStack() noexcept;

	void Push(const std::string &string);
	void Pop();
	std::string GetTopElement() const;
	size_t GetSize() const;
	bool IsEmpty() const;

private:
	Node *m_top = nullptr;
	int m_size = 0;
};