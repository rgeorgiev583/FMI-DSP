#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stack.h"

template <typename T>
class Queue
{
    Stack<T> pushStack, popStack;

    bool move();

public:
    bool empty() const;
    T top();

    void push(const T& data);
    bool pop();
};

#endif // QUEUE_H_INCLUDED
