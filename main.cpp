//
//  main.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/1/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "Chromatics/Chromatics.hpp"
#include "StringUtils.hpp"
using namespace Chromatic;
using namespace std;

void printInfo(const char * info) {
    cout << info << endl;
}

void RGB_TestCase() {
    printInfo("<# RGB TestCase Start");
    printInfo("=> RGB original data:");
    RGB case0 = RGB(REBECCAPURPLE);
    case0.dump();
    
    printInfo("=> single operator:");
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    
    printInfo("=> mixed  operator:");
    case0.clear(166);
    (case0+RGB(1,1,1)).dump();
    (case0-RGB(1,1,1)).dump();
    (case0*RGB(2,2,2)).dump();
    (case0/RGB(2,2,2)).dump();
    (case0%RGB(15,15,15)).dump();
    
    printInfo("=> use scale:");
    (case0.scale(10.8).dump());
    
    printInfo("=> use divide:");
    (case0.divide(2).dump());

    printInfo("=> from hex string(do check):");
    case0.fromHEX("80aF*U", true).dump();
    
    printInfo("=> from hex string(do not check):");
    case0.fromHEX("80aF*U", false).dump();
    
    printInfo("=> to hex string:");
    printInfo(case0.toHEX().c_str());
    
    printInfo("=> from/to RGBA:");
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    printInfo("=> clear with:");
    case0.clear(255).dump();
    
    printInfo("=> RED + LIME = YELLOW : ");
    (RGB(RED) + RGB(LIME)).dump();
    RGB(YELLOW).dump();
    
    printInfo("=> convertor: ");
    RGB rgb = RGB().fromHEX(ANTIQUEWHITE).dump();
    rgb.toRGBA().dump();
    rgb.toCMYK().dump();
    rgb.toHSL().dump();
    
    printInfo("!!! RGB TestCase End #>");
}


void RGBA_TestCase() {
    printInfo("<# RGBA TestCase Start");
    
    RGBA case0 = RGBA(INDIGO);
    
    printInfo("=> RGBA original data:");
    case0.dump();
    
    printInfo("=> single operator:");
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    
    printInfo("=> mixed  operator:");
    case0.clear(166);
    (case0+RGBA(1,1,1,1)).dump();
    (case0-RGBA(1,1,1,1)).dump();
    (case0*RGBA(2,2,2,2)).dump();
    (case0/RGBA(2,2,2,2)).dump();
    (case0%RGBA(15,15,15,15)).dump();
    
    printInfo("=> use scale:");
    (case0.scale(10.8).dump());
    
    printInfo("=> use divide:");
    (case0.divide(2).dump());
    
    printInfo("=> from hex string (do check):");
    case0.fromHEX("80aF*UE", true).dump();
    
    printInfo("=> from hex string (do not check):");
    case0.fromHEX("80aF*UE", false).dump();
    
    printInfo("=> to hex string:");
    printInfo(case0.toHEX().c_str());
    
    printInfo("=> from/to RGB:");
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    printInfo("=> clear with:");
    case0.clear(255).dump();
    
    printInfo("=> convertor: ");
    RGBA rgba = RGBA().fromHEX(ANTIQUEWHITE).dump();
    rgba.toRGB().dump();
    rgba.toCMYK().dump();
    rgba.toHSL().dump();
    
    printInfo("!!! RGBA TestCase End #>");
}

void CMYK_TestCase() {
    printInfo("<# CMYK TestCase Start ");
    
    CMYK cmyk = CMYK().fromHEX(ANTIQUEWHITE).dump();
    cmyk.toRGB().dump();
    cmyk.toHSL().dump();
    cmyk.toRGBA().dump();
    
    printInfo("!!! CMYK TestCase END #>");
}

void HSL_TestCase() {
    printInfo("<# HSL TestCase Start ");
    
    HSL hsl = HSL().fromHEX(ANTIQUEWHITE).dump();
    hsl.toRGB().dump();
    hsl.toCMYK().dump();
    hsl.toRGBA().dump();
    
    printInfo("!!! HSL TestCase Start #>");
}

void HSV_TestCase() {
    printInfo("<# HSV TestCase Start");
    HSV hsv = HSV().fromHEX(ANTIQUEWHITE).dump();
    hsv.toRGB().dump();
    hsv.toCMYK().dump();
    hsv.toRGBA().dump();
    printInfo("!!! HSV TestCase End #>");
}


void RGB_Blend_TestCase() {
    printInfo("<# RGB Blend TestCase Start");
    
    bool bBlendRedLime = RGB(RED).blend(LIME) == YELLOW;
    printInfo("Red blend Lime = Yellow ? ");
    bBlendRedLime ? cout << "True" : cout << "False";
    
    bBlendRedLime = RGB(RED).blend(LIME) + RGB(YELLOW).opposite() == WHITE;
    printInfo("Red blend Green = Yellow ?");
    bBlendRedLime ? cout << "True" : cout << "False";
    
    printInfo("!!! RGB Blend TestCase End #>");
}

void RGBA_Blend_TestCase() {
    printInfo("<# RGBA Blend TestCase Start");
    
    RGBA c1 = RGBA().fromAlphaF(235, 152, 80, 0.6f).dump();
    RGBA c2 = RGBA().fromAlphaF(234, 97, 124, 0.8f).dump();
    c1.blend(c2).dump();
    
    printInfo("RGBA Blend TestCase End #>");
}

void ColorRandom_TestCase() {
    printInfo("<# Color Random TestCase Start");
    
    RGB  c1 = RGB().random().dump();
    randomColor(c1).dump();
    RGBA c2 = RGBA().random().dump();
    randomColor(c2).dump();
    CMYK c3 = CMYK().random().dump();
    randomColor(c3).dump();
    HSL  c4 = HSL().random().dump();
    randomColor(c4).dump();
    HSV  c5 = HSV().random().dump();
    randomColor(c5).dump();
    
    printInfo("!!! Color Random TestCase End #>");
}

void CompareColor_TestCase() {
    printInfo("<# Compare Color With Mode Start");
    
    RGB  c1 = RGB(LIMEGREEN).dump();
    RGBA c2 = RGBA(LIMEGREEN).alpha(88).dump();
    CMYK c3 = CMYK(LIMEGREEN).dump();
    HSL  c4 = HSL(LIMEGREEN).dump();
    HSV  c5 = HSV(LIMEGREEN).dump();
    
    printInfo("[Color Value] LIMEGREEN: HEX(#32CD32)");
    printInfo("[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV ");
    printInfo("[CampareMode] loose :");
    cout << "c1 == c2 ? " << (equals(c1, c2) ? "True" : "False") << endl;
    cout << "c1 == c3 ? " << (equals(c1, c3) ? "True" : "False") << endl;
    cout << "c1 == c4 ? " << (equals(c1, c4) ? "True" : "False") << endl;
    cout << "c1 == c5 ? " << (equals(c1, c5) ? "True" : "False") << endl;
    cout << "c2 == c3 ? " << (equals(c2, c3) ? "True" : "False") << endl;
    cout << "c2 == c4 ? " << (equals(c2, c4) ? "True" : "False") << endl;
    cout << "c2 == c5 ? " << (equals(c2, c5) ? "True" : "False") << endl;
    cout << "c3 == c4 ? " << (equals(c3, c4) ? "True" : "False") << endl;
    cout << "c3 == c5 ? " << (equals(c3, c5) ? "True" : "False") << endl;
    cout << "c4 == c5 ? " << (equals(c4, c5) ? "True" : "False") << endl;
    
    printInfo("[Color Value] LIMEGREEN: HEX(#32CD32)");
    printInfo("[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV ");
    printInfo("[CampareMode] strict :");
    cout << "c1 == c2 ? " << (sequals(c1, c2) ? "True" : "False") << endl;
    cout << "c1 == c3 ? " << (sequals(c1, c3) ? "True" : "False") << endl;
    cout << "c1 == c4 ? " << (sequals(c1, c4) ? "True" : "False") << endl;
    cout << "c1 == c5 ? " << (sequals(c1, c5) ? "True" : "False") << endl;
    cout << "c2 == c3 ? " << (sequals(c2, c3) ? "True" : "False") << endl;
    cout << "c2 == c4 ? " << (sequals(c2, c4) ? "True" : "False") << endl;
    cout << "c2 == c5 ? " << (sequals(c2, c5) ? "True" : "False") << endl;
    cout << "c3 == c4 ? " << (sequals(c3, c4) ? "True" : "False") << endl;
    cout << "c3 == c5 ? " << (sequals(c3, c5) ? "True" : "False") << endl;
    cout << "c4 == c5 ? " << (sequals(c4, c5) ? "True" : "False") << endl;
    
    printInfo("!!! Compare Color With Mode End #>");
}

void PSBlendingMode_TestCase() {
    printInfo("===> PS 图层混合模型 <===");
    printInfo("基色:");
    RGB c1 = RGB("ff9999").dump();
    printInfo("混色:");
    RGB c2 = RGB("CAE90A").dump();
    printInfo("1.Darken:变暗");
    c1.blend4PSMode(c2, eDarken).dump();
    printInfo("2.Multiply:正片叠底");
    c1.blend4PSMode(c2, eMultiply).dump();
    printInfo("3.ColorBurn:颜色加深");
    c1.blend4PSMode(c2, eColorBurn).dump();
    printInfo("4.LinearBurn:线性加深");
    c1.blend4PSMode(c2, eLinearBurn).dump();
    printInfo("5.Lighten:变亮");
    c1.blend4PSMode(c2, eLighten).dump();
    printInfo("6.Lighten:滤色");
    c1.blend4PSMode(c2, eScreen).dump();
    printInfo("7.ColorDodge:颜色减淡");
    c1.blend4PSMode(c2, eColorDodge).dump();
    printInfo("8.LinearDodge:线性减淡");
    c1.blend4PSMode(c2, eLinearDodge).dump();
    printInfo("9.Overlay:叠加");
    c1.blend4PSMode(c2, eOverlay).dump();
    printInfo("10.SoftLight:柔光");
    c1.blend4PSMode(c2, eSoftLight).dump();
    printInfo("11.HardLight:强光");
    c1.blend4PSMode(c2, eHardLight).dump();
    printInfo("12.VividLight:亮光");
    c1.blend4PSMode(c2, eVividLight).dump();
    printInfo("13.LinearLight:线性光");
    c1.blend4PSMode(c2, eLinearLight).dump();
    printInfo("14.PinLight:点光");
    c1.blend4PSMode(c2, ePinLight).dump();
    printInfo("15.HardMix:实色混合");
    c1.blend4PSMode(c2, eHardMix).dump();
    printInfo("16.Difference:差值");
    c1.blend4PSMode(c2, eDifference).dump();
    printInfo("17.HardMix:排除");
    c1.blend4PSMode(c2, eExclusion).dump();
    printInfo("18.Substract:减去");
    c1.blend4PSMode(c2, eSubstract).dump();
    printInfo("===> PS 图层混合模型 <===");
}

int main() {
    RGB_TestCase();
    RGBA_TestCase();
    CMYK_TestCase();
    HSL_TestCase();
    HSV_TestCase();
    RGB_Blend_TestCase();
    RGBA_Blend_TestCase();
    ColorRandom_TestCase();
    CompareColor_TestCase();
    PSBlendingMode_TestCase();
}

