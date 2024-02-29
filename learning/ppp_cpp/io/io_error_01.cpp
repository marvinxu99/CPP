#include "std_lib_facilities.h"

/*
good()
eof()
fail()
bad()
*/

void fill_vector(istream &ist, vector<int> &v, char terminator)
// read integers from ist into v until we reach eof() or terminator
{
    for (int i; ist >> i;)
        v.push_back(i);
    if (ist.eof())
        return; // fine: we found the end of file
    if (ist.bad())
        error("ist is bad"); // stream corrupted; let’s get out of here!
    if (ist.fail())
    {                // clean up the mess as best we can and report the problem
        ist.clear(); // clear stream state,
        // so that we can look for terminator
        char c;
        ist >> c; // read a character, hopefully terminator
        if (c != terminator)
        {                                 // unexpected character
            ist.unget();                  // put that character back
            ist.clear(ios_base::failbit); // set the state to fail()
        }
    }
}

void fill_vector2(istream &ist, vector<int> &v, char terminator)
// read integers from ist into v until we reach eof() or terminator
{
    for (int i; ist >> i;)
        v.push_back(i);
    if (ist.eof())
        return; // fine: we found the end of file
    // not good() and not bad() and not eof(), ist must be fail()
    ist.clear(); // clear stream state
    char c;
    ist >> c; // read a character, hopefully terminator
    if (c != terminator)
    {                                 // ouch: not the terminator, so we must fail
        ist.unget();                  // maybe my caller can use that character
        ist.clear(ios_base::failbit); // set the state to fail()
    }
}

int main()
{
    try
    {
        int i{-1};
        if (cin >> i)
        {
            cout << "true" << endl;
            cout << i << endl;
        }
        else // input operation not successful
        {
            cout << "false" << endl;
        }

        if (!cin)
        { // we get here (only) if an input operation failed
            if (cin.bad())
                error("cin is bad"); // stream corrupted: let’s get out of here!
            if (cin.eof())
            {
                // no more input
                // this is often how we want a sequence of input operations to end
                cout << "eof" << endl;
            }
            if (cin.fail())
            {                // stream encountered something unexpected
                cin.clear(); // make ready for more input

                // somehow recover
                string s;
                cin >> s;
                cout << s << endl;
            }
            // cout << "here" << endl;
        }
    }
    catch (...)
    {
        cout << "error from cin." << endl;
    }
}