#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct S{
    private:
    T val;

    public:
    explicit S(T v=0) : val{v} {};

    const T& get();
    S& operator= (const T& new_val);
//    void set(T vv);

};

template <typename T>
const T& S<T>:: get(){
        return val;
    }
template <typename T>
S<T>& S<T>::operator= (const T& new_val){
    val=new_val;
    return *this;
}
/*
template <typename T>
void S<T>::set(T vv)
{
    val=vv;
}
*/

template <typename T>
void read_val(T& value){
    cin>>value;
}

template <typename T>
ostream& operator<< (ostream& os, vector<T>& v){
    os<<"{";

    for(auto lm : v)
        os<<lm<<(lm==v[v.size()-1] ? "" : ", ");
    os<<"}";

    return os;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v){
    char braces;
    is>>braces;
    if(braces!='{')
        is.clear();
    int val;
    while(is>>val){
        v.push_back(val);
        is>>braces;
        if(braces!=',')
            break;
    }

    return is;
}



int main(){
    S<int> sint (13);
    int i;
    cout<<"Add an integer: "<<endl;
    read_val(i);
    sint=i;

    S<char> schar ('Y');
    char c;
    cout<<"Add a char: "<<endl;
    read_val(c);
    schar=c;
//    schar.set('W');

    S<double> sdouble (3.141592);
    double d;
    cout<<"Add a double: "<<endl;
    read_val(d);
    sdouble=d;

    S<string> sstring ("Nagyon jó szöveg");
//    sstring="Csodás szöveg";
    string s;
    cout<<"Add string: "<<endl;
    read_val(s);
    sstring=s;

    S<vector<int>> svector (vector<int> {0, 1, 2, 3, 4});

    cout<<"int: "<<sint.get()<<"\n"
        <<"char: "<<schar.get()<<"\n"
        <<"double: "<<sdouble.get()<<"\n"
        <<"string: "<<sstring.get()<<endl;

    cout<<"Vector<int> {val, val, val}"<<endl;
    vector<int> test;
    read_val(test);
    cout<<test;

    return 0;
}