// 10-lambda3.cpp : lambda function which calculates average of two values

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v{1, 3, 4, 5, 6};
    int v_max = 3;

    auto p = find_if(v.begin(), v.end(), [&](int x)
                     { return x > v_max; });
    if (p == v.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found: " << *p << endl;
    }
}
