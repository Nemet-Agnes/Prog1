#include "Simple_Window.h"
#include "Graph.h"
using namespace Graph_lib;

int main(){
    Point kezdet {100,100};
    int win_x=800, win_y=1000;

    Simple_window ablak (kezdet,win_x,win_y,"Chapter 13 Drill");

    int grid_x=100;
    int grid_y=100;

    Lines keret;

    for(int x = grid_x; x<win_x; x+=grid_x){
        keret.add(Point{x,0}, Point(x,win_y-200));
    }

    for(int y = grid_y; y<win_y; y+=grid_y){
        keret.add(Point{0,y},Point(win_x,y));
    }

    win.attach(keret);

    Vector_ref<Graph_lib::Rectangle> negyzetek;

    for(int i=0; i<8; i++){
        negyzetek.push_back(new Rectangle{Point{i*100, i*100}, 100, 100});
        negyzetek[i].set_fill_color(Color::red);
        win.attach(negyzetek[i]);
    }

    Image kep1 {Point{400,100}, "harl.png"};
    win.attach(kep1);

    Image kep2 {Point{600,300}, "harl.png"};
    win.attach(kep2);

    Image kep3 {Point{100,400}, "harl.png"};
    win.attach(kep3);

    Image kep4 {Point{300,600}, "harl.png"};
    win.attach(kep4);

//---

    Image masik_kep {Point{0,0}, "joker.png"};
    win.attach(masik_kep);

    win.wait_for_button();

    int oszlopok=0;
    while(true){
        for(int i=0; i<7; i++){
            masik_kep.move {100,0};
            win.wait_for_button();
        }
        if(oszlopok==7){
            oszlopok=0;
            masik_kep.move(-700,700);
        }
        else{
            masik_kep.move(-700,100);
            oszlopok++;
        }
        win.wait_for_button();
    }
    win.wait_for_button();
}