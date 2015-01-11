#include "exprcalc.h"
#include "lstack.cpp"
#include <cstdlib>
#include <sstream>

int priority(char op)
{
	switch (op)
    {
        case '+': case '-':           return 1;
        case '*': case '/': case '%': return 2;
        case '^':                     return 3;
        default:                      return -1;
	}
}

int ipow(int a, int n)
{
    if (a == 0)
        return 0;
    else if (a == 1 || n <= 0)
        return 1;
    else if (n % 2)
        return a * ipow(a, n - 1);
    else
    {
        int b = ipow(a, n / 2);
        return b * b;
    }
}

void apply_operation(LinkedStack<int>& rstack, char op)
{
	int r = rstack.pop();
    int l = rstack.pop();

	switch (op)
    {
        case '+': rstack.push(l + r);    break;
        case '-': rstack.push(l - r);    break;
        case '*': rstack.push(l * r);    break;
        case '/': rstack.push(l / r);    break;
        case '^': rstack.push(ipow(l,r)); break;
	}
}

int calculate_expr(const char* expr)
{
	LinkedStack<char> opstack;
	LinkedStack<int> rstack;

	while (*expr)
    {
		if (    *expr >= '0' && *expr <= '9' ||
                *expr == '-' && *(expr + 1) >= '0' && *(expr + 1) <= '9'    )
        {
			rstack.push(atoi(expr));

            while (*expr && *(expr + 1) >= '0' && *(expr + 1) <= '9')
                expr++;
        }
		else if (*expr == '(')
			opstack.push(*expr);
		else if (*expr == ')')
        {
			char op = opstack.pop();

			while (op != '(') {
				apply_operation(rstack, op);
				op = opstack.pop();
			}

			/*
			while ((op = opstack.pop()) != '(')
				*rpn++ = op;
		    */
		}
        else if (*expr != ' ' && *expr != '\t')
        {
			// *expr е операция
			// първо: вадим всички операции
			// с по-висок или равен приоритет
			while (!opstack.empty() &&
				   priority(opstack.last()) >=
				   priority(*expr))
				apply_operation(rstack,opstack.pop());

			opstack.push(*expr);
		}
		expr++;
	}

	while (!opstack.empty())
		apply_operation(rstack, opstack.pop());

	return rstack.pop();
}

char* strshift(char* str, size_t n)
{
    if (!str || !*str)
        return str;

    char* i = str;

    while (*i)
        i++;

    while (i != str - 1)
    {
        *(i + n) = *i;
        i--;
    }

    return str + n;
}

char* itonstr(int n, char* str)
{
    if (n == 0)
        *str = '0';
    else
    {
        size_t len = 0;
        int t = n;

        while (t)
        {
            t /= 10;
            len++;
        }

        if (n < 0)
        {
            *str = '-';
            len++;
        }

        strshift(str, len);
        char* i = str + len - 1;

        while (i >= str && n)
        {
            *i = '0' + n % 10;
            n /= 10;
            i--;
        }
    }

    return str;
}

char* strsubst(char* str, char ch, int subst)
{
    char* i = str;

    while (*i)
    {
        if (*i == ch)
            itonstr(subst, str);

        i++;
    }

    return str;
}

std::string& substitute(std::string& s, char ch, const std::string& subst)
{
    size_t pos = s.find(ch);

    while (pos != std::string::npos)
    {
        s.replace(pos, 1, subst);
        pos = s.find(ch, pos + 1);
    }

    return s;
}

std::string& interpolate(std::string& s, char ch, int arg)
{
    std::ostringstream argout;
    argout << arg;
    return substitute(s, ch, argout.str());
}

const char* find_token(const char* str)
{
    if (!str)
        return NULL;

    while (*str && *str == ' ' && *str == '\t')
        str++;

    return *str && *str != ' ' && *str != '\t' ? str : NULL;
}

bool is_alpha(char ch)
{
    return ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z';
}
