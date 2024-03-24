#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string from, to;
    // cin >> from >> to; // get source and target file names
    from = "test1.txt";
    to = "test2.text";

    ifstream is{from}; // open input stream
    ofstream os{to};   // open output stream

    istream_iterator<string> ii{is}; // make input iterator for stream
    istream_iterator<string> eos;    // input sentinel - When an istream reaches end of input (often referred
                                     // to as eof), its istream_iterator will equal the default istream_iterator (here called eos).

    ostream_iterator<string> oo{os, "\n"}; // make output iterator for stream

    vector<string> b{ii, eos}; // b is a vector initialized from input

    sort(b.begin(), b.end(), [](const string &a, const string &b)
         { return a > b; });

    std::sort(b.begin(), b.end(), std::greater<std::string>());

    std::sort(b.begin(), b.end(), std::less<std::string>());

    copy(b.begin(), b.end(), oo); // copy buffer to output
}