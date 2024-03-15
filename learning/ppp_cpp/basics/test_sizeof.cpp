#include "std_lib_facilities.h"

// compute mean and median temperatures
int main()
{
    char ch{'a'};
    int i = 2;
    int *p = &i;
    
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof (ch) << '\n';
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof (i) << '\n';
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof (p) << '\n';

    bool test_b = true;
    cout << "the size of int* is " << sizeof(bool) << ' ' << sizeof (test_b) << '\n';

}