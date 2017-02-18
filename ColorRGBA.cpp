//
//  ColorRGBA.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/16.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatics.hpp"
#include "StringUtils.hpp"
#include <iostream>
#include <vector>

RGBA::RGBA()
: r(0), g(0), b(0), a(0)
{}

RGBA::RGBA(t_rgba _r, t_rgba _g, t_rgba _b, t_rgba _a)
: r(_r), g(_g), b(_b), a(_a)
{}

RGBA::RGBA(const RGBA& rgba)
: r(rgba.r)
, g(rgba.g)
, b(rgba.b)
, a(rgba.a)
{}

RGBA::RGBA(const RGB& other)
: r(other.r)
, g(other.g)
, b(other.b)
{}

RGBA::RGBA(const CMYK& cmyk)
{
    fromCMYK(cmyk);
}

RGBA::RGBA(std::string hex)
{
    fromhex(hex, false);
}

bool RGBA::operator==(const RGBA& other) const
{
    return (r == other.r && g == other.g && b == other.b && a == other.a);
}

bool RGBA::operator!=(const RGBA& other) const
{
    return !(*this == other);
}

RGBA RGBA::operator+(const RGBA& other)
{
    r = check((int)(r + other.r));
    g = check((int)(g + other.g));
    b = check((int)(b + other.b));
    a = check((int)(a + other.a));
    return *this;
}

RGBA RGBA::operator+(const t_rgba cv)
{
    r = check((int)(r + cv));
    g = check((int)(g + cv));
    b = check((int)(b + cv));
    a = check((int)(a + cv));
    return *this;
}

RGBA RGBA::operator-(const RGBA& other)
{
    r = check((int)(r - other.r));
    g = check((int)(g - other.g));
    b = check((int)(b - other.b));
    a = check((int)(a - other.a));
    return *this;
}

RGBA RGBA::operator-(const t_rgba cv)
{
    r = check((int)(r - cv));
    g = check((int)(g - cv));
    b = check((int)(b - cv));
    a = check((int)(a - cv));
    return *this;
}

RGBA RGBA::operator*(const float scale)
{
    r = check((int)(r * scale));
    g = check((int)(g * scale));
    b = check((int)(b * scale));
    a = check((int)(a * scale));
    return *this;
}

RGBA RGBA::operator*(const RGBA& other)
{
    r = check((int)(r * other.r));
    g = check((int)(g * other.g));
    b = check((int)(b * other.b));
    a = check((int)(a * other.a));
    return *this;
}

RGBA RGBA::operator/(const float scale)
{
    r = check((int)(r / scale));
    g = check((int)(g / scale));
    b = check((int)(b / scale));
    a = check((int)(a / scale));
    return *this;
}

RGBA RGBA::operator/(const RGBA& other)
{
    r = check((int)(r / other.r));
    g = check((int)(g / other.g));
    b = check((int)(b / other.b));
    a = check((int)(a / other.a));
    return *this;
}

RGBA RGBA::operator%(const t_rgba c)
{
    r = check((int)(r % c));
    g = check((int)(g % c));
    b = check((int)(b % c));
    a = check((int)(a % c));
    return *this;
}

RGBA RGBA::operator%(const RGBA& other)
{
    r = check((int)(r % other.r));
    g = check((int)(g % other.g));
    b = check((int)(b % other.b));
    a = check((int)(a % other.a));
    return *this;
}

RGBA RGBA::dump()
{
    char txt[128];
    memset(txt, 0, sizeof(txt));
    CMYK cmyk = toCMYK();
    sprintf(txt, "RGBA(%03d,%03d,%03d,%03d) HEX(%s) CMYK(%.03f,%.03f,%.03f,%.03f)",
            r, g, b, a,
            tohex().c_str(),
            cmyk.c, cmyk.m, cmyk.y, cmyk.k);
    std::cout << txt << std::endl;
    return *this;
}

std::string RGBA::tohex()
{
    std::string s_rgba("");
    s_rgba.append(StringUtils::hex02(red  ()));
    s_rgba.append(StringUtils::hex02(green()));
    s_rgba.append(StringUtils::hex02(blue ()));
    s_rgba.append(StringUtils::hex02(alpha()));
    return s_rgba;
}

RGBA RGBA::fromhex(std::string hex, bool bCheckHex) {
    clear();
    if(bCheckHex && !StringUtils::checkhex(hex)) return *this;
    
    unsigned long unHexSize = hex.size();
    unsigned long unSize = (unHexSize / 2) + (unHexSize % 2 == 0 ? 0 : 1);
    std::vector<t_rgba*> vecRGBA;
    vecRGBA.clear();
    vecRGBA.push_back(&r);
    vecRGBA.push_back(&g);
    vecRGBA.push_back(&b);
    vecRGBA.push_back(&a);
    for(unsigned long i=0,j=0; i<unSize && i<4; i++,j+=2) {
        int nhigh = StringUtils::hex01(hex.at(j)) * 16;
        int nlow  = (j+1) >= unHexSize ? 0 : StringUtils::hex01(hex.at(j+1));
        *vecRGBA.at(i) = t_rgba(nhigh + nlow);
    }
    return *this;
}

RGB RGBA::toRGB() {
    return RGB(r, g, b);
}

RGBA RGBA::fromRGB(const RGB& rgb) {
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
    a = RGBA::MAX;
    return *this;
}

CMYK RGBA::toCMYK()
{
    return CMYK(*this);
}

RGBA RGBA::fromCMYK(const CMYK& cmyk)
{
    r = 255 * (1.0f - cmyk.c) * (1.0f - cmyk.k);
    g = 255 * (1.0f - cmyk.m) * (1.0f - cmyk.k);
    b = 255 * (1.0f - cmyk.y) * (1.0f - cmyk.k);
    a = 255;
    return *this;
}


/**
 * Color constants
 */
const t_rgba RGBA::MIN = 0;
const t_rgba RGBA::MID = 127;
const t_rgba RGBA::MAX = 255;
