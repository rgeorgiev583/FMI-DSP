#include <iostream>
#include "stream.h"

class OddNStream : Stream
{
    size_t n;

public:
    OddNStream(): n(1) {}

    OddNStream* clone() const;
    {
        return new OddNStream(*this);
    }

    OddNStream& operator>>(size_t& x)
    {
        x = n;
        n += 2;
        return *this;
    }

    OddNStream& operator>>(std::ostream& os)
    {
        os << n;
        n += 2;
        return *this;
    }
};

