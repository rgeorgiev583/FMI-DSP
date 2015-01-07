#include "dllist.cpp"

template <typename T>
class DoubleLinkedChain : public DoubleLinkedList<T>
{
public:
    DoubleListElement<T>* getFrontPtr() { return front; }
    const DoubleListElement<T>* getFrontPtr() const { return front; }

    DoubleListElement<T>* getBackPtr() { return back; }
    const DoubleListElement<T>* getBackPtr() const { return back; }

    bool adoptList(DoubleLinkedList<T>& l)
    {
        front = l.front;
        back = l.back;
        l.front = NULL;
        l.back = NULL;
    }

    bool attachAtBegin(DoubleLinkedList<T>& l, const I& it)
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

    bool attachAtEnd(DoubleLinkedList<T>& l, const I& it)
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

    bool attachAtPrev(DoubleLinkedList<T>& l, const I& it)
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

    void attachAtNext(DoubleLinkedList<T>& l, const I& it)
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
