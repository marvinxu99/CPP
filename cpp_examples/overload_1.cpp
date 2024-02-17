// 04-overload.cpp : calling a function with different types of arguments and parameters
 
#include <iostream>
using namespace std;
 
void f(int i) {
    cout << "f(): int: " << i << '\n';
}

void f(int& i) {
    cout << "f(): int reference: " << i << '\n';
}
 
void f(double d) {
    cout << "f(): double: " << d << '\n';
}

void f(unsigned u) {
    cout << "f(): unsigned: " << u << '\n';
}
 
int main() {
    f(1);
    f(2.5);
    f(unsigned(1));

    int i{3};
    f((int&)i);
}