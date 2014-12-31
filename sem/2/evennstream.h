#include <iostream>
#include "stream.h"

class EvenNStream : Stream
{
    size_t n;

public:
    EvenNStream(): n(2) {}

    EvenNStream* clone() const
    {
        return new EvenNStream(*this);
    }

    EvenNStream& operator>>(size_t& x)
    {
        x = n;
        n += 2;
        return *this;
    }

    EvenNStream& operator>>(std::ostream& os)
    {
        os << n;
        n += 2;
        return *this;
    }
};

