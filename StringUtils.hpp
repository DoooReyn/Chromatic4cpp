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

class StringUtils {
public:
    static std::string itoa(int value, int base);
    static const std::string fill02(std::string h);
    static const std::string fill03(int v);
    static const int hex01(char hex);
    static const std::string hex02(int v);
    static bool checkhex(std::string hex);
    static std::string touppercase(std::string &s);
    static std::string tolowercase(std::string &s);
};

#endif /* StringUtils_hpp */
