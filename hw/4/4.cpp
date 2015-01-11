#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "intfunction.h"

using namespace std;

int main(int argc, char** argv)
{
    ifstream fin;

    if (argc >= 2)
        fin.open(argv[1]);
        
    istream* pin = fin.is_open() ? &fin : &cin;
    istream& in = *pin;

    int a, b;
    in >> a >> b; if (!in) { return 1; }
    in.ignore();

    vector<IntFunction> fs;
    string s;
    getline(in, s);

    while (!in.eof() && !s.empty())
    {
        fs.push_back(IntFunction(s));
        getline(in, s);
    }

    vector<int> vals;
    size_t nfs = fs.size();

    for (int i = a; i <= b; i++)
    {
        for (size_t j = 0; j < nfs; j++)
            vals.push_back(fs[j].calculate(i));

        bool eq = false;
        size_t eqval;
        vector<bool> eqs(nfs - 1, false);
        
        for (size_t j = 0; j < nfs - 1; j++)
            if (!j || !eqs[j - 1])
                for (size_t k = j + 1; k < nfs; k++)
                    if (vals[j] == vals[k])
                    {
                        if (!eq)
                        {
                            cout << fs[j].getName() << '(' << i << ") = ";
                            eqval = vals[j];
                            eq = true;
                        }

                        cout     << fs[k].getName() << '(' << i << ") = ";
                        eqs[k - 1] = true;
                    }

        if (eq)
            cout << eqval << endl;

        vals.clear();
    }

    if (fin.is_open())
        fin.close();

    return 0;
}
