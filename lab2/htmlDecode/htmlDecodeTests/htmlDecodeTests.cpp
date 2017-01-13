#include "stdafx.h"
#include "..\htmlDecode\htmlDecode.h"

using namespace std;

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(Html_Decode_function)

	BOOST_AUTO_TEST_CASE(decode_empty_string)
	{
		string emptyString = "";
		BOOST_CHECK_EQUAL(HtmlDecode(emptyString), "");
	}
	
	BOOST_AUTO_TEST_CASE(decode_string_without_html_chars)
	{
		string inputString = "Cat <says> \"Meow\". M&M's";
		const string correctDecodeString = "Cat <says> \"Meow\". M&M's";
		BOOST_CHECK_EQUAL(HtmlDecode(inputString), correctDecodeString);
	}

	BOOST_AUTO_TEST_CASE(decode_correct_string_with_html_character)
	{
		string inputString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
		const string correctDecodeString = "Cat <says> \"Meow\". M&M's";
		BOOST_CHECK_EQUAL(HtmlDecode(inputString), correctDecodeString);
	}

BOOST_AUTO_TEST_SUITE_END()


