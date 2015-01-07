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

    void attachAtPrev(const I& it, const I& prev)
    {
        if (it && prev && !it.ptr->prev)
            it.ptr->prev = prev.ptr;
    }

    void attachAtNext(const I& it, const I& next)
    {
        if (it && next && !it.ptr->next)
            it.ptr->next = next.ptr;
    }



};
