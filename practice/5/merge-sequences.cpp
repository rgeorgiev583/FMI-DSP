#include <iostream>
#include <stack>

using namespace std;

int main()
{
    size_t n, m; cin >> n;
    stack<int> seq1;

    while (n)
    {
        cin >> m;
        seq1.push(m);
        n--;
    }

    cin >> n;
    stack<int> seq2;

    while (n)
    {
        cin >> m;
        seq2.push(m);
        n--;
    }

    stack<int> pops;

    while (!seq1.empty() && !seq2.empty())
    {
        if (seq1.top() > seq2.top())
        {
            pops.push(seq1.top());
            seq1.pop();
        }
        else
        {
            pops.push(seq2.top());
            seq2.pop();
        }
    }

    while (!seq1.empty())
    {
        pops.push(seq1.top());
        seq1.pop();
    }

    while (!seq2.empty())
    {
        pops.push(seq2.top());
        seq2.pop();
    }
    
    while (!pops.empty())
    {
        cout << pops.top() << ' ';
        pops.pop();
    }

    return 0;
}
