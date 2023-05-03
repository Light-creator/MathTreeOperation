#include <iostream>
#include <string>
using namespace std;

extern int splitBySpace(string str, string *strArr) {
    for(int i=0; i<50; i++) strArr[i].clear();
    int strLen, idxRes, count;

    strLen = str.length();
    idxRes = count = 0;
    for(int i=0; i<strLen; i++) {
        if(str[i] == ' ') {
            idxRes = 0;
            count++;
        } else {
            strArr[count] += (char)str[i];
        }
    }
    return count + 1;
}

extern int splitByOperators(string str, string *strArr) {
    for(int i=0; i<50; i++) strArr[i].clear();

    int flag, idxArr, idxRes, strLen, prevFlagSep;
    char sep;
    char seps[9] {'(', ')', '@', '^', '*', '/', '%', '+', '-'};
    string strRes;

    idxArr = idxRes = prevFlagSep = 0;
    strLen = str.length();
    for(int i=0; i<strLen; i++) {
        flag = 0;
        for(int j=0; j<9; j++) {
            if(seps[j] == str[i]) {
                flag = 1; 
                sep = seps[j];
                break;
            }
        }

        if(flag) {
            if(prevFlagSep) {
                strArr[idxArr] = sep;
                idxArr++;
            } else {
                strArr[idxArr+1] = sep;
                idxArr += 2;
            }
            prevFlagSep = 1;
            idxRes = 0;
        } else {
            prevFlagSep = 0;
            strArr[idxArr] += (char)str[i];
            idxRes++;
        }
    }
    return idxArr+1;
}
