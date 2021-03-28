#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

double one(double x) {
    return 1;
}

double slope(double x){
    return x/2;
}

double square(double x){
    return x*x;
}

double cos_slope(double x){
    return slope(x)+cos(x);
}

int main(){
	int win_height=600, win_width=600;
	Point kozep{win_width/2,win_height/2};

	Simple_window win (Point{100,100},win_width,win_height,"Function graphs");

    Axis x_tengely (Axis::x, Point{100,300},400,20,"1==20 pixel");
	x_tengely.set_color(Color::red);
	win.attach(x_tengely);

	Axis y_tengely (Axis::y, Point{300,500},400,20,"1==20 pixel");
	y_tengely.set_color(Color::red);
	win.attach(y_tengely);

    int range_min=-10, range_max=11;
	int points=400;
	int x_scaling=20, y_scaling=20;

	Function onefunction(one,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(onefunction);

	Function slopefunction(slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(slopefunction);

	Text label {Point {500,190}, "x/2"};
	win.attach(label);

	Function squarefunction(square,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(squarefunction);

	Function cosfunction([](double x){return cos(x);},
		range_min, range_max, origo, points, x_scaling, y_scaling);
	    cosfunction.set_color(Color::blue);
	win.attach(cosfunction);

	Function cosslopefunction(cos_slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(cosslopefunction);

	win.wait_for_button();
}
