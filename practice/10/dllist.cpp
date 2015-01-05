#include <>

template <typename T>
struct DoubleLinkedNode
{
    T data;
    DoubleLinkedNode *next, *prev;
    
    DoubleLinkedNode(const T& _data = T(),
                     DoubleLinkedNode* _next = NULL,
                     DoubleLinkedNode* _prev = NULL):
        data(_data), next(_next), prev(_prev) {}

}

struct 

template <typename T>
class DoubleLinkedList
{
    DoubleLinkedNode *front, *back;

    void insert(const T& data,)
