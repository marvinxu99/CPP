#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    map<string, int> fruits{
        {"Apple", 7},
        {"Plum", 8},
        {"Grape", 2345},
        {"Kiwi", 100},
        {"Orange", 99},
        {"Quince", 0}};

    auto res = fruits.insert(pair("Melon", 100));
    if (res.second)
    {
        cout << "inserted" << endl;
    }
    else
    {
        cout << "Not inserted" << endl;
    }

    auto res2 = fruits.insert(pair("Melon", 100));
    if (res2.second)
    {
        cout << "inserted" << endl;
    }
    else
    {
        cout << "Not inserted" << endl;
    }

    for (auto el : fruits)
    {
        cout << el.first << ", " << el.second << endl;
    }
}