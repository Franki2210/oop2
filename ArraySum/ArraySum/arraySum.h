#pragma once

#include <vector>

template <typename T>
T ArraySum(std::vector<T> const& arr)
{
	T sum = T();
	if (!arr.empty())
	{
		for (auto &element : arr)
		{
			sum += element;
		}
	}
	return sum;
}
