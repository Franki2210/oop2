#pragma once

#include <iostream>
#include <vector>

#include <algorithm>
#include <numeric>
#include <functional>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

void ProcessVector(vector<double> & numbers);