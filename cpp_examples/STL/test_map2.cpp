#include <iostream>
#include <map>
#include <sstream>
#include <numeric>
using namespace std;

double weighted_value(
    const pair<string, double> &a,
    const pair<string, double> &b) // extract values and multiply
{
    return a.second * b.second;
}

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

    map<string, double> dow_price = {
        // Dow Jones Industrial index (symbol,price);
        // for up-to-date quotes see
        // www.djindexes.com
        {"MMM", 81.86},
        {"AA", 34.69},
        {"MO", 54.45},
        // . . .
    };

    map<string, double> dow_weight = {
        // Dow (symbol,weight)
        {"MMM", 5.8549},
        {"AA", 2.4808},
        {"MO", 3.8940},
        // . . .
    };

    map<string, string> dow_name = {
        {"MMM", "3M Co."},
        {"AA", "Alcoa Inc."},
        {"MO", "Altria Group Inc."},
        // . . .
    };

    // double alcoa_price = dow_price["AAA"]; // read values from a map
    // double boeing_price = dow_price["BA"];

    if (dow_price.find("AA") != dow_price.end()) // find an entry in a map
        cout << "Alcoa Inc is in the Dow\n";

    // write price for each company in the Dow index:
    for (const auto &p : dow_price)
    {
        const string &symbol = p.first; // the “ticker” symbol
        cout << symbol << '\t'
             << p.second << '\t'
             << dow_name[symbol] << '\n';
    }

    double dji_index =
        inner_product(dow_price.begin(), dow_price.end(), // all companies
                      dow_weight.begin(),                 // their weights
                      0.0,                                // initial value
                      plus<double>(),                     // add (as usual)
                      weighted_value);                    // extract values and weights
                                                          // and multiply
}