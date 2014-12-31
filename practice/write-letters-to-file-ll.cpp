#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f("letters.txt", ios::out);

    try
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            f.write((const char*) &i, sizeof(char));
        }

        f.close();
    }
    catch (exception e)
    {
        f.close();
    }

    f.open("letters.txt", ios::in);

    try
    {
        char i;

        while (f.read((char*) &i, sizeof(char)))
        {
            cout << i;
        }

        f.close();
    }
    catch (exception e)
    {
        f.close();
    }
       
    return 0;
}
