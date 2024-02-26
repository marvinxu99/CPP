/*
if default_date () is called often and it is expensive to construct Date,
we’d like to construct the Date once only.That is done like this : Click here to view code image
*/

#include "std_lib_facilities.h"
#include <chrono>

const Date &default_date()
{
    static const Date dd(1970, 1, 1); // initialize dd first time we get here
    return dd;
}

int main()
{
    cout << "Default date: " << default_date() << endl;
}