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
        cout << "Enter the command: ";
        getline(cin, mainStr);

        int lenCmd = splitBySpace(mainStr, strArr);
        if(strArr[0] == "exit") break;
        else if(strArr[0] == "parse") {
            int lenArr = splitByOperators(strArr[1], strArr);
            tree->buildTreeByStr(strArr, lenArr);
            tree->printTreePrf();
        } else if(strArr[0] == "load_prf") {
            int lenArr = splitByOperators(mainStr, strArr);
            tree->buildTreeByStr(strArr, lenArr);
        } else if(strArr[0] == "load_pst") {
            int lenArr = splitByOperators(mainStr, strArr);
            tree->buildTreeByStr(strArr, lenArr);
        } else if(strArr[0] == "save_prf") {
            tree->printTreePrf();
        } else if(strArr[0] == "save_pst") {
            tree->printTreePst();
        }
    }

    delete[] strArr;
}

// (9+3)-5*(25-1)
// 5*(14-4*2)/2



// (9+3)-5*(25-1)
// Build
