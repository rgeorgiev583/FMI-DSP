#include <iostream>
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

int main()
{
    Stack<int> s0;
    s0.push(2);
    s0.push(3);
    s0.push(5);
    s0.push(7);
    s0.push(11);
    s0.push(13);
    s0.push(17);

    do
    {
        cout << s0.top() << endl;
    }
    while (s0.pop());

    Stack<int> ps;
    char s[1000];
    cin.getline(s, 1000);
    const char* str = s;

    bool valid = true;
    while (*str)
    {
        switch (*str)
        {
        case '(':
            ps.push(1);
            break;
        case ')':
            if (!ps.pop())
                valid = false;
            break;
        }

        str++;
    }
    cout << (ps.empty() && valid ? "Yes" : "No") << endl;

    Queue<int> q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(11);
    q.push(13);
    q.push(17);

    do
    {
        cout << q.top() << endl;
    }
    while (q.pop());

    return 0;
}
