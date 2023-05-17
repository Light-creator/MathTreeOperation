#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

using namespace std;
extern int splitByOperators(String str, String *strArr);
extern int splitBySpace(String str, String *strArr);
extern int splitByFirstSpace(String str, String *strArr);
extern int splitBySeps(String str, String *strArr, String seps);
extern bool isNumeric(String str);
extern int NOK(int a, int b);
extern int pow(int a, int b);
extern void getLine(istream & is, String & _s);
int stoi(String &st);

#endif // UTILS_H_INCLUDED