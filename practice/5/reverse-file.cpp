#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
const size_t MAX_SIZE = 256;

int main()
{
    char in_filename[256];
    cin.getline(in_filename, 256);
    char out_filename[256];
    cin.getline(out_filename, 256);
    ifstream fin(in_filename, ios::in);

    size_t from, to;
    cin >> from >> to;

    fin.seekg(0, ios::end);
    size_t len = fin.tellg();
    fin.seekg(0, ios::beg);

    ofstream fout(out_filename, ios::out);
    char* chunk = new char[from];
    fin.read(chunk, from);
    fout.write(chunk, from);
    stack<char> s, origs;
    char ch;

    for (size_t i = from; i <= to; i++)
    {
        ch = fin.get();
        s.push(ch);
    }

    while (!s.empty())
    {
        ch = s.top();
        cout << ch;
        fout.put(ch);
        origs.push(ch);
        s.pop();
    }

    cout << endl;

    size_t chunklen = len - to - 1;
    delete chunk;
    chunk = new char[chunklen];
    fin.read(chunk, chunklen);
    fout.write(chunk, chunklen);
    
    fin.close();
    fout.close();

    while (!origs.empty())
    {
        cout << origs.top();
        origs.pop();
    }

    return 0;
}
