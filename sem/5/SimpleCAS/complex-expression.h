/*
 * complex-expression.h
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#ifndef COMPLEX_EXPRESSION_H_
#define COMPLEX_EXPRESSION_H_

#include <stack>
#include "expression.h"

class ComplexExpression : Expression
{
public:
	ComplexExpression(const char* rpn = NULL)

	Expression* deserialize(const char* expr)
	{
		stack<char> opstack;
		char *rpn = new char[strlen(expr) + 1], *rpn_final = rpn;
		bool complex = false;

		while (*expr)
		{
			if (*expr >= '0' && *expr <= '9' || *expr >= 'a' && *expr <= 'z')
			{
				*rpn++ = *expr;
			}
			else if (*expr == '(')
			{
				opstack.push(*expr);
				complex = true;
			}
			else if (*expr == ')')
			{
				char op = opstack.pop();
				while (op != '(')
				{
					*rpn++ = op;
					op = opstack.pop();
				}
				complex = true;
			}
			else
			{
				// *expr е операция
				// първо: вадим всички операции
				// с по-висок или равен приоритет
				while (!opstack.empty() &&
					   priority(opstack.top()) >=
					   priority(*expr))
					*rpn++ = opstack.pop();
				opstack.push(*expr);
				complex = true;
			}
			expr++;
		}
		while (!opstack.empty())
			*rpn++ = opstack.pop();
		// терминираме низа
		*rpn = '\0';

		return complex ? new ComplexExpression(rpn_final) : new Constant(rpn_final);
	}

	int evaluate() const
	{
		char* rpni = rpn;
		stack<double> s;
		while (*rpni) {
			if (*rpni >= '0' && *rpni <= '9')
				s.push(*rpni-'0');
			else {
				double r = s.pop();
				double l = s.pop();

				switch (*rpni) {
					case '+':s.push(l + r);break;
					case '-':s.push(l - r);break;
					case '*':s.push(l * r);break;
					case '/':s.push(l / r);break;
				}
			}
			rpni++;
		}
		return s.pop();
	}
};


#endif /* COMPLEX_EXPRESSION_H_ */
