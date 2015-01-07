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
        if (ownsItems)
            clean();
    }

    void attachAtBegin(const I& it)
    {
        if (it && front)
        {
            front->prev = it.ptr;

            I begin = front;
            while (begin)
                begin--;
            front = begin.ptr;
        }
    }

    void attachAtEnd(const I& it)
    {
        if (it && back)
        {
            back->next = it.ptr;

            I end = back;
            while (end)
                end++;
            back = end.ptr;
        }
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
