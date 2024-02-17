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
   int i = 0;
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);  

   do {
      cout << "Going to sleep...." << endl;
      if( i == 3 ) {
         raise( SIGINT);
      }
      //sleep(1);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));

      i++;

   } while (i < 50);

   return 0;
}