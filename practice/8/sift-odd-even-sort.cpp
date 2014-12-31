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

    priority_queue<int, vector<int>, greater<int> > qo, qe;
    int t;

    while (!q.empty())
    {
        t = q.front();
        t % 2 ? qo.push(t) : qe.push(t);
        q.pop();
    }

    while (!qe.empty())
    {
        cout << qe.top() << endl;
        qe.pop();
    }

    while (!qo.empty())
    {
        cout << qo.top() << endl;
        qo.pop();
    }

    return 0;
}
