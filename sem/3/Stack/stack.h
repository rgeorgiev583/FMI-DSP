#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cstddef>

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node();
    Node(const T&, Node* = NULL);
};

template <typename T>
class Stack
{
    Node<T>* topnode;

    void copy(const Stack&);
    void destroy();
    Node<T>* base_reverse(Node<T>*);

public:
    Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack();

    bool empty() const;
    T top() const;

    void push(const T& data);
    bool pop();

    void reverse();
};

#endif // STACK_H_INCLUDED
