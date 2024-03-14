#include <filesystem>

#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities
#include "lines_window.h"


int main()
try {
	Lines_window win{ Point{100,100},600,400,"lines" };

	return gui_main();
}
catch (exception& e) {
	cout << "Caught error: " << e.what() << endl;
	return 1;

}
catch (...) {
	cout << "caught unknown error." << endl;
	return 2;
}