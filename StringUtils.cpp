//
//  StringUtils.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/17.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "StringUtils.hpp"

const string StringUtils::itoa(int value, int base) {
    const char digitMap[] = "0123456789ABCDEF";
    string buf;
    if (base == 0 || base > 16) {
        // Error: may add more trace/log output here
        return buf;
    }
    
    // Take care of negative int:
    string sign;
    int _value = value;
    
    // Check for case when input is zero:
    if (_value == 0) return "0";
    if (value < 0) {
        _value = -value;
        sign = "-";
    }
    
    // Translating number to string with base:
    for (int i = 30; _value && i ; --i) {
        buf = digitMap[ _value % base ] + buf;
        _value /= base;
    }
    
    return sign.append(buf);
}

int StringUtils::hexStr2int(const string hex) {
    if(!checkhex(hex)) return -1;
    int a = 0;
    sscanf(hex.c_str(), "%x", &a);
    return a;
}

const string StringUtils::fill02(string hex) {
    if(hex.size() < 2)
        hex.insert(0, "0");
    return hex;
}

const string StringUtils::fill03(int v) {
    string ret( itoa(v, 10) );
    if(v < 10) {
        ret.insert(0, "00");
    } else if( v < 100) {
        ret.insert(0, "0");
    }
    return ret;
}

bool StringUtils::checkhex(string hex) {
    bool isvalid = true;
    string hexdict = "0123456789ABCDEF";
    touppercase(hex);
    for(unsigned long i=0; i<hex.size(); i++) {
        isvalid = hexdict.find(hex.at(i)) == string::npos;
        if(isvalid) return false;
    }
    return true;
}

void StringUtils::touppercase(string& s)
{
    for(unsigned int i = 0; i < s.size(); ++i)
        s[i] = (s[i] <= 'z' && s[i] >= 'a') ? s[i]-('a'-'A') : s[i];
}

void StringUtils::tolowercase(string& s)
{
    for(unsigned int i = 0; i < s.size(); ++i)
        s[i] = (s[i] <= 'Z' && s[i] >= 'A') ? s[i]+('a'-'A') : s[i];
}

const int StringUtils::hex01(char hex) {
    //the char which out of range will be considered as '(int)0'
    int ret = 0;
    if(hex >= 'A' && hex <= 'F') ret = (int)(hex-'A')+10;
    if(hex >= 'a' && hex <= 'f') ret = (int)(hex-'a')+10;
    if(hex >= '0' && hex <= '9') ret = (int)(hex-'0')+0;
    return ret;
}

const string StringUtils::hex02(int v) {
    return fill02(itoa(v, 16));
}

int StringUtils::hexChar2Int(char ch) {
    // the same as 'StringUtils::hex01', but the char
    // which out of range will be considered as '(int)-1'
    if((ch>='0') && (ch<='9'))
        return ch-0x30;
    else if((ch>='A')&&(ch<='F'))
        return ch-'A'+10;
    else if((ch>='a')&&(ch<='f'))
        return ch-'a'+10;
    else
        return -1;
}

