#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    cout << endl;
}

void print(priority_queue<int, vector<int>, greater<int> > q)
{
    while (!q.empty())
    {
        cout << q.top() << ' ';
        q.pop();
    }

    cout << endl;
}

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

    print(qe);
    print(qo);
    queue<int> qs;

    while (!qe.empty() && !qo.empty())
    {
        int te = qe.top(), to = qo.top();
        if (te > to)
        {
            qs.push(to);
            qo.pop();
        }
        else
        {
            qs.push(te);
            qe.pop();
        }
    }

    while (!qe.empty())
    {
        qs.push(qe.top());
        qe.pop();
    }

    while (!qo.empty())
    {
        qs.push(qo.top());
        qo.pop();
    }

    print(qs);

    return 0;
}
