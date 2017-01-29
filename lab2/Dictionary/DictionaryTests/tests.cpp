#include "stdafx.h"
#include "../Dictionary/dictionary.h"

BOOST_AUTO_TEST_SUITE(dictionary_can)
	BOOST_AUTO_TEST_CASE(returns_translating_string_if_word_is_in_dictionary)
	{
		std::string word = "apple";
		Dictionary dictionary =
		{
			{ word, "€блоко" }
		};

		BOOST_CHECK_EQUAL(FindTranslation(word, dictionary), "€блоко");
	}

	BOOST_AUTO_TEST_CASE(returns_empty_string_if_word_is_not_in_dictionary)
	{
		std::string word = "banana";
		Dictionary dictionary =
		{
			{ "cat", "кошка" },
			{ "home", "дом" }
		};

		BOOST_CHECK_EQUAL(FindTranslation(word, dictionary), "");
	}

	BOOST_AUTO_TEST_CASE(add_new_words)
	{
		std::string word = "banana";
		std::string translatingWord = "банан";
		Dictionary dictionary;
		AddNewTranslation(word, translatingWord, dictionary);

		std::string findWord = "banana";
		BOOST_CHECK_EQUAL(FindTranslation(findWord, dictionary), "банан");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetDictionaryFromFile_function)
	BOOST_AUTO_TEST_CASE(returns_empty_dictionary_from_empty_file)
	{
		Dictionary dictionary;
		BOOST_CHECK(dictionary == GetDictionaryFromFile("empty.txt"));
	}

	BOOST_AUTO_TEST_CASE(returns_correct_dictionary_from_correct_file)
	{
		Dictionary dictionary =
		{
			{ "cat", "кошка" },
			{ "dog", "собака" }
		};

		BOOST_CHECK(dictionary == GetDictionaryFromFile("correct_dictionary.txt"));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SaveDictionaryInFile_function)
	BOOST_AUTO_TEST_CASE(saves_dictionary_changes_in_file_by_changing_file)
	{
		remove("dictionary.txt");
		std::string fileName = "dictionary.txt";

		Dictionary dictionary1 =
		{
			{ "mouse", "мышь" },
			{ "big", "большой" },
			{ "house", "дом" }
		};

		SaveDictionaryToFile(fileName, dictionary1);
		BOOST_CHECK(dictionary1 == GetDictionaryFromFile(fileName));
	}
BOOST_AUTO_TEST_SUITE_END()