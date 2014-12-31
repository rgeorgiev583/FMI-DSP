/*
 * numeric-variable.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: radoslav
 */

#include "numeric-variable.h"

std::string NumericVariable::toString() const
{
	std::ostringstream sout;
	sout << value;
	return sout.str();
}

void NumericVariable::fromString(const std::string& s)
{
	std::istringstream sin(s);
	sin >> value;
}
