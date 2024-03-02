#include <iostream>
#include <span>

int main()
{
    int value = 42;

    // Obtain a std::span<const std::byte> representing the bytes of the integer value
    auto bytes = std::as_bytes(std::span<int>(&value, 1));

    // Print the bytes
    for (std::byte b : bytes)
    {
        std::cout << std::to_integer<int>(b) << " ";
    }
    std::cout << std::endl;

    return 0;
}