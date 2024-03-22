#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> mySet{10, 20, 30};
    mySet.insert(40);

    for (const auto &elm : mySet)
    {
        cout << elm << " ";
    }
    cout << endl;
}
