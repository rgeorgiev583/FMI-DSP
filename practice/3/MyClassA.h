#pragma once
#include <iostream>
using std::ostream;
using std::endl;

class MyClassA
{
public:
    int b;
    char c;

    MyClassA() {}
    MyClassA(int _b, char _c)
    {
        b = _b;
        c = _c;
    }

    friend ostream& operator<<(ostream&, MyClassA&);
};

ostream& operator<<(ostream& os, MyClassA& obj)
{
    os << obj.b << endl;
    os << obj.c << endl;
    os << endl;
    return os;
}

