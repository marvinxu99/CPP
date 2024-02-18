// 10-smartptr1.cpp : use of unique_ptr
 
#include <iostream>
#include <string>
#include <string_view>
#include <memory>
using namespace std;
 
class Simple {
    string str;
public:
    Simple(string_view s) : str{s}
    { cout << "Simple(): " << str << '\n'; }
    
    ~Simple()
    { cout << "~Simple(): " << str << '\n'; }
};
 
int main(int argc, const char *argv[]) {
    unique_ptr<Simple> p1{ new Simple("p1") };
    Simple *p2 = new Simple("p2");

    Simple p21 = Simple("p21");
    
    {
        auto p3 = make_unique<Simple>("p3");      //preferred way
        if (argc > 1) {
            
            throw exception{};

            return 1;
        }

        delete p2;
        p2 = nullptr;
    }
}

/* A few things to note about this program:

- A std::unique_ptr is initialized with a pointer to a heap object. The pointer type 
needs to be provided in case it needs to be a (different) base class type, such 
as a std::unique_ptr<Shape> initialized with a new Triangle().

- This initialization has a direct analogy with initialization of raw pointers.

- An alternative way to create a std::unique_ptr is by using the helper function std::make_unique 
as used to create p3. This is the preferred way in many cases due to its exception safety, so you will find this in code.

- A std::unique_ptr created within a sub-scope is destroyed at the end of the sub-scope. Otherwise, as with 
all stack objects, they are destroyed in the reverse order in which they were created.
*/