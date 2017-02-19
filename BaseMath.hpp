//
//  BaseMath.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef BaseMath_hpp
#define BaseMath_hpp

#include <math.h>

#define MIN(a,b) (a > b ? b : a)
#define MAX(a,b) (a > b ? a : b)

#define max03f(f1, f2, f3) MAX(MAX(f1, f2), f3)
#define min03f(f1, f2, f3) MIN(MIN(f1, f2), f3)

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

#endif /* BaseMath_hpp */
