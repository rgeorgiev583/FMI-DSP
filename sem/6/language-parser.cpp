/*
 * language-parser.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: radoslav
 */

#include "language-parser.h"

LanguageParser::LanguageParser(const std::string& code = std::string()): in(std::stringstream(code)), var_count(0)
{
	for (size_t i = 0; i < 26; i++)
	{
		vars[i] = NULL;
	}
}

LanguageParser::LanguageParser(std::istream& sin): in(sin), var_count(0)
{
	for (size_t i = 0; i < 26; i++)
	{
		vars[i] = NULL;
	}
}

bool LanguageParser::parseLine()
{
	std::string line;
	getline(in, line);

	std::istringstream lin;

	while (!lin.eof())
	{
		std::string token;
		char var;

		lin >> token;

		if (token[0] == "$")
		{

		}
		else
		{
			if (token == "Number" || token == "String")
			{
				std::string varname;
				lin >> varname;

				if (varname[0] < 'a' || varname[0] > 'z')
					return false;

				var = varname[0];
			}
			else if (token[0] >= 'a' && token[0] <= 'z')
			{
				var = token[0];
			}

			std::string equals_sign;
			lin >> equals_sign;

			if (equals_sign != "=")
				return false;

			std::string expr_ser;
			lin >> expr_ser;
			size_t expr_ser_len = expr_ser.length();

			if (expr_ser[expr_ser_len - 1] != '!')
				return false;

			if (expr_ser[0] == '"')
			{
				size_t rpos = expr_ser.find('"', 1);

				if (rpos == std::string::npos)
					return false;

				vars[var - 65] = new StringVariable(expr_ser.substr(1, rpos - 1));
			}
			else
			{
				Expression* expr = deserialize(expr_ser.substr(0, expr_ser_len - 1));
				vars[var - 65] = new NumericVariable(expr->evaluate());
				delete expr;
			}
		}
	}
}
