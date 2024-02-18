// 10-lambda1.cpp : simple lambda which produces output
 
#include <iostream>
using namespace std;


class func_2 
{
public:
    // func_2() = default;
    // func_2(const T& value) : value{ value } {}
    template <typename T>
    void operator()(T&& val){
        cout << "Lambda says Template Functor and " << val << endl; 
    };
};


int main() {

    auto l1 = []{ cout << "Lambda says Hi!\n"; };
    l1();

    auto l2 = [](string_view s){ 
        cout << "Lambda says " << s << "! " << endl; 
    };
    l2("Hola");

    auto ll2 = [](auto s){ 
        cout << "Lambda says " << s << "! " << endl; 
    };
    ll2("Hola");

    auto l3 = []{
        string s;
        cout << "enter a word for hello:" << endl;
        cin >> s; 
        cout << "Lambda says " << s << "! " << endl; 
    };
    l3();

    // Use a functor to implement a lambda
    struct func_l {
        void operator()(){
            cout << "Lambda says lambada!" << endl; 
        }
    };

    func_l fun1;
    fun1();

    func_2 fun2{};
    fun2(7);

}