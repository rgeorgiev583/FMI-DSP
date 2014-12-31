#include <iostream>
#include "stream.h"

class PrimeNStream : Stream
{
    size_t n;

    static bool isPrime(size_t m)
    {
        for (size_t i = 2; i * i <= m; i++)
        {
            if (m % i == 0)
                return false;
        }

        return true;
    }

public:
    PrimeNStream(): n(2) {}

    PrimeNStream* clone() const;
    {
        return new PrimeNStream(*this);
    }

    PrimeNStream& operator>>(size_t& x)
    {
        while (!isPrime(n))
            n++;

        x = n;
        return *this;
    }

    PrimeNStream& operator>>(std::ostream& os)
    {
        while (!isPrime(n))
            n++;

        os << n;
        return *this;
    }
};

