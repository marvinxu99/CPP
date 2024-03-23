#include <iostream>
#include <set>
#include <chrono>
using namespace std;

// p.536
struct Fruit
{
    string name;
    int count;
    double unit_price;
    chrono::year_month_day last_sale_date;
    // . . .

    friend ostream &operator<<(ostream &os, const Fruit &obj)
    {
        os << "(" << obj.name << ", " << obj.count << ")";
        return os;
    }
};

struct Fruit_order
{
    bool operator()(const Fruit &a, const Fruit &b) const
    {
        return a.name < b.name;
    }
};

int main()
{
    set<Fruit, Fruit_order> inventory; // use Fruit_order(x,y) to compare Fruits
    inventory.insert(Fruit("quince", 5));
    inventory.insert(Fruit("apple", 200, 0.37));

    for (auto p = inventory.begin(); p != inventory.end(); ++p)
        cout << *p << endl;

    for (const auto &elm : inventory)
    {
        cout << elm << " ";
    }
    cout << endl;
}
