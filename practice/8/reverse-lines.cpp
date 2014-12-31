#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

const size_t MAX_SIZE = 256;

int main()
{
    char finname[MAX_SIZE];
    cin.getline(finname, MAX_SIZE);
    char foutname[MAX_SIZE];
    cin.getline(foutname, MAX_SIZE);
    ifstream fin(finname, ios::in);
    char ch = 0;
    queue< stack<char> > q;

    while (!fin.eof())
    {
        stack<char> s;

        while (ch != '\n')
        {
            fin.get(ch);
            s.push(ch);
        }

        q.push(s);
    }

    fin.close();
    ofstream fout(foutname, ios::out);

    while (!q.empty())
    {
        stack<char> s = q.front();

        while (!s.empty())
        {
            fout.put(s.top());
            s.pop();
        }

        fout.put('\n');
        q.pop();
    }

    fout.close();
    return 0;
}
