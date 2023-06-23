#include <iostream>

#include "String.hpp"
#include "utils.hpp"
#include "Tree.hpp"

using namespace std;
/*
int main() {
    String s1 = "Hello";
    String s2 = "Hello";
    String s3 = s1+s2;
    String s4 = s3 + s1;
    cout << s4 << endl;

    return 0;
} */

int main() {
    String mainStr;

    String *strArr = new String[50];
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
        getLine(cin, mainStr);

        int lenCmd = splitByFirstSpace(mainStr, strArr);
        if(strArr[0] == "exit") break;
        else if(strArr[0] == "parse") {
            int lenArr = splitByOperators(strArr[1], strArr);
            tree->buildTreeByStr(strArr, lenArr);
            tree->printTreeInOrder();
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


// parse (9+3)-5*(25-1)
// parse a*(b-c*d)/e
// eval a=2 b=50 c=2 d=2 e=2
// / * 5 - 14 * 4 2 2 
// 5 14 4 2 * - * 2 /
/*

(22-(1+1))/(5*(6-(2+2))) =2
(((1))) =1
((((1)*2)) =2
(((((((5))))))) =5
(1+2*(1-2)) =-1
(1+2*(1-2))*(1+2*(1-2)) = 1

2/2+3*4-6 =7
2*(2*(2*(2*1))) =16
3*(4+7)-6 =27
1*2*3*4*5+20/5 =124
1*2*3*4*(5+20)/5 =120
*/

// (9+3)-5*(25-1)
// Build
