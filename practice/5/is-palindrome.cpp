#include <iostream>
#include <stack>

using namespace std;

int main()
{
    size_t len; cin >> len; cin.get();
    stack<int> origs, pops;

    while (len)
    {
        char input = cin.get();
        origs.push(input);
        pops.push(input);
        len--;
    }

    stack<int> pushs;

    while (!pops.empty())
    {
        pushs.push(pops.top());
        pops.pop();
    }

    while (!origs.empty() && !pushs.empty() && origs.top() == pushs.top())
    {
        origs.pop();
        pushs.pop();
    }

    cout << (origs.empty() && pushs.empty()) << endl;
    return 0;
}

