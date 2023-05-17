#include <iostream>

#include "String.hpp"
using namespace std;

extern int splitBySpace(String str, String *strArr)
{
    for (int i = 0; i < 50; i++)
        strArr[i].clear();
    int strLen, idxRes, count;

    strLen = str.length();
    idxRes = count = 0;
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == ' ')
        {
            idxRes = 0;
            count++;
        }
        else
        {
            strArr[count] = strArr[count] + (char)str[i];
        }
    }
    return count + 1;
}

extern int splitBySeps(String str, String *strArr, String seps)
{
    for (int i = 0; i < 50; i++)
        strArr[i].clear();
    int strLen, idxRes, count;

    int sepsLen = seps.length();

    strLen = str.length();
    idxRes = count = 0;
    for (int i = 0; i < strLen; i++)
    {
        bool f = false;
        for (int j = 0; j < sepsLen; j++)
        {
            if (str[i] == seps[j])
            {
                idxRes = 0;
                count++;
                f = true;
                break;
            }
        }
        if (!f)
        {
            strArr[count] = strArr[count] + (char)str[i];
        }
    }
    return count + 1;
}

extern int NOK(int a, int b)
{
    int n = (a < b) ? a : b;

    while (n % b != 0 || n % a != 0)
        n++;

    return n;
}

extern int pow(int a, int b)
{
    int res = a;
    for (int i = 0; i < b; i++)
    {
        res *= a;
    }

    return res;
}

extern bool isNumeric(String str)
{
    int i = 0;
    while (i < str.sLen)
    {
        if (!isdigit(str.s[i]))
        {
            return false;
        }
    }
    return true;
}

extern int splitByFirstSpace(String str, String *strArr)
{
    for (int i = 0; i < 50; i++)
        strArr[i].clear();
    int strLen, idxRes, count;

    strLen = str.length();
    count = 0;
    bool f = 0;
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == ' ' && !f)
        {
            f = 1;
            count++;
        }
        else
        {
            strArr[count] = strArr[count] + (char)str[i];
        }
    }
    return 2;
}

extern int splitByOperators(String str, String *strArr)
{
    for (int i = 0; i < 50; i++)
        strArr[i].clear();

    int flag, idxArr, idxRes, strLen, prevFlagSep;
    char sep;
    char seps[9]{'(', ')', '@', '^', '*', '/', '%', '+', '-'};
    String strRes;

    idxArr = idxRes = prevFlagSep = 0;
    strLen = str.length();
    for (int i = 0; i < strLen; i++)
    {
        flag = 0;
        for (int j = 0; j < 9; j++)
        {
            if (seps[j] == str[i])
            {
                flag = 1;
                sep = seps[j];
                break;
            }
        }

        if (flag)
        {
            if (prevFlagSep)
            {
                strArr[idxArr] = sep;
                idxArr++;
            }
            else
            {
                strArr[idxArr + 1] = sep;
                idxArr += 2;
            }
            prevFlagSep = 1;
            idxRes = 0;
        }
        else
        {
            prevFlagSep = 0;
            strArr[idxArr] = strArr[idxArr] + (char)str[i];
            idxRes++;
        }
    }
    return idxArr + 1;
}

void getLine(istream &is, String &_s)
{
    _s.clear();
    String tmp;
    char c;
    while (is.get(c) && c != '\n')
    {
        String newS = tmp + c;
        tmp = newS;
        _s.sLen++;
        if (!is.bad())
            _s = tmp;
        if (!is.bad() && is.eof())
            is.clear(std::ios_base::eofbit);
    }
}

int stoi(String &st)
{
    int i = 0;
    int num = 0;
    while (st.s[i] != '\0')
    {
        int t = st.s[i]-'0';
        num += num * 10 + t;
        i++;
    }

    return num;
}
