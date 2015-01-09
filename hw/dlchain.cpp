#pragma once
#include "dllist.cpp"

template <typename T>
class DoubleLinkedChain : public DoubleLinkedList<T>
{
protected:
    void copy(const DoubleLinkedChain<T>& other)
    {
        if (!other.front || !other.back)
            return;

        DoubleListElement<T> *pFront = other.front, *pn = pFront->prev;
        DoubleLinkedList<T> lFront;

        while (pFront && pFront->prev == pn)
        {
            lFront.insertEnd(pFront->data);
            pn = pFront;
            pFront = pFront->next;
        }

        if (pFront)
        {
            DoubleListElement<T> *pBack = other.back;
            pn = pBack->next;
            DoubleLinkedList<T> lBack;

            while (pBack && pBack->next == pn)
            {
                lBack.insertBegin(pBack->data);
                pn = pBack;
                pBack = pBack->prev;
            }

            lFront.back->next = pFront;
            lBack.front->prev = pBack;
            this->front = lFront.front;
            this->back = lBack.back;
            lBack.back = lBack.front = NULL;
        }
        else
        {
            this->front = lFront.front;
            this->back = lFront.back;
        }

        lFront.back = lFront.front = NULL;
    }

public:
    void clear()
    {
        if (!this->front || !this->back)
            return;

        DoubleListElement<T> *pFront = this->front, *prev = pFront->prev;

        while (pFront && pFront->prev == prev)
        {
            prev = pFront;
            pFront = pFront->next;
        }

        prev->next = NULL;

        DoubleListElement<T> *pBack = this->back, *next = pBack->next;

        while (pBack && pBack->next == next)
        {
            next = pBack;
            pBack = pBack->prev;
        }

        next->prev = NULL;

        DoubleLinkedList<T> lFront, lBack;
        lFront.front = this->front;
        lFront.back = prev;
        
        if (this->front != next && prev != this->back)
        {
            lBack.front = next;
            lBack.back = this->back;
        }

        this->back = this->front = NULL;
    }

    DoubleLinkedChain()
    {
        this->front = NULL;
        this->back = NULL;
    }

    DoubleLinkedChain(const DoubleLinkedChain& other)
    {
        copy(other);
    }

    DoubleLinkedChain& operator=(const DoubleLinkedChain& other)
    {
        if (&other != this)
        {
            clear();
            copy(other);
        }

        return *this;
    }

    ~DoubleLinkedChain()
    {
        clear();
    }

    DoubleListElement<T>* getFrontPtr() { return this->front; }
    const DoubleListElement<T>* getFrontPtr() const { return this->front; }

    DoubleListElement<T>* getBackPtr() { return this->back; }
    const DoubleListElement<T>* getBackPtr() const { return this->back; }

    bool adoptList(DoubleLinkedList<T>& l)
    {
        if (!l.front || !l.back)
            return false;

        clear();
        this->front = l.front;
        this->back = l.back;
        l.front = NULL;
        l.back = NULL;
        return true;
    }

    bool attachAtBegin(DoubleLinkedList<T>& l, DoubleLinkedListIterator<T>& it)
    {
        if (it)
        {
            if (this->front)
            {
                this->front->prev = it.ptr;

                if (it.ptr == l.back)
                    it.ptr->next = this->front;

                I begin = front;
                while (begin && begin.ptr->back)
                    begin--;
                front = begin.ptr;
            }
            else
            {
                this->front = l.front;
                this->back = l.back;
            }

            l.front = NULL;
            l.back = NULL;
            return true;
        }
        else
            return false;
    }

    bool attachAtEnd(DoubleLinkedList<T>& l, DoubleLinkedListIterator<T>& it)
    {
        if (it)
        {
            if (this->back)
            {
                this->back->next = it.ptr;

                if (it.ptr == l.front)
                    it.ptr->prev = this->back;

                I end = back;
                while (end && end.ptr->next)
                    end++;
                back = end.ptr;
            }
            else
            {
                this->front = l.front;
                this->back = l.back;
            }

            l.front = NULL;
            l.back = NULL;
            return true;
        }
        else
            return false;
    }

    bool attachListAtFront(DoubleLinkedList<T>& l, DoubleLinkedListIterator<T>& it)
    {
        if (it && l.front && !l.front->prev)
        {
            l.front->prev = it.ptr;

            if (it.ptr == this->back)
            {
                this->back->next = l.front;

                I end = back;
                while (end && end.ptr->next)
                    end++;
                back = end.ptr;
            }

            return true;
        }
        else
            return false;
    }

    bool attachListAtBack(DoubleLinkedList<T>& l,
            DoubleLinkedListIterator<T>& it)
    {
        if (it && l.back && !l.back->next)
        {
            l.back->next = it.ptr;

            if (it.ptr == this->front)
            {
                this->front->back = l.back;

                I begin = front;
                while (begin && begin.ptr->back)
                    begin--;
                front = begin.ptr;
            }

            return true;
        }
        else
            return false;
    }

    bool join_at(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2,
            DoubleLinkedListIterator<T>& M1, DoubleLinkedListIterator<T>& M2)
    {
        return adoptList(L1) && attachListAtFront(L2, M1) &&
                                attachAtEnd(L2, M2);
    }

    bool join(DoubleLinkedList<T>& L1, DoubleLinkedList<T>& L2)
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

    bool isJoined() const
    {
        if (!this->front || !this->back)
            return false;

        DoubleListElement<T> *pFront = this->front, *pn = pFront->prev;

        while (pFront && pFront->prev == pn)
        {
            pn = pFront;
            pFront = pFront->next;
        }
       
        DoubleListElement<T> *pBack = this->back;
        pn = pBack->next;

        while (pBack && pBack->next == pn)
        {
            pn = pBack;
            pBack = pBack->prev;
        }

        return pFront && pBack;
    }

    T sum() const
    {
        T S = T();

        if (!this->front || !this->back)
            return S;

        DoubleListElement<T> *pFront = this->front, *pn = pFront->prev;

        while (pFront && pFront->prev == pn)
        {
            S += pFront->data;
            pn = pFront;
            pFront = pFront->next;
        }
       
        if (pFront)
        {
            DoubleListElement<T> *pBack = this->back;
            pn = pBack->next;

            while (pBack && pBack->next == pn)
            {
                S += pBack->data;
                pn = pBack;
                pBack = pBack->prev;
            }
        }

        return S;
    }
};
