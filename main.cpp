#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "tree.h"
using namespace std;


template <typename T>

tuple<int, T> pars(T str){
    vector<pair<char, int>> v;
    pair<char, int> foo =make_pair('e', 0);
    int j=0;
    for (auto f : str) {
        if ((f == '/') || (f == '*') || (f == '+') || (f == '-') || (f == '^')) {
            foo = make_pair(f, j);
            v.push_back(foo);
        }
        j++;
    }

    int n= v.size();
    bool cnt= true;
    T f1;
    int f2;

    for (int i= 0; i<n; i++){
        auto f=v[n-1-i];
        if ((f.first == '+') || (f.first == '-')) {cnt= false;f1=f.first; f2= f.second; break; }
    }
    if(cnt) {
        for (int i= 0; i<n; i++) {
            auto f=v[n-1-i];
            if ((f.first == '*') || (f.first == '/')) {cnt= false; f1=f.first; f2= f.second;break;}
        }
    }
    if(cnt){
        for (int i= 0; i<n; i++) {
            auto f=v[n-1-i];
            if (f.first == '^') {cnt= false;f1=f.first; f2= f.second; break;}
        }}

    return  make_tuple(f2, f1);
};

int main() {

    string str= "7+2*4^2";
    Tree<string> tree(str);
    cout << tree.start();

    return 0;
}