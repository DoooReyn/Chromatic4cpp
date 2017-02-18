//
//  main.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/1/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include <iostream>
#include "Chromatics/Chromatics.hpp"

void RGB_TestCase() {
    RGB case0 = RGB(Chromatic::REBECCAPURPLE);
    
    std::cout << "=> RGB original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15).dump();
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

    std::cout << std::endl << "=> from hex string(do check, this case will fail for invalid hex string):" << std::endl;
    case0.fromhex("80aF*U", true).dump();
    
    std::cout << std::endl << "=> from hex string(don't do check, will always succeed):" << std::endl;
    case0.fromhex("80aF*U", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.tohex() << std::endl;
    
    std::cout << std::endl << "=> from/to RGBA:" << std::endl;
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
}

void RGBA_TestCase() {
    RGBA case0 = RGBA(Chromatic::INDIGO);
    
    std::cout << "=> RGBA original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15).dump();
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
    
    std::cout << std::endl << "=> from hex string (do check, this case will fail for invalid hex string):" << std::endl;
    case0.fromhex("80aF*UE", true).dump();
    
    std::cout << std::endl << "=> from hex string (don't do check, will always succeed):" << std::endl;
    case0.fromhex("80aF*UE", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.tohex() << std::endl;
    
    std::cout << std::endl << "=> from/to RGB:" << std::endl;
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
}

void CMYK_TestCase() {
    RGBA rgba = RGBA(Chromatic::BURLYWOOD);
    CMYK case0 = CMYK(rgba);
    rgba.fromCMYK(case0).dump();
    case0.dump();
}

int main() {
//    RGB_TestCase();
//    RGBA_TestCase();
    CMYK_TestCase();
}

