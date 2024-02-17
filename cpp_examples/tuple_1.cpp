// 04-aggregate.cpp : calling a function with different types of arguments and parameters
 
#include <iostream>
#include <utility>
#include <tuple>

using namespace std;
 
auto get_numbers() {
    cout << "Please enter a float and an integer: ";
    double d{};
    int i{};
    cin >> d >> i;
    return pair{ d, i };
}

auto get_numbers2() {
    cout << "Please enter a float, an integer and an unsigned: ";
    double d{};
    int i{};
    unsigned u{};
    cin >> d >> i >> u;
    return tuple{ d, i, u };
}
 
int main() {
    auto [ a, b ] = get_numbers();
    cout << "You entered " << a << " and " << b << '\n';

    auto [a1, a2, a3] = get_numbers2();
    cout << "You entered " << a1 << ", " << a2 << " and " << a3 << '\n';

}
