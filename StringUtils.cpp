//
//  StringUtils.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/17.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "StringUtils.hpp"

std::string StringUtils::itoa(int value, int base) {
    const char digitMap[] = "0123456789abcdef";
    std::string buf;
    if (base == 0 || base > 16) {
        // Error: may add more trace/log output here
        return buf;
    }
    
    // Take care of negative int:
    std::string sign;
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

const std::string StringUtils::fill02(std::string h) {
    if(h.size() < 2)
        h.insert(0, "0");
    return h;
}

const std::string StringUtils::fill03(int v) {
    std::string ret( itoa(v, 10) );
    if(v < 10) {
        ret.insert(0, "00");
    } else if( v < 100) {
        ret.insert(0, "0");
    }
    return ret;
}

bool StringUtils::checkhex(std::string hex) {
    bool isvalid = true;
    std::string hexdict = "0123456789ABCDEF";
    hex = touppercase(hex);
    for(unsigned long i=0; i<hex.size(); i++) {
        isvalid = hexdict.find(hex.at(i)) == std::string::npos;
        if(isvalid) return false;
    }
    return true;
}

std::string StringUtils::touppercase(std::string& s)
{
    std::string ret(s.size(), char());
    for(unsigned int i = 0; i < s.size(); ++i)
        ret[i] = (s[i] <= 'z' && s[i] >= 'a') ? s[i]-('a'-'A') : s[i];
    return ret;
}

std::string StringUtils::tolowercase(std::string& s)
{
    std::string ret(s.size(), char());
    for(unsigned int i = 0; i < s.size(); ++i)
        ret[i] = (s[i] <= 'Z' && s[i] >= 'A') ? s[i]+('a'-'A') : s[i];
    return ret;
}

const int StringUtils::hex01(char hex) {
    int ret = 0;
    if(hex >= 'A' && hex <= 'F') ret = (int)(hex-'A')+10;
    if(hex >= 'a' && hex <= 'f') ret = (int)(hex-'a')+10;
    if(hex >= '0' && hex <= '9') ret = (int)(hex-'0')+0;
    return ret;
}

const std::string StringUtils::hex02(int v) {
    return fill02(itoa(v, 16));
}
