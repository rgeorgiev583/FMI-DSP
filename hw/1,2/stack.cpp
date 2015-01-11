#include <stack>

template <typename T>
void pour(std::stack<T>& dest, std::stack<T> src)
{
    while (!src.empty())
    {
        dest.push(src.top());
        src.pop();
    }
}

template <typename T>
void copy(std::stack<T>& dest, std::stack<T> src)
{
    std::stack<T> buff;
    pour(buff, src);
    pour(dest, buff);
}

template <typename T>
void destroy(std::stack<T>& s)
{
    while (!s.empty())
        s.pop();
}
