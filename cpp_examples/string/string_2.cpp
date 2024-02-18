// 07-reversed.cpp : output different "string" types using a string_view
 
#include <iostream>
#include <string>
#include <string_view>

#include "type_name.h"

using namespace std;
 
void print_reversed(string_view sv) {
    for (auto iter = crbegin(sv); iter != crend(sv); ++iter) {
        cout << *iter;
    }
    cout << '\n';
}
 
string str_reversed(string_view sv) {
    string result;
    for (auto iter = crbegin(sv); iter != crend(sv); ++iter) {
        result.append(1, *iter);
    }
    return result;
}

int main() {
    const char *s1 = "Elf";
    char s2[] = "Dwarf";
    string s3 = "Hobbit"s;
    string_view s4 = "Orc"sv;
    string s5_empty{};
 
    print_reversed(s1);
    print_reversed(s2);
    print_reversed(s3);
    print_reversed(s4);
    print_reversed(s5_empty);
    print_reversed("Man");

    print_reversed(str_reversed("MArvin"));

    cout << "decltype(s5_empty) is " << type_name<decltype(s5_empty)>() << '\n';
    cout << "decltype(s2) is " << type_name<decltype(s2)>() << '\n';
}