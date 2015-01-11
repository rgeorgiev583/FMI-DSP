#include <fstream>
#include <queue>
using namespace std;

struct Animal
{
    char name[20], species[40];
    size_t weight;
};

void read(queue<Animal>& q)
{
    istream fin("zoo.bin", ios::in | ios::binary);
    if (!fin.is_open())
        return 1;

    Animal a;

    while (!fin.eof())
    {
        fin.read((char*) a, sizeof(a));
        q.push(a);
    }

    fin.close();
}

void sort(queue<Animal> qa, queue<size_t> qn, queue<queue<Animal> > qres)
{
    while (!qn.empty())
    {
        queue<Animal> q = qa, qr;

        size_t from = qn.front();
        qn.pop();
        size_t to = qn.front();

        while (!q.empty())
        {
            Animal a = q.top();

            if (a.weight >= from && a.weight <= to)
            {
                qr.push(a);
            }
        }

        qres.push(qr);
    }
}

void write(queue<queue<Animal> > qs, size_t n)
{
    while (!qs.empty() && n)
    {
        qs.pop();
        n--;
    }

    queue<Animal> q = qs.top();
    Animal a;

    ofstream fout("animals.txt", ios::out | ios::binary);

    while (!q.empty())
    {
        a = q.top();
        fout.write((const char*) a, sizeof(a));
        q.pop();
    }
}

int main()
{

    return 0;
}
