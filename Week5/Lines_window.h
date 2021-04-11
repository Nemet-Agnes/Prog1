#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	Menu color_menu;
	Menu line_menu;

	Button color_button;
	Button linestyle_button;

	bool wait_for_button();

	//CallBacks
	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_dark_red(Address, Address pw){reference_to<Lines_window>(pw).dark_red_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_dark_blue(Address, Address pw) {reference_to<Lines_window>(pw).dark_blue_pressed();}
	static void cb_black(Address, Address pw){reference_to<Lines_window>(pw).black_pressed();}
	static void cb_white(Address, Address pw){reference_to<Lines_window>(pw).white_pressed();}
	static void cb_color_menu(Address, Address pw){reference_to<Lines_window>(pw).color_pressed();}

	static void cb_line_menu(Address, Address pw){reference_to<Lines_window>(pw).line_pressed();}
	static void cb_solid(Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}
	static void cb_dash(Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_dot(Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_dashdot(Address, Address pw){reference_to<Lines_window>(pw).dash_dot_pressed();}
	static void cb_dashdotdot(Address, Address pw){reference_to<Lines_window>(pw).dash_dot_dot_pressed();}

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

	//setting colors
	void change(Color c) {lines.set_color(c);}

	void red_pressed() {change(Color::red);hide_menu();}
	void dark_red_pressed(){change(Color::dark_red);hide_menu();}
	void blue_pressed(){change(Color::blue);hide_menu();}
	void dark_blue_pressed(){change(Color::dark_blue);hide_menu();}
	void white_pressed(){change(Color::white);hide_menu();}
	void black_pressed(){change(Color::black);hide_menu();}

	//part3
	void hide_menu(){color_menu.hide();color_button.show();linestyle_button.show();}
	void color_pressed(){color_button.hide();linestyle_button.hide();color_menu.show();}

	//part4
	void hide_style_menu(){line_menu.hide();linestyle_button.show();color_button.show();}
	void line_pressed(){linestyle_button.hide();color_button.hide();line_menu.show();}

	void change_ls(Line_style s) {lines.set_style(s);hide_style_menu();}
	void solid_pressed(){change_ls(Line_style::solid);}
	void dash_pressed(){change_ls(Line_style::dash);}
	void dot_pressed(){change_ls(Line_style::dot);}
	void dash_dot_pressed(){change_ls(Line_style::dashdot);}
	void dash_dot_dot_pressed(){change_ls(Line_style::dashdotdot);}

};