#include "std_lib_facilities.h"

void end_of_loop(istream &ist, char term, const string &message)
{
    if (ist.fail())
    { // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist >> ch && ch == term)
            return; // all is fine
        error(message);
    }
}

int main()
{

    // Here is the file containing the data.
    ifstream ist("test.csv");

    // somewhere: make ist throw an exception if it goes bad:
    ist.exceptions(ist.exceptions() | ios_base::badbit);

    for (My_type var; ist >> var;)
    { // read until end of file
      // maybe check that var is valid
      // do something with var
    }
    end_of_loop(ist, '|', "bad termination of file"); // test if we can continue

    // carry on: we found end of file
}
