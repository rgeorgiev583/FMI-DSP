#include <iostream>
#include <vector>
#include "intfunction.h"

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; if (!cin) { return 1; }

    vector<IntFunction> fs;

    while (cin)
        fs.push_back(IntFunction());

    vector<int> vals;
    size_t nfs = fs.size();

    for (int i = a; i <= b; i++)
    {
        for (size_t j = 0; j < nfs; j++)
            vals.push_back(fs[j].calculate(i));

        for (size_t j = 0; j < nfs - 1; j++)
            for (size_t k = j + 1; k < nfs; k++)
                if (vals[j] == vals[k])
                    cout << fs[j].getName() << '(' << i << ") = " <<
                            fs[k].getName() << '(' << i << ") = " <<
                            vals[j] << endl;
    }

    return 0;
}
