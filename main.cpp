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

void RGB_TestCase() {
    RGB case0 = RGB(Chromatic::REBECCAPURPLE);
    
    std::cout << "==================== RGB TestCase Start ===================" << std::endl;
    
    std::cout << "=> RGB original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    std::cout << std::endl << "=> mixed  operator:" << std::endl;
    case0.clear(166);
    (case0+RGB(1,1,1)).dump();
    (case0-RGB(1,1,1)).dump();
    (case0*RGB(2,2,2)).dump();
    (case0/RGB(2,2,2)).dump();
    (case0%RGB(15,15,15)).dump();
    
    std::cout << std::endl << "=> use scale:" << std::endl;
    (case0.scale(10.8).dump());
    
    std::cout << std::endl << "=> use divide:" << std::endl;
    (case0.divide(2).dump());

    std::cout << std::endl << "=> from hex string(do check):" << std::endl;
    case0.fromHEX("80aF*U", true).dump();
    
    std::cout << std::endl << "=> from hex string(do not check):" << std::endl;
    case0.fromHEX("80aF*U", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.toHEX() << std::endl;
    
    std::cout << std::endl << "=> from/to RGBA:" << std::endl;
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
    
    std::cout << std::endl << "=> RED + LIME = YELLOW : " << std::endl;
    (RGB(Chromatic::RED) + RGB(Chromatic::LIME)).dump();
    RGB(Chromatic::YELLOW).dump();
    
    std::cout << std::endl << "=> convertor: " << std::endl;
    RGB rgb = RGB().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    rgb.toRGBA().dump();
    rgb.toCMYK().dump();
    rgb.toHSL().dump();
    
    std::cout << "==================== RGB TestCase End =====================" << std::endl << std::endl;
}


void RGBA_TestCase() {
    std::cout << "=================== RGBA TestCase Start ===================" << std::endl;
    RGBA case0 = RGBA(Chromatic::INDIGO);
    
    std::cout << "=> RGBA original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    std::cout << std::endl << "=> mixed  operator:" << std::endl;
    case0.clear(166);
    (case0+RGBA(1,1,1,1)).dump();
    (case0-RGBA(1,1,1,1)).dump();
    (case0*RGBA(2,2,2,2)).dump();
    (case0/RGBA(2,2,2,2)).dump();
    (case0%RGBA(15,15,15,15)).dump();
    
    std::cout << std::endl << "=> use scale:" << std::endl;
    (case0.scale(10.8).dump());
    
    std::cout << std::endl << "=> use divide:" << std::endl;
    (case0.divide(2).dump());
    
    std::cout << std::endl << "=> from hex string (do check):" << std::endl;
    case0.fromHEX("80aF*UE", true).dump();
    
    std::cout << std::endl << "=> from hex string (do not check):" << std::endl;
    case0.fromHEX("80aF*UE", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.toHEX() << std::endl;
    
    std::cout << std::endl << "=> from/to RGB:" << std::endl;
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
    
    std::cout << std::endl << "=> convertor: " << std::endl;
    RGBA rgba = RGBA().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    rgba.toRGB().dump();
    rgba.toCMYK().dump();
    rgba.toHSL().dump();
    std::cout << "=================== RGBA TestCase End =====================" << std::endl << std::endl;
}

void CMYK_TestCase() {
    std::cout << "=================== CMYK TestCase Start ===================" << std::endl;
    CMYK cmyk = CMYK().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    cmyk.toRGB().dump();
    cmyk.toHSL().dump();
    cmyk.toRGBA().dump();
    std::cout << "=================== CMYK TestCase END =====================" << std::endl << std::endl;
}

void HSL_TestCase() {
    std::cout << "==================== HSL TestCase Start ===================" << std::endl;
    HSL hsl = HSL().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    hsl.toRGB().dump();
    hsl.toCMYK().dump();
    hsl.toRGBA().dump();
    std::cout << "==================== HSL TestCase Start ===================" << std::endl << std::endl;
}

void HSV_TestCase() {
    std::cout << "==================== HSL TestCase Start ===================" << std::endl;
    HSV hsv = HSV().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    hsv.toRGB().dump();
    hsv.toCMYK().dump();
    hsv.toRGBA().dump();
    std::cout << "==================== HSL TestCase End ===================" << std::endl << std::endl;
}


void RGB_Blend_TestCase() {
    std::cout << "==================== RGB Blend TestCase Start ===================" << std::endl;
    bool bBlendRedLime = RGB(RED).blend(LIME) == YELLOW;
    cout << "Red blend Lime = Yellow ? ";
    bBlendRedLime ? cout << "True" : cout << "False";
    cout << std::endl;
    
    bBlendRedLime = RGB(RED).blend(LIME) + RGB(YELLOW).opposite() == WHITE;
    cout << "Red blend Green = Yellow ? ";
    bBlendRedLime ? cout << "True" : cout << "False";
    cout << std::endl;
    std::cout << "==================== RGB Blend TestCase End   ===================" << std::endl << std::endl;
}

void RGBA_Blend_TestCase() {
    RGBA c1 = RGBA(235, 152, 80, 0.6f*255).dump();
    RGBA c2 = RGBA(234, 97, 124, 0.8f*255).dump();
//    RGBA c3 = c1.blend(c2).dump();
    c2.blend(c1).dump();
}

int main() {
//    RGB_TestCase();
//    RGBA_TestCase();
//    CMYK_TestCase();
//    HSL_TestCase();
//    HSV_TestCase();
//    RGB_Blend_TestCase();
    RGBA_Blend_TestCase();
}

