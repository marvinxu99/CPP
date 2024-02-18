// 10-smartptr2.cpp : encapsulate a FILE* in a unique_ptr
 
#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;
 
int main(int argc, const char *argv[]) {
    if (argc != 2) {
        cerr << "Syntax: " << argv[0] << " <filename>\n";
        return 1;
    }
 
    unique_ptr<FILE, decltype(&fclose)> fp{ fopen(argv[1], "rb"), fclose };
 
    if (fp) {
        int c;
        while ((c = fgetc(fp.get())) != EOF) {
            putchar(c);
        }
    }

}

/* A couple of things to note about this program:

- Here std::make_unique cannot be used, nor can the type of the std::unique_ptr be deduced automatically. 
Also, we have to specify the type of the deleter explicitly: decltype(&fclose) provides us with a function pointer type.

- The member function get() is used to access the raw pointer needed for the call to the C Library function fgetc(). 

- The member function reset() changes the object owned by the std::unique_ptr; calling reset(nullptr) releases and destroys the object early
*/
