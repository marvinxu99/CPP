#include <iostream>

using namespace std;

class Line {

   public:
      int getLength( void );
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len) {
   cout << "Normal constructor allocating ptr" << endl;
   
   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;
}

Line::Line(const Line &obj) {
   cout << "Copy constructor allocating ptr." << endl;
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

Line::~Line(void) {
   cout << "Freeing memory!" << endl;
   delete ptr;
}

int Line::getLength( void ) {
   return *ptr;
}

// Pass object as value
void display(Line obj) {
   cout << "Length of line : " << obj.getLength() <<endl;
}

// Pass object as pointer
void display2(Line *obj) {
   cout << "Length of line : " << obj->getLength() <<endl;
}

// Pass object as reference
void display3(Line &obj) {
   cout << "Length of line : " << obj.getLength() <<endl;
}

// Main function for the program
int main() {
   Line line(10);

   display(line);   // Pass as value so copy constructor is called
   cout << "After display (pass as value)" << endl;

   display2(&line);
   cout << "After display (pass as pointer)" << endl;

   display3(line);
   cout << "After display (pass as reference)" << endl;

   return 0;
}
