#include <fstream>
#include <iostream>

using namespace std;
 
int main () {
   char data[100];
   //string data;


   // open a file in write mode.
   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   //getline(cin >> std::ws, data);
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile; 
   infile.open("afile.dat"); 

   cout << "Reading from the file" << endl; 

   string out_str;
   //while (getline(infile, out_str))
   //{
   //   cout << out_str << endl;
   //}
   while (infile.getline(data, 100))
   {
       cout << data << endl;
   }

   // close the opened file.
   infile.close();

   return 0;
}
