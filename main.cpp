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

// Solo debería pedirte una vez ingresar la variable, si uso por ejemplo 'a' en dos lugares en tu programa, 
// me pide dos veces que ingrese a
// Con el operador unario no funciona, e.g. -(5+4)
// Tampoco simplifica operadores, e.g. 5+-+-+-5

// Probar con: 
// (17*3/2-a)^b    a=5, b=1  Resultado esperado: 20.5
int main(int argc, char const *argv[]) {

    //string str= "(7+3)*2^2";
    string equation;
    if (argc == 2) {
        equation = argv[1];
    }
    else {
      throw "One argument expected";
    }

    Tree<string> tree(equation);
    cout << tree.start() << endl;

    return 0;
}