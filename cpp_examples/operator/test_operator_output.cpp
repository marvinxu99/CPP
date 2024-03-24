#include <iostream>

// Define a class representing a point in 2D space
class Point
{
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Public member functions to access private data members
    int getX() const { return x; }
    int getY() const { return y; }
};

// Overload the insertion operator for output streams
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

int main()
{
    // Create a Point object
    Point p1(3, 5);

    // Stream the Point object to std::cout using the overloaded operator<<
    std::cout << "Point p1: " << p1 << std::endl;

    return 0;
}