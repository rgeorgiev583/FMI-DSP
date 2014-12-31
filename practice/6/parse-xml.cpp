#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
const size_t MAX_SIZE = 256;
/*
char* upcase_cstr(char* s)
{
    char* i = s;

    while (*i)
    {
        if (*i >= 'a' && *i <= 'z')
            *i -= 32;

        i++;
    }
    
    return s;
}

char* lowcase_cstr(char* s)
{
    char* i = s;

    while (*i)
    {
        if (*i >= 'A' && *i <= 'Z')
            *i += 32;

        i++;
    }
    
    return s;
}

char* parseXML_cstr(char* xml, stack<char*>& s)
{
    stack<char*> s;
    char* leading_text = strtok(xml, "<");
    //cout << leading_text;
    char* start_tag = strtok(NULL, ">");
    s.push(start_tag);
    char* text = strtok(NULL, "<");
    char* end_tag = strtok(NULL, ">");

    if (*end_tag == '/' && !strcmp(start_tag, end_tag + 1) || *end_tag != '/')
    {
        if (!strcmp(start_tag, "upcase") && !strcmp(end_tag, "/upcase"))
            cout << upcase(text);
        else if (!strcmp(start_tag, "lowcase") && !strcmp(end_tag, "/lowcase"))
            cout << lowcase(text);

        cout << text;
    }

    return end_tag;
}
*/
string upcase(string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;

    return str;
}

string lowcase(string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;

    return str;
}

size_t parse(const string& xml, size_t offset, stack<string>& s)
{
    size_t otag_start = xml.find("<", offset), otag_end = xml.find(">", otag_start);

    if (!otag_start != string::npos || !otag_end != string::npos)
        return -1;
        
    s.push(xml.substr(otag_start + 1, otag_end - otag_start));

    size_t text_start = otag_end + 1, text_end = xml.find("<", text_start) - 1;

    if (!text_start != string::npos || !text_end != string::npos)
        return -1;

    string text = xml.substr(text_start, text_end - text_start + 1);
    
    if (s.top() == "upcase")
        cout << upcase(text);
    else if (s.top() == "lowcase")
        cout << lowcase(text);
    else
        cout << text;

    size_t ctag_start = text_end + 1, ctag_end = xml.find(">", ctag_start);

    if (!ctag_start != string::npos || !ctag_end != string::npos)
        return -1;

    if (xml[ctag_start + 1] == '/' && xml.substr(ctag_start + 2, ctag_end - ctag_start) == s.top())
    {
        s.pop();
        return otag_end + 1;
    }
    else
        return otag_start;
}

int main()
{
    char in_filename[256];
    cin.getline(in_filename, 256);
    //char out_filename[256];
    //cin.getline(out_filename, 256);
    ifstream fin(in_filename, ios::in);

    fin.seekg(0, ios::end);
    size_t len = fin.tellg();
    fin.seekg(0, ios::beg);

    char* file = new char[len];
    fin.read(file, len);
    fin.close();

    string xml(file);
    stack<string> s;
    size_t pos = 0;

    do
    {
        pos = parse(xml, pos, s);
    }
    while (pos < xml.length() && !s.empty());

    /*
    ofstream fout(out_filename, ios::out);
    fout.write(chunk, from);
    stack<char> s, origs;
    char ch;



    for (size_t i = from; i <= to; i++)
    {
        ch = fin.get();
        s.push(ch);
    }

    while (!s.empty())
    {
        ch = s.top();
        cout << ch;
        fout.put(ch);
        origs.push(ch);
        s.pop();
    }

    cout << endl;

    size_t chunklen = len - to - 1;
    delete chunk;
    chunk = new char[chunklen];
    fin.read(chunk, chunklen);
    fout.write(chunk, chunklen);
    */
    //fout.close();
    /*
    while (!origs.empty())
    {
        cout << origs.top();
        origs.pop();
    }
*/
    return 0;
}
