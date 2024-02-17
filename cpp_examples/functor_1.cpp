/*
Function objects
It is possible to overload the function call operator operator() for structs 
and classes; this enables objects created from them to masquerade as functions. 
Sometimes these objects are called functors; essentially this means that they 
are callable in the same sense as free functions, member functions and 
lambdas (which are discussed later in this Chapter). The term functor can be 
used to describe both the struct or class definition and the instance objects it creates.
*/

// 10-functor1.cpp : simple function object demonstration
 
#include <iostream>
using namespace std;
 
struct Average 
{
    int operator()(int a, int b) {
        cout << "Calculating average...\n";
        return (a + b) / 2;
    }
};

class Avg_double 
{
public:    
    double operator()(double a, double b) {
        cout << "Calculating average...\n";
        return (a + b) / 2;
    }
};

int main() {
    
    Average a;    
    int x{}, y{};
    
    cout << "Please enter two integers:\n";
    cin >> x >> y;
    
    auto avg = a(x, y);
    cout << "The average is: " << avg << '\n';

    // Avg_double
    Avg_double a2;    
    double x2{}, y2{};
    
    cout << "Please enter two decimals:\n";
    cin >> x2 >> y2;
    
    auto avg2 = a2(x2, y2);
    cout << "The average is: " << avg2 << '\n';

}
