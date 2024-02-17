// 04-noexcept.cpp : a noexcept function throwing an exception
 
#include <iostream>
#include <stdexcept>
using namespace std;
 
int throw_if_zero(int i) noexcept {
//int throw_if_zero(int i) {
    if (!i) {
        throw runtime_error("found a zero");
    }
    cout << "throw_if_zero(): " << i << '\n';
    return 0;
}
 
int main() {
    cout << "Entering main()\n";
    try {
        throw_if_zero(1);
        throw_if_zero(0);
    }
    catch(...) {
        cout << "Caught an exception!\n";
    }
    cout << "Leaving main()\n";
}