#include <fstream>
#include "simpleclass.h"
#define MAX_SIZE 1000
using std::ofstream;
using std::ifstream;
using std::endl;

void SimpleClass::serialize(const char* fname)
{
    ofstream fout(fname);
    fout << "iProp:" << iProp << endl;
    fout << "fProp:" << fProp << endl;
    fout << "cProp:" << cProp << endl;
    fout << "sizeArri:" << sizeArri << endl;
    fout << "arriProp:";

    for (size_t i = 0; i < sizeArri; i++)
    {
        fout << arriProp[i] << " ";
    }

    fout << endl;
    fout.close();
}

void SimpleClass::deserialize(const char* fname)
{
    ifstream fin(fname);
    const char* read[MAX_SIZE];
    fin >>
    fin >> iProp >> fProp >> cProp;
    fin.close();
}

SimpleClass::SimpleClass() {}

SimpleClass::SimpleClass(int i, float f, char c, int* ai, size_t sai):
        iProp(i), fProp(f), cProp(c), sizeArri(sai)
{
    arriProp = new int[sai];

    for (size_t i = 0; i < sai; i++)
    {
        arriProp[i] = ai[i];
    }
}
