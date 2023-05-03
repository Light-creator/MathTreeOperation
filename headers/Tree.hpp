#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>

#include "utils.hpp"

using namespace std;

struct Node {
    string val;

    Node *left;
    Node *right;

    Node(string val) {
        this->val = val;
        this->left = nullptr; 
        this->right = nullptr;
    }
};

class BTree {

public:
    BTree() {
        root = nullptr;
    }
    ~BTree() {
        free_tree();
    }

    int isEmpty() {
        return (root == nullptr);
    }

    void buildTreeByStr(string *strArr, int lenArr);

    void loadPrf(string *strArr, int lenArr);
    void loadPst(string *strArr, int lenArr);

    void printTreePrf();
    void printTreePst();
    void printTreeInOrder();
    void free_tree();

private:
    Node* loadPrf(string *strArr, int lenArr, Node *node);
    Node* loadPst(string *strArr, int lenArr, Node *node);

    void free_treePrivate(Node *node);
    void printTreePrf(Node *node);
    void printTreePst(Node *node);
    void printTreeInOrder(Node *node);
    Node *buildTreeByStr(string *strArr, int lenArr, Node *node, int idxStart);

    Node *root;
};

#endif