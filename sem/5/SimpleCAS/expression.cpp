/*
 * expression.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#include <cstring>
#include <stack>

#include "expression.h"

Expression::Expression(const char* _rpn = NULL)
{
	size_t _len = strlen(_rpn);
	rpn = new char[_len + 1];
	strcpy(rpn, _rpn);
	len = _len;
}

Expression::Expression(const Expression& other)
{
	rpn = new char[other.len + 1];
	strcpy(rpn, other.rpn);
	len = other.len;
}

Expression& Expression::operator=(const Expression& other)
{
	if (&other != this)
	{
		destroy();
	}
}

int priority(char op) {
	switch (op)
	{
		case '+':
		case '-': return  1;
		case '*':
		case '/': return  2;
		default:  return -1;
	}
}
