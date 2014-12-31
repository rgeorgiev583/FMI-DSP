#include "simpleclass.h"

int main()
{
    SimpleClass so(1, 3.14f, 'x');
    so.serialize("so.txt");
    so.iProp = 2;
    SimpleClass so2;
    so2.deserialize("so.txt");
    return 0;
};
