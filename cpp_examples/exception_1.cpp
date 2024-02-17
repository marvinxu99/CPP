#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};
 
int main() {
   try {
      throw MyException();
   } catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(std::exception& e) {
      //Other errors
   }
}

/*
This would produce the following result −

MyException caught
C++ Exception

Here, what() is a public method provided by exception class and it has been overridden by all the child exception classes. This returns the cause of an exception.
*/