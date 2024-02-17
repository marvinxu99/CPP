// 02-assign.cpp : assign to local variables
 
#include <iostream>
using namespace std;
 
int main() {
    int i = 1, j = 2;
    unsigned k;
    cout << "(1) i = " << i << ", j = " << j << ", k = " << k << '\n';
    i = j;
    j = 3;
    k = -1;
    cout << "(2) i = " << i << ", j = " << j << ", k = " << k << '\n';

    // Uniform initialization
    // int c = { 2.5 };                 // Error: this does NOT compile
    int c = { static_cast<int>(2.5) };  // while this does
    double d = { 1 };                   // and so does this
    cout << "c = " << c << ", d = " << d << '\n';
}