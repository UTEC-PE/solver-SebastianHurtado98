//
// Created by Sebastian on 20/09/2018.
//

#ifndef SOLVER4REAL_TREE_H
#define SOLVER4REAL_TREE_H
#include <iostream>
#include "node.h"
#include <string>
#include <vector>
#include <regex>
#include <tuple>
#include <math.h>

using namespace std;

template <typename T>

class Tree {
private:
    Node<T> *head;

    tuple<int, T> pars(T str) {
        vector<pair<char, int>> v;
        pair<char, int> foo;
        int j = 0;
        int i=0;
        for (auto f : str) {
            if (f=='(') i++;
            if(f==')') i--;
            if(i==0) {
                if ((f == '/') || (f == '*') || (f == '+') || (f == '-') || (f == '^')) {
                    foo = make_pair(f, j);
                    v.push_back(foo);
                }
            }
            j++;
        }

        int n = v.size();
        bool cnt = true;
        T f1;
        int f2;

        for (int i = 0; i < n; i++) {
            auto f = v[n - 1 - i];
            if ((f.first == '+') || (f.first == '-')) {
                cnt = false;
                f1 = f.first;
                f2 = f.second;
                break;
            }
        }
        if (cnt) {
            for (int i = 0; i < n; i++) {
                auto f = v[n - 1 - i];
                if ((f.first == '*') || (f.first == '/')) {
                    cnt = false;
                    f1 = f.first;
                    f2 = f.second;
                    break;
                }
            }
        }
        if (cnt) {
            for (int i = 0; i < n; i++) {
                auto f = v[n - 1 - i];
                if (f.first == '^') {
                    f1 = f.first;
                    f2 = f.second;
                    break;
                }
            }
        }

        return {f2, f1};
    };

    string clean(string str){
        //falta implementar con variables repetidas
        cout << endl << "Limpiando string de variables...";
        char letters[] = "abcdefghijklmnopqrstuvwxyz";
        int n=str.size();
        char x;
        for (int i =0; i<n; i++){
            for (auto f2: letters){
                if (str[i]==f2){
                    cout <<"Inserte el valor numérico de " <<f2 <<": ";
                    cin>>x;
                    str[i]=x;
                    cout << endl;
                }
            }
        }
        cout << endl;
        return str;

    };



public:
    Tree() {
        head = nullptr;
    };

    Tree(T str) {

        str= clean(str);
        if(parenthesis(str)){
            int n2= str.size();
            str= str.substr(1,n2-2);
        }
        auto[position, value]= pars(str);
        auto *n = new Node<T>();
        n->data = value;
        head = n;
        string right, left;
        int size = str.size();
        right = str.substr(position + 1, size - position - 1);
        left = str.substr(0, position);

        create_node(left, true, head);
        create_node(right, false, head);
    }


    void create_node(T str, bool path, Node<T> *current) {

        if(parenthesis(str)){
            int n2= str.size();
            str= str.substr(1,n2-2);
        }
        if (str.size() == 1) {
            auto *n = new Node<T>();
            n->data = str;
            if (path) {
                current->left = n;
            } else {
                current->right = n;
            }

        } else {
            auto[position, value]= pars(str);

            create_node(value, path, current);
            if (path) { current = current->left; } else { current = current->right; }
            string right, left;
            int size = str.size();
            right = str.substr(position + 1, size - position - 1);
            left = str.substr(0, position);

            create_node(left, true, current);
            create_node(right, false, current);
        }


    }
    bool is_op(T f){
        if ((f == "/") || (f == "*") || (f == "+") || (f == "-") || (f == "^")){return true;} else{return false;}
    };


    float operate(Node<T>* left, Node<T>* middle, Node<T>* right){
        float L, R;
        if(is_op(left->data)){L= operate(left->left, left, left->right);} else{L= stof(left->data);}
        if(is_op(right->data)){R= operate(right->left, right, right->right);} else{R= stof(right->data);}

        if(middle->data== "+"){
            return L+R;
        }
        if(middle->data== "-"){
            return L-R;
        }
        if(middle->data== "/"){
            return L/R;
        }
        if(middle->data== "*"){
            return L*R;
        }
        if(middle->data== "^"){
            return pow(L,R);
        }
        return 0;

    };



    float start(){

        return operate(head->left, head, head->right);
    };

    bool parenthesis(T str){
        if ((str[0]=='(')&& (str[str.size()-1]==')')) {return true;}
        else {return false;}
    };


};

//~List();

#endif //SOLVER4REAL_TREE_H
