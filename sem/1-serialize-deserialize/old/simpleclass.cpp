#include <fstream>
#include "simpleclass.h"
using std::ofstream;
using std::ifstream;
using std::endl;

void SimpleClass::serialize(const char* fname)
{
    ofstream fout(fname);
    fout << iProp << endl << fProp << endl << cProp;
    fout.close();
}

void SimpleClass::deserialize(const char* fname)
{
    ifstream fin(fname);
    fin >> iProp >> fProp >> cProp;
    fin.close();
}

SimpleClass::SimpleClass() {}

SimpleClass::SimpleClass(int i, float f, char c):
        iProp(i), fProp(f), cProp(c) {}
