/*
 * complex-expression.h
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#ifndef COMPLEX_EXPRESSION_H_
#define COMPLEX_EXPRESSION_H_

#include "expression.h"

class ComplexExpression : Expression
{
	std::string rpn;

public:
	ComplexExpression(const std::string& _rpn): rpn(_rpn) {}

	int evaluate() const;
};

int priority(char);
Expression* deserialize(const std::string&);

#endif /* COMPLEX_EXPRESSION_H_ */
