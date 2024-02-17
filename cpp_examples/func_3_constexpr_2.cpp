// 04-constexpr.cpp : use of a constexpr function with static_assert
 
#include <iostream>
using namespace std;
 
constexpr int factorial(int n) {
    if (n < 2) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
 
static_assert(factorial(0) == 1);
static_assert(factorial(5) == 120);


constexpr int fib(int n);
 
int main() {
    cout << "Please enter a number: ";
    int n{};
    cin >> n;
    cout << n << "! = " << factorial(n) << '\n';

    cout << "fib(" << n <<") = " << fib(n) << '\n';
    
}

constexpr int fib(int n) {
   if (n == 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else {
      return fib(n-1) + fib(n-2);
   }

}
