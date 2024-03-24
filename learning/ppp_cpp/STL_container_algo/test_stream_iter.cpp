#include <iostream>
#include <string>
#include <iterator>
using namespace std;

// p.537 - Programming principles and practice using C++
int main()
{
    ostream_iterator<string> oo{cout}; // assigning to *oo is to write to cout
    *oo = "Hello, ";                   // meaning cout << "Hello, "
    ++oo;                              // “get ready for next output operation”
    *oo = "World!\n";                  // meaning cout << "World!\n"
}