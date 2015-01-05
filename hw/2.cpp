#include <iostream>
#include "stack.cpp"
#include <queue>

using namespace std;

int main()
{
    queue<stack<bool> > qs;
    stack<bool> s;
    bool ends = false, endq = false;
    size_t input;

    do
    {
        cin >> input;

        if (input != -1)
        {
            s.push(input);
            ends = false;
        }
        else
        {
            qs.push(s);
            destroy(s);

            if (!ends)
                ends = true;
            else
                endq = true;
        }
    }
    while (!endq);

    size_t t = 0;

    while (!qs.empty())
    {
        cout << "***********" << endl;
        cout << t << " минута:" << endl;

        size_t i = 0;

        while (!qs.empty() && s.size() < 15)
        {
            copy(s, qs.front());
            cout << "Келнер " << i << " оставя чинии" << endl;
            qs.pop();
            i++;
        }

        size_t nt = 0, nf = 0;

        while (!s.empty() && nt < 7)
        {
            bool c = s.top();
            c ? nt++ : nf++;
            s.pop();
        }
    
        cout << nt << " измити чинии" << endl;
        cout << nf << " счупени чинии" << endl;
        t++;
    }
}
