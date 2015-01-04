#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    queue<size_t> q;
    size_t d;
    cin >> d;

    while (d)
    {
        q.push(d);
        cin >> d;
    }

    if (q.empty())
        return 0;

    queue<stack<size_t> > qs;
    stack<size_t> s;

    s.push(q.front());
    q.pop();

    while (!q.empty())
    {
        size_t dn = q.front();

        if (s.top() > dn)
        {
            stack<size_t> sr;
            pour(sr, s);
            qs.push(sr);
            s = stack<size_t>();
        }

        s.push(dn);
        q.pop();
    }

    stack<size_t> sr;
    pour(sr, s);
    qs.push(sr);
    s = qs.front();
    qs.pop();

    queue<stack<size_t> > qsm;

    while (!qs.empty())
    {
        stack<size_t> sn = qs.front(), sc = sn, sr;
        
        while (!sc.empty())
        {
            sr.push(sc.top());
            sc.pop();
        }

        if (sr.top() < s.top())
            while (!sr.empty())
            {
                s.push(sr.top());
                sr.pop();
            }
        else
        {
            qsm.push(s);
            s = sn;
        }

        qs.pop();
    }

    qsm.push(s);
    d = 1;

    while (!qsm.empty())
    {
        cout << "Купчина " << d << ": ";

        stack<size_t> sn = qsm.front();

        while (!sn.empty())
        {
            cout << sn.top() << " ";
            sn.pop();
        }

        cout << endl;
        d++;
        qsm.pop();
    }

    return 0;
}
