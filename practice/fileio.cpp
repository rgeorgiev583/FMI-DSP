#include <fstream>
using namespace std;

int main()
{
    ofstream file("baba.txt", ios::out | ios::app);

    try
    {
        file.write("Hello world", 12);
        file.close();
    }
    catch (exception e)
    {
        file.close();
    }

    return 0;
}
