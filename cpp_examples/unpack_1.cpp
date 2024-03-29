// 06-pixel1.cpp : Color and position Pixel type through composition
 
#include <iostream>
#include <string_view>
using namespace std;
 
struct Point {
    int x{}, y{};
};
 
enum class Color { red, green, blue };
 
struct Pixel {
    Point pt;
    Color col{};
};
 
string_view get_color(Color c) {
    switch (c) {
        case Color::red:
            return "red";
            break;
        case Color::green:
            return "green";
            break;
        case Color::blue:
            return "blue";
            break;
    }
    return "<no color>";
}
 
int main() {
    Pixel p1;
    cout << "Pixel p1 has color " << get_color(p1.col);
    cout << " and co-ordinates " << p1.pt.x;
    cout << ',' << p1.pt.y << '\n';
 
    Pixel p2{ { -1, 2 }, Color::blue };
    cout << "Pixel p2 has color " << get_color(p2.col);
    cout << " and co-ordinates " << p2.pt.x;
    cout << ',' << p2.pt.y << '\n';

    // Unpack
    auto [ point2, color2 ] = p2; 
    cout << "Pixel p2 has color " << get_color(color2);
    cout << " and co-ordinates " << point2.x;
    cout << ',' << point2.y << '\n';
    
    //
	// More unpack examples...
	struct Packed {
	  int x;
	  char y;
	  float z;
	};

	Packed p;
	// access by reference
	auto & [ x, y, z ] = p;
	// access by move
	auto && [ xx, yy, zz ] = p;

	class cls {
	public:
	  int m;
	  float n;
	};

	auto[m, n] = cls();
	cout << "m = " << m << ", n = " << n << endl;
 
}