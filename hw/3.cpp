#include "dllist.cpp"

template <typename T>
DoubleLinkedList<T> join_at(DoubleLinkedList<T> L1,
        const DoubleLinkedList<T>& L2,
        const DoubleLinkedListIterator<T>& M1,
        const DoubleLinkedListIterator<T>& M2)
{
    DoubleLinkedListIterator <T> itL2 = L2.begin();

    while (itL2 && itL2 != M2)
    {
        L1.insertBefore(*itL2, M1);
        itL2++;
    }

    T x;
    L1.deleteAt(x, M1);
    itL2++;

    while (itL2)
    {
        L1.insertEnd(*itL2);
        itL2++;
    }

    return L1;
}

template <typename T>
DoubleLinkedList<T> join(const DoubleLinkedList<T>& L1,
                         const DoubleLinkedList<T>& L2)
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
