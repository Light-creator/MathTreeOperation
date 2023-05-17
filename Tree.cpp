#include <iostream>

#include "String.hpp"
#include "utils.hpp"
#include "Tree.hpp"

using namespace std;

// Print Tree
void BTree::printTreeInOrder(Node *node)
{
    if (node == NULL)
        return;
    printTreeInOrder(node->left);
    cout << node->val << " ";
    printTreeInOrder(node->right);
}

void BTree::printTreePrf(Node *node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    printTreePrf(node->left);
    printTreePrf(node->right);
}

void BTree::printTreePst(Node *node)
{

    if (node == NULL)
        return;
    printTreePst(node->left);
    printTreePst(node->right);
    cout << node->val << " ";
}

void BTree::printTreeInOrder()
{
    cout << "{" << endl;
    printTreeInOrder(root);
    cout << endl;
    cout << "}" << endl;
}

void BTree::printTreePrf()
{
    cout << "{" << endl;
    printTreePrf(root);
    cout << endl;
    cout << "}" << endl;
}

void BTree::printTreePst()
{
    cout << "{" << endl;
    printTreePst(root);
    cout << endl;
    cout << "}" << endl;
}

// Parse Expr
Node *BTree::buildTreeByStr(String *strArr, int lenArr, Node *node, int idxStart)
{
    if (lenArr - idxStart <= 2)
    {
        int newIdx;
        if (strArr[idxStart][0] == ')')
            newIdx = idxStart - 1;
        else
            newIdx = idxStart;

        node = new Node(strArr[newIdx]);
        return node;
    }

    int countScob, minPrior, idxMinPrior;
    countScob = 0;

    minPrior = 1000;
    idxMinPrior = 0;
    String arr[4] = {"+-", "*/%", "^", "@"};
    for (int i = idxStart; i < lenArr; i++)
    {
        if (strArr[i][0] == '(')
            countScob++;
        else if (strArr[i][0] == ')')
            countScob--;

        if (countScob == 0)
        {
            if (!isdigit(strArr[i][0]))
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int x = 0; x < arr[j].length(); x++)
                    {
                        if (arr[j][x] == strArr[i][0] && minPrior >= j)
                        {
                            minPrior = j;
                            idxMinPrior = i;
                        }
                    }
                }
            }
        }
    }

    if (minPrior == 1000)
        return buildTreeByStr(strArr, lenArr, node, idxStart + 1);
    else
    {
        node = new Node(strArr[idxMinPrior]);
        node->left = buildTreeByStr(strArr, idxMinPrior, node->left, idxStart);
        node->right = buildTreeByStr(strArr, lenArr, node->right, idxMinPrior + 1);

        return node;
    }

    return nullptr;
}

Node *BTree::loadPrf(String *strArr, int lenArr, Node *node, int *i) {
    String arr[7] = {"+", "-", "*", "/", "%", "^", "@"};
    bool f = false;
    for(int j=0; j<7; j++) {
        if(strArr[*i] == arr[j]) {
            f = true;
            node = new Node(strArr[*i]);
        }
    }

    if(!f) {
        cout << "Incorrect data...";
        return nullptr;
    }

    f = false;
    *i = *i+1;
    for(int j=0; j<7; j++) {
        if(strArr[*i] == arr[j]) {
            f = true;
            node->left = loadPrf(strArr, lenArr, node->left, i);
        }
    }
    if(!f) node->left = new Node(strArr[*i]);

    f = false;
    *i = *i+1;
    for(int j=0; j<7; j++) {
        if(strArr[*i] == arr[j]) {
            f = true;
            node->right = loadPrf(strArr, lenArr, node->right, i);
        }
    }
    if(!f) node->right = new Node(strArr[*i]);

    return node;
}

void BTree::loadPrf(String *strArr, int lenArr)
{
    int i = 0;
    root = loadPrf(strArr, lenArr, root, &i);
}

Node *BTree::loadPst(String *strArr, int lenArr, Node *node, int *i) {
    String arr[7] = {"+", "-", "*", "/", "%", "^", "@"};
    bool f = false;
    for(int j=0; j<7; j++) {
        if(strArr[*i] == arr[j]) {
            f = true;
            node = new Node(strArr[*i]);
            break;
        }
    }

    if(!f) {
        cout << "Incorrect data...";
        return nullptr;
    }

    f = false;
    *i = *i-1;
    for(int j=0; j<7; j++) {
        if(strArr[*i] == arr[j]) {
            f = true;
            node->right = loadPst(strArr, lenArr, node->right, i);
        }
    }
    if(!f) node->right = new Node(strArr[*i]);

    f = false;
    *i = *i-1;
    for(int j=0; j<7; j++) {
        if(strArr[*i] == arr[j]) {
            f = true;
            node->left = loadPst(strArr, lenArr, node->left, i);
        }
    }
    if(!f) node->left = new Node(strArr[*i]);

    return node;
}

void BTree::loadPst(String *strArr, int lenArr)
{
    int i = lenArr-1;
    root = loadPst(strArr, lenArr, root, &i);
}

void BTree::buildTreeByStr(String *strArr, int lenArr)
{
    root = buildTreeByStr(strArr, lenArr, root, 0);
}


void BTree::fillTree(String *strArr, int strLen, Node *node) {
    if(node == nullptr) return;

    String arr[7] = {"+", "-", "*", "/", "%", "^", "@"};
    bool f = false;
    for(int j=0; j<7; j++) {
        if(node->val == arr[j]) {
            f = true;
            break;
        }
    }

    if(!f) {
        for(int i=0; i<strLen; i+=2) {
            if(strArr[i] == node->val) {
                node->val = strArr[i+1];
                break;
            }
        }
    }

    fillTree(strArr, strLen, node->left);
    fillTree(strArr, strLen, node->right);
}

void BTree::fillTree(String *strArr, int strLen) {
    fillTree(strArr, strLen, root);
}


int BTree::eval(Node *node, Node *prevNode) {

    if(node->left == nullptr && node->right == nullptr) {
        return stoi(node->val);
    }

    if(!isNumeric(node->val)) {
        int num1 = eval(node->left, node);
        int num2 = eval(node->right, node);
        int res = 0;

        if(node->val == "+") res = num1 + num2;
        else if(node->val == "-") res = num1 - num2;
        else if(node->val == "*") res = num1 * num2;
        else if(node->val == "/") res = num1 / num2;
        else if(node->val == "%") res = num1 % num2;
        else if(node->val == "^") res = pow(num1, num2);
        else if(node->val == "@") res = NOK(num1, num2);

        return res;
    } else {
        cout << "error..." << endl;
    }
    return 0;
}

void BTree::eval() {
    cout << "Res = " << eval(root, nullptr) << endl;
}

// Free Memory
void BTree::free_treePrivate(Node *node)
{
    if (node != NULL)
    {
        free_treePrivate(node->left);
        free_treePrivate(node->right);
    }
    delete node;
}

void BTree::free_tree()
{
    free_treePrivate(root);
}