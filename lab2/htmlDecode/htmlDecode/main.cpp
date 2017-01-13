#include "stdafx.h"
#include "htmlDecode.h"

using namespace std;

int main()
{
	string htmlLine, result = "";

	cout << "Enter your HTML text for decode: \n";

	while (getline(cin, htmlLine))
	{
		result += HtmlDecode(htmlLine) + '\n';
	}
	cout << "Decoded: \n" << result << endl;

    return 0;
}

