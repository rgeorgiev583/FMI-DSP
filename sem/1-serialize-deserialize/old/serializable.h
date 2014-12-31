#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

class Serializable
{
public:
    virtual void serialize(const char* fname) = 0;
    virtual void deserialize(const char* fname) = 0;
};

#endif
