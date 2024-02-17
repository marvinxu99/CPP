#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>

using namespace std;

void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here  
   // terminate program  

   exit(signum);  
}

int main () {
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);  

   while(1) {
      cout << "Going to sleep...." << endl;
     //sleep(1);
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }

   return 0;
}

/*
When the above code is compiled and executed, it produces the following result −

Going to sleep....
Going to sleep....
Going to sleep....
Now, press Ctrl+c to interrupt the program and you will see that your program will catch the signal and would come out by printing something as follows −

Going to sleep....
Going to sleep....
Going to sleep....
Interrupt signal (2) received.

*/