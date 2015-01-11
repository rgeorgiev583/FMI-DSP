#pragma once
#include "lstack.cpp"
#include <string>

int priority(char);
int ipow(int, int);
void apply_operation(LinkedStack<int>&, char);
int calculate_expr(const char*);
char* strshift(char*, size_t);
char* itonstr(int, char*);
char* strsubst(char*, char, int);
std::string& substitute(std::string&, char, const std::string&);
std::string& interpolate(std::string&, char, int);
const char* find_token(const char*);
bool is_alpha(char);
