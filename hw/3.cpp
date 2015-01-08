#include "dllist.cpp"
#include "dlchain.cpp"

template <typename T>
DoubleLinkedChain<T>& join_at(DoubleLinkedChain<T>& ch,
        DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2,
        DoubleLinkedListIterator<T>& M1, DoubleLinkedListIterator<T>& M2)
{
    ch.adoptList(L1);
    ch.attachListAtFront(L2, M1);
    ch.attachAtEnd(L2, M2);
    return ch;
}

template <typename T>
DoubleLinkedChain<T> join_at(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2,
        DoubleLinkedListIterator<T>& M1, DoubleLinkedListIterator<T>& M2)
{
    DoubleLinkedChain<T> ch;
    join_at(ch, L1, L2, M1, M2);
    return ch;
}

template <typename T>
DoubleLinkedChain<T>& join(DoubleLinkedChain<T>& ch,
        DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2)
{
    DoubleLinkedListIterator<T> itL1 = L1.begin(), itL2 = L2.end(), M1, M2;

    while (itL1 && itL2)
    {
        if (*itL1 == *itL2 && (!M1 || *itL1 > *M1))
        {
            M1 = itL1;
            M2 = itL2;
        }

        itL1++;
        itL2--;
    }

    itL1 = L1.end();
    itL2 = L2.begin();

    while (itL1 && itL2)
    {
        if (*itL1 == *itL2 && (!M1 || *itL1 > *M1))
        {
            M1 = itL1;
            M2 = itL2;
        }

        itL1--;
        itL2++;
    }

    return join_at(ch, L1, L2, M1, M2);
}

template <typename T>
DoubleLinkedChain<T> join(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2)
{
    DoubleLinkedChain<T> ch;
    ch.join(ch, L1, L2);
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
    DoubleListElement<T> *front = ch.getFrontPtr(),
                         *back  = ch.getBackPtr();
    T S = T();

    if (!front || !back)
        return S;

    DoubleListElement<T> *pn = front->prev;

    while (front && front->prev == pn)
    {
        S += front->data;
        pn = front;
        front = front->next;
    }

    pn = back->next;

    while (back && back->next == pn)
    {
        S += back->data;
        pn = back;
        back = back->prev;
    }

    return S;
}
