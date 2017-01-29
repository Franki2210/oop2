#pragma once
#include "stdafx.h"

const std::string EXIT = "...";
typedef std::map<std::string, std::string> Dictionary;

bool IsEmptyFile(std::ifstream & file);
Dictionary GetDictionaryFromFile(const std::string & fileName);
std::string ToLower(std::string input);
std::string FindTranslation(std::string & inputString, const Dictionary & dictionary);
void AddNewTranslation(const std::string & word, std::string & translationWord, Dictionary & dictionary);
void SaveDictionaryToFile(const std::string & dictionaryFileName, Dictionary & dictionary);
void RequestToSaveDictionaryFile(std::istream & input, std::ostream & output, const std::string &dictionaryFileName, Dictionary &dictionary);
void ProcessingUserInput(std::istream & input, std::ostream & output, std::string & inputString, Dictionary & dictionary, bool & dictionaryHasChanged);
void EnterTranslationLoop(const std::string & dictionaryFileName, std::istream & input, std::ostream & output);