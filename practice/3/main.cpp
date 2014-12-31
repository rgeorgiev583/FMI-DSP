#include <iostream>
#include <fstream>
#include "MyClassA.h"
#include "MyClassB.h"
using namespace std;

int main()
{
    MyClassA a(1, 'a');
    ofstream ofs("out.txt");
    ofs.write((const char*)& a, sizeof(a));
    ofs.close();

    MyClassA m(2, 'b');
    ifstream ifs("out.txt");
    ifs.read((char*)& m, sizeof(m));
    ifs.close();
    cout << m.b << ' ' << m.c << endl;
    cout << a;

    int arr[10];

    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    MyClassA objw(1, 'a');
    MyClassB objw2(objw, arr);
    ofstream f("out2.txt");
    f.write((const char*)& objw2, sizeof(objw2));
    f.close();

    int b[10];

    MyClassA objr(2, 'b');
    MyClassB objr2(objr, b);
    ifstream f2("out2.txt");
    f2.read((char*)& objr2, sizeof(objr2));
    f2.close();
    cout << objr << objr2;

    ofstream f3("out3.txt");

    for (size_t i = 0; i < 10; i++)
    {
        f3.write((const char*)& objr2, sizeof(objr2));
    }

    MyClassB obj3(MyClassA(3, 'c'), arr);
    f3.write((const char*)& obj3, sizeof(obj3));
    f3.close();
    ifstream is("out3.txt");
    is.seekg(10 * sizeof(obj3), is.beg);

    MyClassB obj4;
    is.read((char*)& obj4, sizeof(obj4));
    is.close();

    cout << obj4;

    return 0;
}

