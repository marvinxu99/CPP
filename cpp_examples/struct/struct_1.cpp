#include <iostream>
#include <string_view>


using namespace std;
 
// Template to display the type name of a variable
template <typename T>
constexpr auto type_name() {
  std::string_view name, prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void)";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

enum Rank : unsigned short;
enum class Suit : char;

struct PlayingCard {
    Rank r;
    Suit s;
};

enum Rank : unsigned short { 
	ace = 1, 
	two, 
	three, 
	four, 
	five, 
	six, 
	seven, 
	eight, 
	nine, 
	ten, 
	jack, 
	queen, 
	king, 
	none = 99
};

// enum class type - is also known as scoped or strongly typed enumeration
enum class Suit : char { 
	spades = 'S', 
	clubs = 'C', 
	hearts = 'H', 
	diamonds = 'D', 
	none = '\?' 
};


int main(int argc, char *argv[]) {
    
    cout << "Function name is: " <<  __PRETTY_FUNCTION__ << endl;
    for (int i{ 0 }; i != argc; ++i) {
        cout << "Argument " << i << ": " << argv[i] << '\n';
    }

    auto test_var{ eight };
    cout << "test_var = " << test_var << endl;

    Suit s1 = Suit::hearts;     // good, types match
    Suit s2{};                  // possible problem, s2 has value zero (NUL-byte)
    Suit s3{ 'S' };             // ok, perhaps surprisingly

    auto s4 = Suit::diamonds;   // s4 is of type Suit
    cout << "s4 type name is: " << type_name<decltype(s4)>() << endl;
    cout << "s4 type name is: " << typeid(s4).name() << endl;

    //char c = Suit::none;        // error: no implicit conversion to underlying type, static_cast needed


    PlayingCard ace_of_spades{ ace, Suit::spades };
 
    auto the_rank1 = ace_of_spades.r;               // the_rank1 = ace, and is of type Rank
    auto the_suit1 = ace_of_spades.s;               // the_suit1 = Suit::spades, and is of type Suit
 
    auto [ the_rank2, the_suit2 ] = ace_of_spades;  // the_rank2 = ace, the_suit2 = Suit::spades

}

