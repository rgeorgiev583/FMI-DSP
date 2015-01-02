#include "stack.h"

void pour(std::stack<size_t>& dest, std::stack<size_t> src)
{
    while (!src.empty())
    {
        dest.push(src.top());
        src.pop();
    }
}

void copy(std::stack<size_t>& dest, std::stack<size_t> src)
{
    std::stack<size_t> buff;
    pour(buff, src);
    pour(dest, buff);
}

void destroy(std::stack<size_t>& s)
{
    while (!s.empty())
        s.pop();
}
