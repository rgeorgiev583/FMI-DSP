#include <iostream>
#include <fstream>
#include "nstream.h"
#include "evennstream.h"
#include "oddnstream.h"
#include "fibnstream.h"
using namespace std;

int main()
{
    NStream ns;
    ofstream fout("test.txt");
    int x, y;
    ns >> x;
    ns >> x;
    ns >> y;
    ns >> x;
    cout << x << endl << y << endl;
    ns >> cout;
    ns >> fout;
    fout << " ";
    ns >> fout;
    fout << " ";
    ns >> fout;
    fout << " ";
    ns >> fout;
    fout << " ";
    fout << endl;

    EvenNStream ens;
    ens >> fout;
    fout << " ";
    ens >> fout;
    fout << " ";
    ens >> fout;
    fout << " ";
    ens >> fout;
    fout << " ";
    fout << endl;

    OddNStream ons;
    ons >> fout;
    fout << " ";
    ons >> fout;
    fout << " ";
    ons >> fout;
    fout << " ";
    ons >> fout;
    fout << " ";
    fout << endl;

    FibNStream fns;
    fns >> fout;
    fout << " ";
    fns >> fout;
    fout << " ";
    fns >> fout;
    fout << " ";
    fns >> fout;
    fout << " ";
    fout << endl;

    PrimeNStream fns;
    fns >> fout;
    fout << " ";
    fns >> fout;
    fout << " ";
    fns >> fout;
    fout << " ";
    fns >> fout;
    fout << " ";
    fout << endl << endl;

    fout << ons + fns << endl;

    fout.close();
}
