#include <iostream>
#include <cstring>
using namespace std;
#include "String.hpp"

using std::ostream;
using std::istream;

String::String() {
    sLen = 0;
    s = new char[1];
    s[0] = '\0';
}

String::String(const char *_s) {
    sLen = strlen(_s);
    s = new char[sLen+1];
    strcpy(s, _s);
}

String::String(const String &_s) {
    sLen = _s.sLen;
    s = new char[sLen+1];
    strncpy(s, _s.s, sLen);
}

String::~String() {
    delete[] s;
}

String & String::operator=(const String & _s){

    if(this == &_s) return *this;
    
    delete[] s;
    sLen = _s.sLen;
    s = new char[sLen+1];
    strcpy(s, _s.s);
    s[sLen] = '\0';
    return *this;
}

String & String::operator=(const char * _s){
    delete[] s;
    sLen = strlen(_s);
    s = new char[sLen+1];
    strcpy(s, _s);
    s[sLen] = '\0';
    return *this;
}

String & String::operator=(char c) {
    delete[] s;
    sLen = 1;
    s = new char[sLen+1];
    s[0] = c;
    s[sLen] = '\0';
    return *this;
}

char & String::operator[](int i){
    return s[i];
}

const char & String::operator[](int i) const{
    return s[i];
}

bool operator==(const String &st, const String &st2){
    if(strcmp(st.s, st2.s) == 0) 
        return 1;
    else 
        return 0;
}

String operator+(const String& st1, const String& st2){
    String t;
    t.sLen = st1.sLen + st2.sLen;
    t.s = new char[t.sLen + 1];
    strcpy(t.s, st1.s);
    strcpy(t.s+st1.sLen, st2.s);
    t.s[t.sLen] = '\0';
    return t;
}

String operator+(String& st1, const String& st2){
    String t;
    t.sLen = st1.sLen + st2.sLen;
    t.s = new char[t.sLen + 1];
    strcpy(t.s, st1.s);
    strcpy(t.s+st1.sLen, st2.s);
    t.s[t.sLen] = '\0';
    return t;
}

String operator+(const String& st1, char c){
    String t;
    delete[] t.s;
    t.sLen = st1.sLen + 1;
    t.s = new char[t.sLen + 1];
    strcpy(t.s, st1.s);
    t.s[t.sLen-1] = c;
    t.s[t.sLen] = '\0';
    return t;
}

ostream & operator<<(ostream & os, const String &st2){
    os << st2.s;
    return os;
}

istream & operator>>(istream & is, String & st){
    char temp[500];
    is.get(temp, 500);
    if (is)
        st = temp;
    while (is && is.get() != '\n') continue;
    return is;    
}

void String::clear() {
    delete[] s;
    sLen = 0;
    s = new char[sLen];
}
