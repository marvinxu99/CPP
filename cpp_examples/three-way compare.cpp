
#include <compare>
#include <iostream>

using namespace std;

int main()
{
    double foo = -0.0;
    double bar = 0.0;

    auto res = foo <= bar;

    if (res < 0)
        std::cout << "-0 is less than 0";
    else if (res > 0)
        std::cout << "-0 is greater than 0";
    else if (res == 0)
        std::cout << "-0 and 0 are equal";
    else
        std::cout << "-0 and 0 are unordered";
}


/*
#include <cassert>
#include <compare>
#include <set>

struct Point {
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
};

int main() {
    Point pt1{ 1, 1 }, pt2{ 1, 2 };

    // Just to show it Is enough for `std::set`.
    std::set<Point> s;
    s.insert(pt1);

    // All of these are automatically defined for us!
    assert(!(pt1 == pt2));
    assert((pt1 != pt2));
    assert((pt1 < pt2));
    assert((pt1 <= pt2));
    assert(!(pt1 > pt2));
    assert(!(pt1 >= pt2));
}
*/