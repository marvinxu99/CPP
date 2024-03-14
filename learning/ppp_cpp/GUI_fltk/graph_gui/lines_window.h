#include "GUI.h"
#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities
#include "Point.h"
using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);


	static void cb_red(Address, Address pw); // callback for red button
	static void cb_blue(Address, Address pw); // callback for blue button
	static void cb_black(Address, Address pw); // callback for black button

	// the actions:
	void red_pressed() { change(Color::red); }
	void blue_pressed() { change(Color::blue); }
	void black_pressed() { change(Color::black); }
	void change(Color c) { lines.set_color(c); }

private:
	Button next_button; // add (next_x,next_y) to lines
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Open_polyline lines;
	Menu color_menu;
	//	Button menu_button;

	void next();
	void quit();
};

