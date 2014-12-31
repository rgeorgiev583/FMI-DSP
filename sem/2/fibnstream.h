#include <iostream>
#include "stream.h"

class FibNStream : Stream
{
    size_t a, b;

public:
    FibNStream(): a(0), b(1) {}

    FibNStream* clone() const;
    {
        return new FibNStream(*this);
    }

    FibNStream& operator>>(size_t& x)
    {
        x = a;
        a += b;
        std::swap(a, b);
        return *this;
    }

    FibNStream& operator>>(std::ostream& os)
    {
        os << a;
        a += b;
        std::swap(a, b);
        return *this;
    }
};

