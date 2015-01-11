#include "intfunction.h"
#include "exprcalc.h"
#include <cstring>

const size_t MAX_SIZE = 1000;

void IntFunction::copy(const IntFunction& other)
{
    name = other.name;
    param = other.param;

    expr = new char[strlen(other.expr) + 1];
    strcpy(expr, other.expr);
}

void IntFunction::destroy()
{
    delete[] expr;
}

bool IntFunction::parse(const char* dfn)
{
    // първо извличаме името (латинска буква)
    const char* i = find_token(dfn);
    if (!i || !is_alpha(*i))
        return false;
    name = *i;
    i++;

    // после извличаме '('
    i = find_token(i);
    if (!i || *i != '(')
        return false;
    i++;

    // след това извличаме името на аргумента
    i = find_token(i);
    if (!i || !is_alpha(*i))
        return false;
    param = *i;
    i++;

    // после извличаме ')'
    i = find_token(i);
    if (!i || *i != ')')
        return false;
    i++;

    // след това извличаме '='
    i = find_token(i);
    if (!i || *i != '=')
        return false;
    i++;

    // и накрая копираме израза в полето expr
    i = find_token(i);
    expr = new char[strlen(i) + 1];
    strcpy(expr, i);
    return true;
}

IntFunction::IntFunction(std::istream& in)
{
    char strin[MAX_SIZE];
    in.getline(strin, MAX_SIZE);
    parse(strin);
}

IntFunction::IntFunction(const char* dfn)
{
    parse(dfn);
}

IntFunction::IntFunction(const std::string& s)
{
    parse(s.c_str());
}

IntFunction::IntFunction(const IntFunction& other)
{
    copy(other);
}

IntFunction& IntFunction::operator=(const IntFunction& other)
{
    if (&other != this)
    {
        destroy();
        copy(other);
    }

    return *this;
}

IntFunction::~IntFunction()
{
    destroy();
}

int IntFunction::calculate(int arg) const
{
    strsubst(expr, param, arg);
    return calculate_expr(expr);
}
