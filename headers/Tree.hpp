#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

#include "String.hpp"
#include "utils.hpp"

using namespace std;

struct Node {
    String val;

    Node *left;
    Node *right;

    Node(String val) {
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

    void buildTreeByStr(String *strArr, int lenArr);

    void loadPrf(String *strArr, int lenArr);
    void loadPst(String *strArr, int lenArr);

    void printTreePrf();
    void printTreePst();
    void printTreeInOrder();
    void free_tree();

    void fillTree(String *strArr, int strLen);
    void eval();

private:
    Node* loadPrf(String *strArr, int lenArr, Node *node, int *i);
    Node* loadPst(String *strArr, int lenArr, Node *node, int *i);

    void free_treePrivate(Node *node);
    void printTreePrf(Node *node);
    void printTreePst(Node *node);
    void printTreeInOrder(Node *node);
    int eval(Node *node, Node *prevNode);
    Node *buildTreeByStr(String *strArr, int lenArr, Node *node, int idxStart);

    void fillTree(String *strArr, int strLen, Node *node);

    Node *root;
};

#endif