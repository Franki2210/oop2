#include "stdafx.h"
#include "htmlDecode.h"
#include <map>
#include <vector>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

const string HTML_CHARS[5][2] = { { "&quot;", "\"" },
								{ "&apos;", "'" },
								{ "&lt;", "<" },
								{ "&gt;", ">" },
								{ "&amp;", "&" } };

bool ReplaceHtmlChar(const string &htmlLine, string &result, size_t &cursorPosition)
{
	bool replaced = false;
	for (int i = 0; i < 5; ++i)
	{
		if (htmlLine.find(HTML_CHARS[i][0].c_str(), cursorPosition, HTML_CHARS[i][0].length()) == cursorPosition)
		{
			result += HTML_CHARS[i][1];
			cursorPosition += HTML_CHARS[i][0].size() - 1;
			replaced = true;
		}
	}
	return replaced;
}

string HtmlDecode(const string &htmlLine)
{
	string resultLine;
	resultLine.reserve(htmlLine.length());

	for (size_t i = 0; i < htmlLine.length(); ++i)
	{
		bool decoded = false;
		if (htmlLine[i] == '&')
		{
			decoded = ReplaceHtmlChar(htmlLine, resultLine, i);
		}
		if (!decoded)
		{
			resultLine += htmlLine[i];
		}
	}

	return resultLine;
}