#include "stack.h"

void pour(std::stack<std::size_t>& dest, std::stack<std::size_t> src)
{
    while (!src.empty())
    {
        dest.push(src.top());
        src.pop();
    }
}

void copy(std::stack<std::size_t>& dest, std::stack<std::size_t> src)
{
    std::stack<std::size_t> buff;
    pour(buff, src);
    pour(dest, buff);
}

void destroy(std::stack<std::size_t>& s)
{
    while (!s.empty())
        s.pop();
}
