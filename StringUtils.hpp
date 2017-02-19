//
//  StringUtils.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/17.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef StringUtils_hpp
#define StringUtils_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <clocale>
#include <cctype>
#include <algorithm>
using namespace std;


class StringUtils {
public:
    static string itoa(int value, int base);
    static const string fill02(string h);
    static const string fill03(int v);
    static const int hex01(char hex);
    static const string hex02(int v);
    static bool checkhex(string hex);
    static string touppercase(string &s);
    static string tolowercase(string &s);
    static int hexStr2int(string hex);
    static int hexChar2Int(char ch);
};

#endif /* StringUtils_hpp */
