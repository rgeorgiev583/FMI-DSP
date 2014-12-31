#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int n;

    do
    {
        cin >> n;
        q.push(n);
    }
    while (n);

    queue<int> qo, qe;
    int t;

    while (!q.empty())
    {
        t = q.front();
        (t % 2) ? qo.push(t) : qe.push(t);
        q.pop();
    }

    while (!qe.empty())
    {
        cout << qe.front() << endl;
        qe.pop();
    }

    while (!qo.empty())
    {
        cout << qo.front() << endl;
        qo.pop();
    }

    return 0;
}
