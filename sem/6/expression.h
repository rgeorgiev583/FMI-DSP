/*
 * expression.h
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>

class Expression
{
public:
	virtual ~Expression() {}

	virtual int evaluate() const = 0;
};



#endif /* EXPRESSION_H_ */
