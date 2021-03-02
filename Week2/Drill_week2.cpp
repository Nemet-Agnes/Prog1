#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
//-------------

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{100,100},600,400,"My window"};

	Axis xa {Axis::x, Point(20,300),280,10,"X tengely"};
	Axis ya {Axis::y, Point(20,300),280,10,"Y tengely"};
	xa.set_color(Color::blue);
	ya.set_color(Color::yellow);

	Function sinfuggveny {sin,0,100,Point{20,150},1000,50,50};
	sinfuggveny.set_color(Color::white);

	Graph_lib::Polygon poly1;
	poly1.add(Point{400,200});
	poly1.add(Point{400,350});
	poly1.add(Point{650,350});
	
	poly1.set_fill_color(Color::dark_blue);


	Graph_lib::Rectangle teglalap {Point{600,50},100,150};
	teglalap.set_fill_color(Color::yellow);

	Circle kor {Point{150,150},50};
	kor.set_fill_color(Color::yellow);

	Mark pont {Point{220,220},'p'};

	Image kutyae {Point{50,50},"dog.jpg"};

	Text felirat {Point{612,50}, "Jó napot kívánok! Ma esni fog a hó! :D"};
	felirat.set_font_size(18);

	
//--------------------------
	win.attach(kutyae);
	win.attach(xa);
	win.attach(ya);
	win.attach(sinfuggveny);
	win.attach(poly1);
	win.attach(teglalap);
	win.attach(felirat);
	win.attach(kor);
	win.attach(pont);
	win.wait_for_button();
}