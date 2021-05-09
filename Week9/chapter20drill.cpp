#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
void print_val(T temp){
    for(auto lm : temp)
        cout<<lm<<" ";
        cout<<endl;
}

template<typename T>
void increase(T& temp, const int val){
    for(auto& lm : temp){
        lm+=val;
    }
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p = f1; p!= e1; p++){
        *f2 = *p;
        f2++;
    }

    return f2;
}


int main(){
    const int size=10;

//    int arr [size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, size> ari = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list <int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    array<int, size> ari2 = ari;
    vector<int> v2 = v;
    list <int> l2 = l;

//    print_val(ari);

    cout<<"Array: ";
    increase(ari, 2);
    print_val(ari);
    cout<<"Vector: ";
    increase(v, 3);
    print_val(v);
    cout<<"List: ";
    increase(l,5);
    print_val(l);

    //array->vector
    //list->array

    my_copy(ari.begin(), ari.end(), v.begin());
    my_copy(l.begin(), l.end(), ari.begin());

    vector<int>::iterator vfind;
    vfind = std::find(v2.begin(), v2.end(), 3);
    if(vfind != v2.end()){
        cout<<distance(v2.begin(), vfind)<<endl;
    }
    else{
        cout<<"Does not contain"<<endl;
    }

    list<int>::iterator lfind;
    lfind=std::find(l2.begin(), l2.end(), 27);
    if(lfind == l2.end()){
        cout<<"Does not contain"<<endl;
    }
    else{
        cout<<distance(l2.begin(), lfind)<<endl;
    }


    return 0;
}