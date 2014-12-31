#pragma once
#include <iostream>
#include "MyClassA.h"
using std::ostream;
using std::endl;

class MyClassB
{
public:
    MyClassA a;
    int b[10];

    MyClassB() {}
    MyClassB(MyClassA& _a, int _b[])
    {
        a = _a;
        
        for (size_t i = 0; i < 10; i++)
        {
            b[i] = _b[i];
        }
    }

    friend ostream& operator<<(ostream&, MyClassB&);
};

ostream& operator<<(ostream& os, MyClassB& obj)
{
    os << obj.a << endl;

    for (size_t i = 0; i < 10; i++)
    {
        os << obj.b[i] << endl;
    }

    os << endl;
    return os;
}

