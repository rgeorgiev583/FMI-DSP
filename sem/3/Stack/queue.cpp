#include <cstddef>
#include "queue.h"

template <typename T>
bool Queue<T>::move()
{
    if (pushStack.empty() || !popStack.empty())
        return false;

    do
        popStack.push(pushStack.top());
    while (pushStack.pop());
    return true;
}

template <typename T>
bool Queue<T>::empty() const
{
    return pushStack.empty() && popStack.empty();
}

template <typename T>
T Queue<T>::top()
{
    move();
    return popStack.top();
}

template <typename T>
void Queue<T>::push(const T& data)
{
    pushStack.push(data);
}

template <typename T>
bool Queue<T>::pop()
{
    move();
    return popStack.pop();
}
