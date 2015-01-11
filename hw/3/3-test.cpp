#include <iostream>
#include "3.cpp"

using namespace std;

int main()
{
    DoubleLinkedChain<int> ch;
    DoubleLinkedList<int> L1, L2;
    int a1[] = {1, 3, 5, 7, 9, 6};
    int a2[] = {3, 4, 8, 5, 7};

    for (size_t i = 0; i < 5; i++)
    {
        L1.insertEnd(a1[i]);
        L2.insertEnd(a2[i]);
    }

    L1.insertEnd(a1[5]);

    ch.join(L1, L2);
    
    DoubleListElement<int> *front = ch.getFrontPtr(), *pn = front->prev;
    cout << "First chain: (";

    while (front && front->prev == pn)
    {
        cout << front->data << " ";
        pn = front;
        front = front->next;
    }

    cout << ")" << endl;
    cout << "First link between chains: " << pn->data << " -> " <<
                                          front->data << endl;
    DoubleListElement<int> *back = ch.getBackPtr();
    pn = back->next;
    cout << "Second chain (reversed): (";

    while (back && back->next == pn)
    {
        cout << back->data << " ";
        pn = back;
        back = back->prev;
    }

    cout << ")" << endl;
    cout << "Second link between chains: " << pn->data << " -> " <<
                                            back->data << endl;

    cout << "Is joined: " << ch.isJoined() << endl;
    cout << "Sum: " << ch.sum() << endl;
    return 0;
}
