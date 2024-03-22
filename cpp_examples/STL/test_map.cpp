#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    map<string, int> words; // keep (word,frequency) pairs

    istringstream iss{
        "C++ is a general purpose programming language designed to make programming more enjoyable for the serious "
        "programmer. Except for minor details, C++ is a superset of the C programming language. In addition to the facilities "
        "provided by C, C++ provides flexible and efficient facilities for defining new types"};

    for (string s; iss >> s;)
        ++words[s]; // note: words is subscripted by a string

    for (const auto &p : words)
        cout << p.first << ": " << p.second << '\n';

    //
    map<string, int>
}