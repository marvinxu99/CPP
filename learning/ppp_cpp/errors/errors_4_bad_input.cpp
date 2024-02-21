#include "std_lib_facilities.h"

int main()
{
    double d = 0;

    cout << "Enter a double: ";
    cin >> d;
    if (cin)
    {
        // all is well, and we can try reading again
        cout << "good input" << endl;
    }
    else
    {
        // the last read didn’t succeed, so we take some other action
        cout << "bad input" << endl;
    }
}