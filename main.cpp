#include <iostream>
#include <string>

#include "utils.hpp"
#include "Tree.hpp"

using namespace std;


int main() {
    string mainStr;

    string *strArr = new string[50];
    BTree *tree = new BTree();

    while(1) {
        cout << "1) exit" << endl;
        cout << "2) parse ..." << endl;
        cout << "3) load_prf ..." << endl;
        cout << "4) load_pst ..." << endl;
        cout << "6) save_prf" << endl;
        cout << "7) save_pst" << endl;
        cout << "8) eval ..." << endl;
        cout << "Enter the command: ";
        getline(cin, mainStr);

        int lenCmd = splitByFirstSpace(mainStr, strArr);
        if(strArr[0] == "exit") break;
        else if(strArr[0] == "parse") {
            int lenArr = splitByOperators(strArr[1], strArr);
            tree->buildTreeByStr(strArr, lenArr);
        } else if(strArr[0] == "load_prf") {
            int lenArr = splitBySpace(strArr[1], strArr);
            tree->loadPrf(strArr, lenArr);
            tree->printTreeInOrder();
        } else if(strArr[0] == "load_pst") {
            int lenArr = splitBySpace(strArr[1], strArr);
            tree->loadPst(strArr, lenArr);
            tree->printTreeInOrder();
        } else if(strArr[0] == "save_prf") {
            tree->printTreePrf();
        } else if(strArr[0] == "save_pst") {
            tree->printTreePst();
        } else if(strArr[0] == "eval") {
            int lenArr = splitBySeps(strArr[1], strArr, " =");
            tree->fillTree(strArr, lenArr);
            tree->eval();
        } else {
            cout << "Incorrect command..." << endl;
        }
    }

    delete[] strArr;
}

// (9+3)-5*(25-1)
// a*(b-c*d)/e
// / * 5 - 14 * 4 2 2 
// 5 14 4 2 * - * 2 /


// (9+3)-5*(25-1)
// Build
