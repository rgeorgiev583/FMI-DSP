#include "dllist.cpp"

template <typename T>
class DoubleLinkedChain : public DoubleLinkedList<T>
{
    bool ownsItems = true;

public:
    DoubleLinkedChain(): front(NULL), back(NULL) {}

    DoubleLinkedChain(const DoubleLinkedList& l): front(l.front), back(l.back),
            ownsItems(false) {}

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

    void attachNext(const I& cur, const I& next)
    {
        if (cur.ptr && !cur.ptr->next)
            cur.ptr->next = next.ptr;
    }

    void attachPrev(const I& cur, const I& prev)
    {
        if (cur.ptr && !cur.ptr->prev)
            cur.ptr->prev = prev.ptr;
    }
};
