/*
 * language-parser.h
 *
 *  Created on: Nov 11, 2014
 *      Author: radoslav
 */

#ifndef LANGUAGE_PARSER_H_
#define LANGUAGE_PARSER_H_

#include <iostream>
#include <sstream>

class LanguageParser
{
	std::istream& in;
	Variable* vars[26];
	size_t var_count;

public:
	LanguageParser(const std::string& code = std::string());
	LanguageParser(std::istream& sin);

	bool parseLine();
};



#endif /* LANGUAGE_PARSER_H_ */
