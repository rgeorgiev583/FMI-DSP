/*
 * constant.h
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include <cstdlib>

class Constant : Expression
{
	int value;

public:
	Constant(int _value = 0) { value = _value; }
	Constant(const char* rpn) { value = atoi(rpn); }

	int evaluate() const { return value; }
};



#endif /* CONSTANT_H_ */
