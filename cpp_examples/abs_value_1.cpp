// 04-absolute3.cpp : modify a parameter to become its absolute value
 
#include <iostream>
using namespace std;
 
void abs_value(int& v) {
    if (v < 0) {
        v = -v;
    }
}

int incr1(int& a) { 
    ++a;

    return a; 
}

int incr2(int&& a) { 
    ++a;
    return a; 
}


int main() {
    int value{};
    cout << "Please enter a positive or negative integer: ";
    cin >> value;
    abs_value(value);
    cout << "The absolute value is: " << value << '\n';


	int i = 0;
	cout << incr1(i) << endl;	// i becomes 1
    // cout << incr1(0);	// error: 0 is not an lvalue

    // rvalue
    cout << incr2(0) << endl;

}