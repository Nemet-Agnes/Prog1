#include "std_lib_facilities.h"
#include <iostream>
using namespace std;

Class B1{
    public:
        virtual void vf() const{
            cout << "B1::vf()" << endl;
        }
        void f() const{
            cout << "B1::f()" << endl;
        }
        virtual void pvf() = 0; //?
};

struct D1:B1{
    void vf() const override{
        cout << "D1::vf()" << endl;
    }
    void f() const{ //?
        cout << "D1::f()" << endl;
    }
};

struct D2:D1{
    void pvf() override{
        cout << "D2::pvf()" << endl;
    }
};

struct B2{
    virtual void pvf() = 0;
};

struct D21:B2{
    string data_member_string:"D21:pvf()";
    void pvf() override{
        cout << data_mamber_string << endl;
    }
};

struct D22:B2{
    string data_member_number = 5;
    void pvf() override {
        cout << data_member_number << endl;
    }
};

void f(B2 &ref){
    ref.pvf();
}

int main(){

//	B1 b1;
//	b1.vf();
//	b1.f();
//	D1 d1;
//	d1.vf();
//	d1.f();
//	B1& bref{d1};
//	bref.vf();
//	bref.f();

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

    return 0;
}