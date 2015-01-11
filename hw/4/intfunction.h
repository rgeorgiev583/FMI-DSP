#pragma once
#include <iostream>

class IntFunction
{
    char name, param;
    char* expr;

private:
    void copy(const IntFunction&);
    void destroy();

protected:
    bool parse(const char*);

public:
    IntFunction(std::istream& = std::cin);
    IntFunction(const char* str);
    IntFunction(const std::string& s);

    IntFunction(const IntFunction&);
    IntFunction& operator=(const IntFunction&);
    ~IntFunction();

    char getName()      const  { return name;  }
    char getParamName() const  { return param; }

    int calculate(int) const;
};
