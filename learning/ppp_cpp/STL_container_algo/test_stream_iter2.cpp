#include <iostream>
#include <string>
#include <iterator>
using namespace std;

// p.537 - Programming principles and practice using C++
int main()
{
    istream_iterator<string> ii{cin}; // reading *ii is to read a string from cin

    cout << "enter data:" << endl;
    string s1 = *ii; // meaning cin>>s1
    ++ii;            // “get ready for the next input operation”
    string s2 = *ii; // meaning cin>>s2
    cout << s1 << " " << s2 << endl;
}