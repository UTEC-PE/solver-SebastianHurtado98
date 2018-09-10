#include <iostream>
#include <map>
#include <string>
#include<algorithm>

using namespace std;

void menu() {
    system("cls");
    cout<<"==========================================================="<<endl;
    cout<<"\t\tPractica Operaciones"<<endl;
    cout<<"==========================================================="<<endl;

    //char* str="7/4*((a+b)*a)+3";
    //char* str="7/4*((a+-+--b)*a)+3";
    //char* str="2+(3)";
    string str="7/4*((a+b)^4*a)+3";
}

void function(){
    string str="7/4*((a+b)^4*a)+3";

    int i=0, j=0;
    map<char, int> v;

    for (auto f : str) {
            if (f == '(') {
                i++;
            }
            if (f == ')') {
                i--;
            }
        if(i==0) {
            if ((f == '/') || (f == '*') || (f == '+') || (f == '-') || (f == '^')) {
                pair<char, int> foo;
                foo= make_pair(f, j);
                v.insert(foo);
            }
        }
        j++;
    }

    bool cnt= true;
    char f1;
    int f2;
    auto k= v.begin();
    while(k!=v.end()){
        cout << (*k).first << " ";
        k++;
    }
    cout << endl;

    for (auto f: v){
        if ((f.first == '+') || (f.second == '-')) {cnt= false;f1=f.first; f2= f.second; break; }
    }
    if(cnt) {
        for (auto f: v) {
            if ((f.first == '*') || (f.second == '/')) {cnt= false; f1=f.first; f2= f.second;break;}
        }
    }
    if(cnt){
        for (auto f: v) {
            if (f.first == '^') {cnt= false;f1=f.first; f2= f.second; break;}
        }}


        cout << f1 << f2;
}


int main(int argc, char const *argv[]) {
    //menu();

    cout << "\nPress enter to continue ...";

    const char* str="7/4*((a+b)^4*a)+3";
    function();

    cin.get();
    return EXIT_SUCCESS;
}


