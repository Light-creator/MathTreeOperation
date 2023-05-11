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

extern int splitBySeps(string str, string *strArr, string seps) {
    for(int i=0; i<50; i++) strArr[i].clear();
    int strLen, idxRes, count;

    int sepsLen = seps.length();

    strLen = str.length();
    idxRes = count = 0;
    for(int i=0; i<strLen; i++) {
        bool f = false;
        for(int j=0; j<sepsLen; j++) {
            if(str[i] == seps[j]) {
                idxRes = 0;
                count++;
                f = true;
                break;
            }
        }
        if(!f) {
            strArr[count] += (char)str[i];
        }
    }
    return count + 1;
}

extern int NOK(int a, int b) {
    int n = (a<b) ? a : b;

    while(n%b != 0 || n%a != 0)
        n++;

    return n;
}

extern int pow(int a, int b) {
    int res = a;
    for(int i=0; i<b; i++) {
        res *= a;
    }

    return res;
}

extern bool isNumeric(string str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

extern int splitByFirstSpace(string str, string *strArr) {
    for(int i=0; i<50; i++) strArr[i].clear();
    int strLen, idxRes, count;

    strLen = str.length();
    count = 0;
    bool f = 0;
    for(int i=0; i<strLen; i++) {
        if(str[i] == ' ' && !f) {
            f = 1;
            count++;
        } else {
            strArr[count] += (char)str[i];
        }
    }
    return 2;
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
