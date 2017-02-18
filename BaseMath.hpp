//
//  BaseMath.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef BaseMath_hpp
#define BaseMath_hpp

#define MIN(a,b) (a > b ? b : a)
#define MAX(a,b) (a > b ? a : b)

#define max03f(f1, f2, f3) MAX(MAX(f1, f2), f3)
#define min03f(f1, f2, f3) MIN(MIN(f1, f2), f3)

typedef unsigned char  t_rgb;
typedef unsigned short d_rgb;

typedef unsigned char  t_rgba;
typedef unsigned short d_rgba;

typedef float t_cmyk;
typedef float d_cmyk;

typedef unsigned short t_hsl_hue;
typedef float t_hsl_saturation;
typedef float t_hsl_lightness;

typedef t_hsl_hue t_hsv_hue;
typedef t_hsl_saturation t_hsv_saturation;
typedef t_hsl_lightness t_hsv_value;

#endif /* BaseMath_hpp */
