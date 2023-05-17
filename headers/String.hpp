#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>

using std::ostream;
using std::istream;

using namespace std;

class String {

public:
    char *s;
    int sLen;
    String();
    String(const char *_s);
    String(const String &_s);
    ~String();

    String & operator=(const String & _s);
    String & operator=(const char * _s);
    String & operator=(char c);
    char & operator[](int i);
    const char & operator[](int i) const;

    void clear();

    friend bool operator==(const String &st, const String &st2);
    friend String operator+(const String& st1, const String& st2);
    friend String operator+(String& st1, const String& st2);
    friend String operator+(const String& st1, char c);

    friend ostream & operator<<(ostream & os, const String &st2);
    friend istream & operator>>(istream & is, String & st);

    int length() const {
        return sLen;
    }
};

#endif