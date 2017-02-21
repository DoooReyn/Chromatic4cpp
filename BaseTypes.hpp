//
//  BaseTypes.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/19.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef BaseTypes_hpp
#define BaseTypes_hpp

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

typedef enum {
    eNormal = 0,
    eDarken,
    eMultiply,
    eColorBurn,
    eLinearBurn,
    eLighten,
    eScreen,
    eColorDodge,
    eLinearDodge,
    eOverlay,
    eSoftLight,
    eHardLight,
    eVividLight,
    eLinearLight,
    ePinLight,
    eHardMix,
    eDifference,
    eExclusion,
    eSubstract,
    eDivide,
    eHSLHue,
    eHSLSaturation,
    eHSLColor,
    eHSLLuminosity,
    Dissolve,
} E_PS_BLEND_MODE;

#endif /* BaseTypes_hpp */
