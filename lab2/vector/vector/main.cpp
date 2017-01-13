#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

int main()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout << fixed << setprecision(3), ", "));
	return 0;
}