#include "lines_window.h"
#include <iostream>


Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title }
	, next_button{ Point{x_max() - 150,0}, 70, 20, "Next point",
			[](Address, Address pw) {reference_to<Lines_window>(pw).next(); } }
	, quit_button{ Point{x_max() - 70,0}, 70, 20, "Quit",
			[](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } }
	, next_x{ Point{x_max() - 310,0}, 50, 20, "next x:" }
	, next_y{ Point{x_max() - 210,0}, 50, 20, "next y:" }
	, xy_out{ Point{100,0}, 100, 20, "current (x,y):" }
	, color_menu{ Point{x_max() - 70,40},70,20,Menu::vertical,"color" }

{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);

	xy_out.put("no point");

	color_menu.attach(new Button{ Point{0,0},0,0,"red",cb_red });
	color_menu.attach(new Button{ Point{0,0},0,0,"blue",cb_blue });
	color_menu.attach(new Button{ Point{0,0},0,0,"black",cb_black });

	attach(color_menu);

	attach(lines);

};


void Lines_window::quit()
{
	hide(); // curious FLTK idiom to delete window
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{ x,y });

	// update current position readout:
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

void Lines_window::cb_red(Address, Address pw) // callback for red button
{
	cout << "in cb_red" << endl;
	reference_to<Lines_window>(pw).red_pressed();

}
void Lines_window::cb_blue(Address, Address pw) // callback for blue button
{
	reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw) // callback for black button
{
	reference_to<Lines_window>(pw).black_pressed();
}
