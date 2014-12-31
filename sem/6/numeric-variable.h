/*
 * numeric-variable.h
 *
 *  Created on: Nov 11, 2014
 *      Author: radoslav
 */

#ifndef NUMERIC_VARIABLE_H_
#define NUMERIC_VARIABLE_H_

#include "variable.h"

class NumericVariable: public Variable
{
	int value;

public:
	NumericVariable(): value(0) {}
	NumericVariable(int _value): value(_value) {}

	std::string toString() const;
	void fromString(const std::string&);

	int getValue() const { return value; }
	void setValue(int _value) { value = _value; }
};



#endif /* NUMERIC_VARIABLE_H_ */
