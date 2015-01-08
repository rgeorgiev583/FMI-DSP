#include "dllist.cpp"
#include "dlchain.cpp"

template <typename T>
DoubleLinkedChain<T>& join_at(DoubleLinkedChain<T>& ch,
        DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2,
        DoubleLinkedListIterator<T>& M1, DoubleLinkedListIterator<T>& M2)
{
    ch.join_at(L1, L2, M1, M2);
    return ch;
}

template <typename T>
DoubleLinkedChain<T> join_at(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2,
        DoubleLinkedListIterator<T>& M1, DoubleLinkedListIterator<T>& M2)
{
    DoubleLinkedChain<T> ch;
    ch.join_at(L1, L2, M1, M2);
    return ch;
}

template <typename T>
DoubleLinkedChain<T>& join(DoubleLinkedChain<T>& ch,
        DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2)
{
    ch.join(L1, L2);
    return ch;
}

template <typename T>
DoubleLinkedChain<T> join(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2)
{
    DoubleLinkedChain<T> ch;
    ch.join(L1, L2);
    return ch;
}

template <typename T>
bool isJoined(const DoubleListElement<T>* front,
              const DoubleListElement<T>* back)
{
    if (!front || !back)
        return false;

    DoubleListElement<T>* pn = front->prev;

    while (front && front->prev == pn)
    {
        pn = front;
        front = front->next;
    }

    pn = back->next;

    while (back && back->next == pn)
    {
        pn = back;
        back = back->prev;
    }

    return front && back;
}

template <typename T>
T sum(const DoubleLinkedChain<T>& ch)
{
    return ch.sum();
}
