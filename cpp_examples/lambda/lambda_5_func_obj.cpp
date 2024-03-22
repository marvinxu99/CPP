#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

struct Record
{
    double unit_price;
    int units; // number of units sold
    // . . .
};

double price(double v, const Record &r)
{
    return v + r.unit_price * r.units; // calculate price and accumulate
}

struct Price_func
{
    double operator()(double v, const Record &r) const
    {
        return v + r.unit_price * r.units; // calculate price and accumulate
    }
};

int main()
{
    vector<Record> r{{2.3, 3}, {1.2, 10}, {3.2, 4}, {2, 3}};

    double s = 0;
    s = accumulate(r.begin(), r.end(), 0.0, price);

    cout << "total price: " << s << endl;

    double s2 = 0;
    s2 = accumulate(r.begin(), r.end(), 0.0, [](double v, const Record r)
                    { return v + r.unit_price * r.units; });
    cout << "total price: " << s2 << endl;

    double s3 = 0;
    s3 = accumulate(r.begin(), r.end(), 0.0, Price_func());
    cout << "total price: " << s3 << endl;
}