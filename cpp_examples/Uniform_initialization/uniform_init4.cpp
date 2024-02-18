// C++ program to demonstrate how to
// initialize a function parameter
// using Uniform Initialization
 
#include <iostream>
using namespace std;
 
// declaring a class 'A'
class A {
 
    // a and b are data members
    int a;
    int b;
 
public:
    A(int x, int y)
        : a(x)
        , b(y)
    {
    }
    void show() { cout << a << " " << b << endl; }
};
 
void f(A x) { x.show(); }

void f2(A x, A y) 
{ 
   x.show(); 
   y.show(); 
}
 
// Driver Code
int main()
{
 
    // calling function and initializing it's argument
    // using brace initialization
    f({ 1, 2 });
    f2({3, 4}, {5, 6}); 
    return 0;
}