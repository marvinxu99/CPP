// 04-inline.cpp : use of an inline function
 
#include <iostream>
using namespace std;
 
inline void swap(int& x, int& y);
 
int main() {
    int a = 1, b = 2;
    cout << "(1) a = " << a << ", b = " << b << '\n';
    swap(a, b);
    cout << "(2) a = " << a << ", b = " << b << '\n';

    double a1{3.3}, a2{4};
    cout << "(3) a1 = " << a1 << ", a2 = " << a2 << endl;
    std::swap(a1, a2);
    cout << "(4) a1 = " << a1 << ", a2 = " << a2 << endl;
   
}

inline void swap(int& x, int& y) {
    auto z = x;
    x = y;
    y = z;
}
