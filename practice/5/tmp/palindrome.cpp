#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n; cin >> n;
    int t = n;

    while (t)
    {
        s.push(t % 10);
        t /= 10;
    }

    int t1 = 0;
    t1 += s.top();
    s.pop();
    
    while (!s.empty())
    {
        t1 *= 10;
        t1 += s.top();
        s.pop();
    }

    cout << t << endl;
    cout << t1 << endl;
    cout << (n == t1) << endl;
}
