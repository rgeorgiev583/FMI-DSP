#include <iostream>
using namespace std;

long int smartFib(int n)
{
    long int a = 0, b = 1;

    for (int i = 1; i <= n; i++)
    {
        a += b;
        long int x = a;
        a = b;
        b = x;
    }

    return a;
}

long int stupidFib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return stupidFib(n - 1) + stupidFib(n - 2);
}

void assertEquals(long int a, long int b, int n)
{
    cout << "Unit test " << n << " has ";
    cout << (a == b ? "PASSED" : "FAILED");
    cout << "." << endl;
}

int main()
{
    //assertEquals(stupidFib(-1), smartFib(-1), -1);
    assertEquals(stupidFib(0), smartFib(0), 0);
    assertEquals(stupidFib(1), smartFib(1), 1);
    assertEquals(stupidFib(2), smartFib(2), 2);
    assertEquals(stupidFib(5), smartFib(5), 5);
    assertEquals(stupidFib(8), smartFib(8), 8);
    assertEquals(stupidFib(20), smartFib(20), 20);
    assertEquals(stupidFib(30), smartFib(30), 30);
    assertEquals(stupidFib(40), smartFib(40), 40);

    cout << smartFib(50) << endl;
    cout << stupidFib(50) << endl;

    return 0;
}
