#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    color_button{Point{x_max()-140,40}, 140, 45, "color menu", cb_color_menu},
    line_menu{Point{x_max()-70,60},70,20,Menu::vertical,"linestyle"},
    linestyle_button{Point{x_max()-140,85},140,45,"linestyle menu",cb_line_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"scarlet",cb_dark_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"ink",cb_dark_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"white",cb_white});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});

    line_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    line_menu.attach(new Button{Point{0,0},0,0,"dashed",cb_dash});
    line_menu.attach(new Button{Point{0,0},0,0,"dotted",cb_dot});
    line_menu.attach(new Button{Point{0,0},0,0,"dash-dot",cb_dashdot});
    line_menu.attach(new Button{Point{0,0},0,0,"dashed-dot-dot",cb_dashdotdot});

    attach(color_menu);
    attach(line_menu);
    color_menu.hide();
    line_menu.hide();
    attach(color_button);
    attach(linestyle_button);


}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}