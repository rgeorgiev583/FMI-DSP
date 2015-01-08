#include "dllist.cpp"

template <typename T>
class DoubleLinkedChain : public DoubleLinkedList<T>
{
protected:
    void copy(const DoubleLinkedChain<T>& other)
    {
        DoubleListElement<T> *pFront = other.getFrontPtr(),
                             *pBack  = other.getBackPtr();

        if (!pFront || !pBack)
            return;
        
        DoubleListElement<T> *pn = pFront->prev;
        DoubleLinkedList<T> lFront;

        while (pFront && pFront->prev == pn)
        {
            lFront.insertEnd(pFront->data);
            pn = pFront;
            pFront = pFront->next;
        }

        if (pFront)
        {
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
            front = lFront.front;
            back = lBack.back;
            lBack.back = lBack.front = NULL;
        }
        else
        {
            front = lFront.front;
            back = lFront.back;
        }

        lFront.back = lFront.front = NULL;
    }

public:
    void clear()
    {
        if (!front || !back)
            return;

        DoubleListElement<T> *pFront = front, *prev = pFront->prev;

        while (pFront && pFront->prev == prev)
        {
            prev = pFront;
            pFront = pFront->next;
        }

        prev->next = NULL;

        DoubleListElement<T> *pBack = back, *next = pBack->next;

        while (pBack && pBack->next == next)
        {
            next = pBack;
            pBack = pBack->prev;
        }

        next->prev = NULL;

        DoubleLinkedList<T> lFront, lBack;
        lFront.front = front;
        lFront.back = prev;
        
        if (front != next && prev != back)
        {
            lBack.front = next;
            lBack.back = back;
        }

        back = front = NULL;
    }

    DoubleLinkedChain(): front(NULL), back(NULL) {}

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

    DoubleListElement<T>* getFrontPtr() { return front; }
    const DoubleListElement<T>* getFrontPtr() const { return front; }

    DoubleListElement<T>* getBackPtr() { return back; }
    const DoubleListElement<T>* getBackPtr() const { return back; }

    bool adoptList(DoubleLinkedList<T>& l)
    {
        clear();
        front = l.front;
        back = l.back;
        l.front = NULL;
        l.back = NULL;
    }

    bool attachAtBegin(DoubleLinkedList<T>& l, I& it)
    {
        if (it)
        {
            if (front)
            {
                front->prev = it.ptr;
                if (it.ptr == l.back)
                    it.ptr->next = front;

                I begin = front;
                while (begin && begin.ptr->back)
                    begin--;
                front = begin.ptr;
            }
            else
            {
                front = l.front;
                back = l.back;
            }

            l.front = NULL;
            l.back = NULL;
            return true;
        }
        else
            return false;
    }

    bool attachAtEnd(DoubleLinkedList<T>& l, I& it)
    {
        if (it)
        {
            if (back)
            {
                back->next = it.ptr;
                if (it.ptr == l.front)
                    it.ptr->prev = back;

                I end = back;
                while (end && end.ptr->next)
                    end++;
                back = end.ptr;
            }
            else
            {
                front = l.front;
                back = l.back;
            }

            l.front = NULL;
            l.back = NULL;
            return true;
        }
        else
            return false;
    }

    bool attachListAtFront(DoubleLinkedList<T>& l, I& it)
    {
        if (it && l.front && !l.front->prev)
        {
            l.front->prev = it.ptr;

            if (it.ptr == back)
            {
                back->next = l.front.ptr;

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

    bool attachListAtBack(DoubleLinkedList<T>& l, I& it)
    {
        if (it && l.back && !l.back->next)
        {
            l.back->next = it.ptr;

            if (it.ptr == front)
            {
                front->back = l.back.ptr;

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
};
