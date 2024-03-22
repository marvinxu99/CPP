#include <iostream>
#include <string>
#include <sstream>

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept Number1 = std::is_integral_v<T> || std::is_floating_point_v<T>;

// template <Integral T>
template <Number1 T>
void printValue(T value)
{
    std::cout << "Value: " << value << std::endl;
}

int main()
{
    printValue(5);   // Valid, int is an integral type
    printValue(3.5); // Error, double is not an integral type

    return 0;
}
