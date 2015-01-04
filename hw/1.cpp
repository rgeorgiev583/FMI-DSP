#include <iostream>
#include "stack.h"
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
            destroy(s);
        }

        s.push(dn);
        q.pop();
    }

    stack<size_t> sr;
    pour(sr, s);
    qs.push(sr);
    destroy(s);

    size_t fixed_stack_count = 0;
    bool was_stack_moved = false;

    while (fixed_stack_count < qs.size())
    {
        stack<size_t> sn;
        copy(sn, qs.front());

        if (sn.empty())
            if (was_stack_moved)
                was_stack_moved = false;
            else
            {
                qs.push(s);
                destroy(s);
                fixed_stack_count++;
            }
        else if (s.empty())
        {
            pour(s, sn);
            qs.push(stack<size_t>()); // sentinel stack
        }
        else
        {
            if (sn.top() > s.top())
                pour(sn, s);

            qs.push(sn);
        }

        qs.pop();
    }

    size_t i = 1;

    while (!qs.empty())
    {
        cout << "Купчина " << i << ": ";

        stack<size_t> sn = qs.front();

        while (!sn.empty())
        {
            cout << sn.top() << " ";
            sn.pop();
        }

        cout << endl;
        i++;
        qs.pop();
    }

    return 0;
}
