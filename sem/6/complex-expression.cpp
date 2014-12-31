/*
 * complex-expression.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: radoslav
 */

#include <stack>

#include "constant.h"
#include "complex-expression.h"

int ComplexExpression::evaluate() const
{
	size_t pos = 0;
	std::stack<double> s;

	while (pos < rpn.length())
	{
		if (rpn[pos] >= '0' && rpn[pos] <= '9')
			s.push(rpn[pos] - '0');
		else
		{
			double r = s.pop();
			double l = s.pop();

			switch (rpn[pos])
			{
				case '+':s.push(l + r);break;
				case '-':s.push(l - r);break;
				case '*':s.push(l * r);break;
				case '/':s.push(l / r);break;
			}
		}

		pos++;
	}

	return s.pop();
}

int priority(char op)
{
	switch (op)
	{
		case '+':
		case '-': return  1;
		case '*':
		case '/': return  2;
		default:  return -1;
	}
}

Expression* deserialize(const std::string& expr)
{
	std::stack<char> opstack;
	std::string rpn;
	size_t pos = 0;
	bool complex = false;

	while (pos < expr.length())
	{
		if (expr[pos] >= '0' && expr[pos] <= '9' || expr[pos] >= 'a' && expr[pos] <= 'z')
		{
			rpn += expr[pos];
		}
		else if (expr[pos] == '(')
		{
			opstack.push(expr[pos]);
			complex = true;
		}
		else if (expr[pos] == ')')
		{
			char op = opstack.pop();
			while (op != '(')
			{
				rpn += op;
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
				   priority(expr[pos]))
				rpn += opstack.pop();
			opstack.push(expr[pos]);
			complex = true;
		}
		pos++;
	}

	while (!opstack.empty())
		rpn += opstack.pop();

	return complex ? new ComplexExpression(rpn) : new Constant(rpn);
}
