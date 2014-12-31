#include <iostream>
#include "stream.h"

class NStream : Stream
{
    size_t n;

public:
    NStream(): n(1) {}

    NStream* clone() const
    {
        return new NStream(*this);
    }

    NStream& operator>>(size_t& x)
    {
        x = n;
        n++;
        return *this;
    }

    NStream& operator>>(std::ostream& os)
    {
        os << n;
        n++;
        return *this;
    }
};

