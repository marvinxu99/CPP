#include <iostream>
using namespace std;

// Template Class example
template <typename T = char>
class Opt 
{
    bool valid{ false };
    T value;

public:
    Opt() = default;
    Opt(const T& value) : value{ value }, valid{ true } {}
    Opt& operator= (const T& new_value) {
        value = new_value;
        valid = true;
        return *this;
    }

    bool hasValue() const {
        return valid;
    }

    const T& get() const {
        if (!valid) {
            throw;
        }
        else {
            return value;
        }
    }
};

// Member functions can be template functions
class Stringy {
    string str;
public:
    template <typename T> explicit Stringy(T&& str)
        : str{ str } {}
        
    string get() const { return str; }
};

int main() {
    auto o1 = Opt{ 1.2 };
    auto o2 = Opt{ 3 };
    auto o3 = Opt{};
    auto o4 = Opt<size_t>{};

    Stringy sy1{ "Star" };       // initialize from const char *
    Stringy sy2{ "Wars"s };      // initialize from std::string
    Stringy sy3{ "Trilogy"sv };  // initialize from std::string_view
    Stringy sy4{ 'V' };          // initialize from char
    Stringy sy5{ "Hello"s + " World" }; 
    //Stringy sy5{ 5 };            // Error! Attempt to narrow from int to char
} 
