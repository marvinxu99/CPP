#include "std_lib_facilities.h"

double my_abs(int x) // warning: buggy code
{
    if (x < 0)
        return -x;
    else if (x > 0)
        return x;
} // error: no value returned if x is 0

int main()
{
    vector<string> v(10);
    vector<string> v2{"a", "b", "c"};

    cout << "v = " << v.size() << endl;
    cout << "v2 = " << v2.size() << endl;

    double t = my_abs(0);
    cout << t << endl;
}