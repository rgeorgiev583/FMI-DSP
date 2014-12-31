/*
 * string-variable.h
 *
 *  Created on: Nov 11, 2014
 *      Author: radoslav
 */

#ifndef STRING_VARIABLE_H_
#define STRING_VARIABLE_H_

#include "variable.h"

class StringVariable: public Variable
{
	std::string s;

public:
	StringVariable() {}
	StringVariable(const std::string& _s): s(_s) {}

	std::string toString() const { return s; }
	void fromString(const std::string& _s) { s = _s; }

	std::string getValue() const { return s; }
	void setValue(const std::string& _s) { s = _s; }
};


#endif /* STRING_VARIABLE_H_ */
