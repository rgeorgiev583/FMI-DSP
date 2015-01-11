#include <iostream>
#include "stack.cpp"
#include <queue>

using namespace std;

void print(queue<stack<size_t> > qs)
{
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
}

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

        if (sn.empty() && was_stack_moved)
            was_stack_moved = false;
        else if (s.empty())
        {
            pour(s, sn);
            qs.push(stack<size_t>()); // sentinel stack
        }
        else
        {
            if (sn.empty())
                fixed_stack_count++;
            else if (sn.top() > s.top())
            {
                was_stack_moved = true;
                fixed_stack_count = 0;
            }

            if (sn.empty() || sn.top() > s.top())
            {
                pour(sn, s);
                destroy(s);
            }

            qs.push(sn);
        }

        qs.pop();
    }

    print(qs);

    return 0;
}
