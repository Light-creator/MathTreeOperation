#include <iostream>
#include <string>

#include "utils.hpp"
#include "Tree.hpp"

using namespace std;


// Print Tree
void BTree::printTreeInOrder(Node *node) {
    if(node == NULL) return;
    printTreeInOrder(node->left);
    cout << node->val << " ";
    printTreeInOrder(node->right);
}  

void BTree::printTreePrf(Node *node) {
    if(node == NULL) return;
    cout << node->val << " ";
    printTreePrf(node->left);
    printTreePrf(node->right);
}  

void BTree::printTreePst(Node *node) {

    if(node == NULL) return;
    printTreePst(node->left);
    printTreePst(node->right);
    cout << node->val << "1";
}   


void BTree::printTreeInOrder() {
    cout << "{" << endl;
    printTreeInOrder(root);
    cout << endl;
    cout << "}" << endl;
}

void BTree::printTreePrf() {
    cout << "{" << endl;
    printTreePrf(root);
    cout << endl;
    cout << "}" << endl;
}

void BTree::printTreePst() {
    cout << "{" << endl;
    printTreePst(root);
    cout << endl;
    cout << "}" << endl;
}


// Parse Expr
Node* BTree::buildTreeByStr(string *strArr, int lenArr, Node *node, int idxStart) {
    if(lenArr-idxStart <= 2) {
        int newIdx;
        if(strArr[idxStart][0] == ')') newIdx = idxStart-1;
        else newIdx = idxStart;

        node = new Node(strArr[newIdx]);
        return node;
    }

    int countScob, minPrior, idxMinPrior;
    countScob = 0;

    minPrior = 1000; idxMinPrior = 0;
    string arr[4] = {"+-", "*/%", "^", "@"};
    for(int i=idxStart; i<lenArr; i++) {
        if(strArr[i][0] == '(') countScob++;
        else if(strArr[i][0] == ')') countScob--;

        if(countScob == 0) {
            if(!isdigit(strArr[i][0])) {
                for(int j=0; j<4; j++) {
                    for(int x=0; x<arr[j].length(); x++) {
                        if(arr[j][x] == strArr[i][0] && minPrior >= j) {
                            minPrior = j;
                            idxMinPrior = i;
                        }
                    }
                }
            }
        }
    }

    if(minPrior == 1000) return buildTreeByStr(strArr, lenArr, node, idxStart+1);
    else {
        node = new Node(strArr[idxMinPrior]);
        node->left = buildTreeByStr(strArr, idxMinPrior, node->left, idxStart);
        node->right = buildTreeByStr(strArr, lenArr, node->right, idxMinPrior+1);

        return node;
    }

    return nullptr;
}

void BTree::buildTreeByStr(string *strArr, int lenArr) {
    root = buildTreeByStr(strArr, lenArr, root, 0);
}

// Load Prf
Node* BTree::loadPrf(string *strArr, int lenArr, Node *node) {
    return nullptr;
}

void BTree::loadPrf(string *strArr, int lenArr) {
    root = loadPrf(strArr, lenArr, root);
}

// Free Memory
void BTree::free_treePrivate(Node *node) {
    if(node != NULL) {
        free_treePrivate(node->left);
        free_treePrivate(node->right);
    }
    delete node;
}

void BTree::free_tree() {
    free_treePrivate(root);
}