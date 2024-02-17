// 10-lambda3.cpp : lambda function which calculates average of two values
 
#include <iostream>
using namespace std;

struct Average {
    int operator()(int a, int b) {
        cout << "Calculating average...\n";
        return (a + b) / 2;
    }
};

int main() {
    auto l = [](int a, int b) {
        cout << "Calculating average...\n";
        return (a + b) / 2;
    };
 
    cout << "Please enter two integers:\n";
    int x{}, y{};
    cin >> x >> y;
    auto avg = l(x, y);
    cout << "The average is: " << avg << '\n';

    // functor approach
    Average avg_f;
    auto rv = avg_f(2, 6);
    cout << "The average of (2, 6) is: " << rv << '\n';
}
