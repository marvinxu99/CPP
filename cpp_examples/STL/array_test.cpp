#include <array>
#include <iostream>
#include <algorithm>
using namespace std;

void f()
{
    array<double, 6> a = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
    // array<double, 6>::iterator p = high(a.begin(), a.end());
    auto p = max_element(a.begin(), a.end());
    cout << "the highest value was " << *p << '\n';
}

int main()
{
    f();

    return 0;
}