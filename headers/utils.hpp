#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

using namespace std;
extern int splitByOperators(string str, string *strArr);
extern int splitBySpace(string str, string *strArr);
extern int splitByFirstSpace(string str, string *strArr);
extern int splitBySeps(string str, string *strArr, string seps);
extern bool isNumeric(string str);
extern int NOK(int a, int b);
extern int pow(int a, int b);

#endif // UTILS_H_INCLUDED