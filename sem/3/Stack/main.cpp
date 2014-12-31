#include <iostream>
#include <cstring>
#include <stack>
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

bool validate(const char* s)
{
    Stack<char> ps;

    while (*s)
    {
        switch (*s)
        {
        case '(':
        case '[':
        case '{':
            ps.push(*s);
            break;
        case ')':
            if (ps.empty() || ps.top() != '(')
                return false;

            ps.pop();
            break;
        case ']':
            if (ps.empty() || ps.top() != '[')
                return false;

            ps.pop();
            break;
        case '}':
            if (ps.empty() || ps.top() != '{')
                return false;

            ps.pop();
            break;
        }

        s++;
    }

    if (ps.empty())
        return true;
}

char* to_rpn(const char* s)
{
    Stack<char> oper;
    char* rpn = new char[strlen(s) + 1];
    size_t n = 0;

    while (*s)
    {
        char opbr;

        switch (*s)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case '[':
        case '{':
            oper.push(*s);
            break;
        case ')':
        case ']':
        case '}':
            opbr = (*s == ')') ? '(' : ( (*s == ']') ? '[' : ( (*s == '}') ? '{' : 0 ) );

            while (!oper.empty() && oper.top() != opbr)
            {
                rpn[n++] = oper.top();
                oper.pop();
            }

            if (oper.top() == opbr)
                oper.pop();
        }

        if (*s >= '0' && *s <= '9' || *s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
        {
            rpn[n++] = *s;
        }

        s++;
    }

    while (!oper.empty())
    {
        rpn[n++] = oper.top();
        oper.pop();
    }

    rpn[n] = 0;
    return rpn;
}

char* to_pn(const char* s)
{
    Stack<char> oper, opnd;
    char* rpn = new char[strlen(s) + 1];
    size_t n = 0;

    while (*s)
    {
        switch (*s)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            oper.push(*s);
            break;
        case ')':
        case ']':
        case '}':
            char subexpr[3];
            subexpr[0] = oper.top();
            oper.pop();
            subexpr[1] = opnd.top();
            opnd.pop();
            subexpr[2] = opnd.top();
            opnd.pop();
            //oper.push(subexpr);
        }

        if (*s >= '0' && *s <= '9' || *s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
        {
            opnd.push(*s);
        }

        s++;
    }

    rpn[n] = 0;
    return rpn;
}

int main()
{
    Stack<int> s0;
    s0.push(2);
    s0.push(3);
    s0.push(5);
    s0.push(7);
    s0.push(11);
    s0.push(13);
    s0.push(17);
    //s0.reverse();

    while (!s0.empty())
    {
        cout << s0.top() << endl;
        s0.pop();
    }

    Stack<int> ps;
    char s[1000];
    cin.getline(s, 1000);
    const char* str = s;

    bool valid = true;
    while (*str)
    {
        switch (*str)
        {
        case '(':
            ps.push(1);
            break;
        case ')':
            if (!ps.pop())
                valid = false;
            break;
        }

        str++;
    }
    cout << (ps.empty() && valid ? "Yes" : "No") << endl;

    Queue<int> q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(11);
    q.push(13);
    q.push(17);

    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    //char expr[100] = "{[(a+b)*c]^[(x+y)+d]}";
    char expr[14] = "(1+2)*(3-4/5)";
    cout << "is valid: " << validate(expr) << endl;
    char* rpn1 = to_rpn(expr);
    cout << rpn1 << endl;
    delete rpn1;
    char* pn1 = to_pn(expr);
    cout << pn1 << endl;
    delete pn1;

    return 0;
}
