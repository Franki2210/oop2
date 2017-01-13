#include "stdafx.h"
#include "VectorProcessor.h"


using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;
using boost::transform;

void ProcessVector(vector<double> & numbers)
{
	if (!numbers.empty())
	{
		auto maxNumber = max_element(numbers.begin(), numbers.end());
		boost::transform(numbers, numbers.begin(), arg1 / (*maxNumber / 2));
	}
}