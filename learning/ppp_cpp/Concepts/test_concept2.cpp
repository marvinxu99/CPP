#include <iostream>
#include <concepts>

template <typename T>
concept Printable = requires(T t) {
    {
        std::cout << t
    } -> std::same_as<std::ostream &>;
};

template <Printable T>
void print(const T &value)
{
    std::cout << value;
}

int main()
{
    print(42);      // Output: 42
    print("Hello"); // Output: Hello

    return 0;
}