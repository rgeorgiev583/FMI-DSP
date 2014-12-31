#include <iostream>
#include <fstream>
using namespace std;

void write(ostream& f, const char* s, size_t l)
{
    f.write(s, l);
}

/*
ostream& operator<<(ostream& file, istream& file2)
{
    while (!file2.eof())
    {
        char c = file2.get();
        file.put(c);
    }
}
*/

ostream& operator<<(ostream& file, istream& file2)
{
    char c;

    while (file2.read(&c, 1))
    {
        file.write(&c, 1);
    }
}

int main()
{
    ofstream f("hello.txt", ios::app);
    ifstream f2("numbers.txt", ios::in);

    try
    {
        for (size_t i = 0; i < 10; i++)
        {
            write(f, "Hello world!\n", 14);
        }

        f << endl;
        cout << f2;

        f2.close();
        f.close();
    }
    catch (exception e)
    {
        f2.close();
        f.close();
    }
    
    return 0;
}

