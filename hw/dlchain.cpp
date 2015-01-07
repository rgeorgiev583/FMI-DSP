#include "dllist.cpp"

template <typename T>
class DoubleLinkedChain : public DoubleLinkedList<T>
{
    bool ownsItems = true;

public:
    DoubleLinkedChain(): front(NULL), back(NULL) {}

    DoubleLinkedChain(const DoubleLinkedList& l):
            front(l.front), back(l.back), ownsItems(false) {}

    DoubleLinkedChain& operator=(const DoubleLinkedList& l)
    {
        if (&other != this)
        {
            if (ownsItems)
                clean();

            front = l.front;
            back = l.back;
            ownsItems = false;
        }

        return *this;
    }

    ~DoubleLinkedChain()
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
