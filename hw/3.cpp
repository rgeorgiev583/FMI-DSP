#include "dllist.cpp"
#include "dlchain.cpp"

template <typename T>
DoubleLinkedChain<T> join_at(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2,
        DoubleLinkedListIterator<T>& M1, DoubleLinkedListIterator<T>& M2)
{
    DoubleLinkedChain<T> ch;
    ch.adoptList(L1);
    ch.attachListAtFront(L2, M1);
    ch.attachAtEnd(L2, M2);
    return ch;
}

template <typename T>
DoubleLinkedChain<T> join(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2)
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

    return join_at(L1, L2, M1, M2);
}

