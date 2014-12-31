/*
 * expression.h
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <cstddef>

class Expression
{
	char* rpn;
	size_t len;

	void copy(const Expre)
public:
	Expression(const char*);

	virtual int evaluate() const = 0;
	friend Expression* deserialize(const char*);
};



#endif /* EXPRESSION_H_ */
