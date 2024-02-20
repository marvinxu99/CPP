#include "std_lib_facilities.h"

int main()
{

    char c = 'a';
    while (c <= 'z')
    {
        cout << c << ": " << int(c) << endl;
        ++c;
    }

    int a{3}, b{4};
    if (a <= b)
    { // do nothing
    }
    else
    { // swap a and b
        int t = a;
        a = b;
        b = t;
    }
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}