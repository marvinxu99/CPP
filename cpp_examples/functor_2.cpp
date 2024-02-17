// 10-functor2.cpp : function object maintaining state
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
 
struct MinMaxAvg {
    void operator()(int i) {
        if (first) {
            min = max = avg = i;
            first = false;
            return;
        }
        if (i < min) {
            min = i;
        }
        if (i > max) {
            max = i;
        }
        avg = ((avg * num) + i) / (num + 1);
        ++num;
    }
    int min, max, num{ 1 };
    double avg;
    bool first{ true };
};

void func(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    ++n1; // increments the copy of n1 stored in the function object
    ++n2; // increments the main()'s n2
    // ++n3; // compile error
}

int main() {
    vector<int> v{ 3, 5, 2, 6, 2, 4 };
    MinMaxAvg f;

    for_each(begin(v), end(v), ref(f));
    // for (auto iter = v.begin(); iter != v.end(); iter++){
    //     f(*iter);
    // }

    cout << "Min: " << f.min << " Max: " << f.max
        << " Avg: " << f.avg << " Num: " << f.num << '\n';
    

    //
    // show the difference in ref(), cref()
    int n1 = 1, n2 = 2, n3 = 3;
    function<void()> bound_f = bind(func, n1, std::ref(n2), std::cref(n3));
    n1 = 10;
    n2 = 11;
    n3 = 12;
    std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    bound_f();
    std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';      
}