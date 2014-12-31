#include <cstddef>
#include "stack.h"

template <typename T>
Node<T>::Node(): next(NULL) {}

template <typename T>
Node<T>::Node(const T& _data, Node<T>* _next): data(_data), next(_next) {}


template <typename T>
void Stack<T>::copy(const Stack<T>& other)
{
    Node<T> *newtopnode = NULL, *currnode;

    for (Node<T>* node = topnode; node; node = node->next)
    {
        Node<T>* newnode = new Node<T>(node);

        if (!newtopnode)
            newtopnode = currnode = newnode;

        currnode->next = newnode;
        currnode = newnode;
    }

    other.topnode = newtopnode;
}

template <typename T>
void Stack<T>::destroy()
{
    while (pop());
}

template <typename T>
Node<T>* Stack<T>::base_reverse(Node<T>* node)
{
    if (node->next->next)
        base_reverse(node->next);

    node->next->next = node;
    node->next = NULL;

    return node->next && !node->next->next ? node->next : NULL;
}

template <typename T>
void Stack<T>::reverse()
{
    if (topnode && topnode->next)
        topnode = base_reverse(topnode);
}

template <typename T>
Stack<T>::Stack(): topnode(NULL) {}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (&other != this)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    destroy();
}

template <typename T>
bool Stack<T>::empty() const
{
    return !topnode;
}

template <typename T>
T Stack<T>::top() const
{
    if (empty())
        return T();

    return topnode->data;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    topnode = new Node<T>(data, topnode);
}

template <typename T>
bool Stack<T>::pop()
{
    if (empty())
        return false;

    Node<T>* newtopnode = topnode->next;
    delete topnode;
    topnode = newtopnode;
    return true;
}

