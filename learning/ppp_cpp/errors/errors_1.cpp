#include "std_lib_facilities.h"

int area(int length, int width) // calculate area of a rectangle
{
    return length * width;
}

int main()
{
    int s1 = area(7, 4);       // error: ) missing
    int s2 = area(7, 4);       // error: ; missing
    int s3 = area(1.7, 3);     // error: Int is not a type
    char s4 = area(100, 9999); // error: non-terminated character (' missing)
}