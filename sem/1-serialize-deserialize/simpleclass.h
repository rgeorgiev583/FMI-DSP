#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H
#include "serializable.h"

class SimpleClass : public Serializable
{
public:
    int iProp;
    float fProp;
    char cProp;
    int* arriProp;
    size_t sizeArri;

    SimpleClass();
    SimpleClass(int, float, char, int*, int);

    void serialize(const char* fname);
    void deserialize(const char* fname);
};

#endif
