//
//  Chromatics.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatics.hpp"

unsigned char Chromatic::getColorVecFromHex(string hex)
{
    if(hex.size() == 0) return 0;
    int nhigh = StringUtils::hex01(hex.at(0)) * 16;
    if(hex.size() == 1) return nhigh;
    int nlow  = StringUtils::hex01(hex.at(1));
    return nhigh + nlow;
}
