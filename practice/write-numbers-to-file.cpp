#include <fstream>
using namespace std;

int main()
{
    ofstream f("numbers.txt", ios::out);

    try
    {
        for (size_t i = 1; i <= 20; i++)
        {
            f << i << " ";
        }

        f << endl;

        f.close();
    }
    catch (exception e)
    {
        f.close();
    }
    
    return 0;
}
