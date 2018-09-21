//
// Created by Sebastian on 20/09/2018.
//

#ifndef SOLVER4REAL_NODE_H
#define SOLVER4REAL_NODE_H


template <typename T>
struct Node {
    T data;
    struct Node* right= nullptr;
    struct Node* left= nullptr;
    void killSelf();
};

#endif //SOLVER4REAL_NODE_H
