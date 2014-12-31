#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H
#include "serializable.h"

class SimpleClass : public Serializable
{
public:
    int iProp;
    float fProp;
    char cProp;

    SimpleClass();
    SimpleClass(int, float, char);

    void serialize(const char* fname);
    void deserialize(const char* fname);
};

#endif
