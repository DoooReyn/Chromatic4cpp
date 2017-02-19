//
//  ColorRGB.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatics.hpp"
#include "StringUtils.hpp"
#include <iostream>
#include <vector>

RGB::RGB()
: r(0), g(0), b(0)
{}

RGB::RGB(t_rgb _r, t_rgb _g, t_rgb _b)
: r(_r), g(_g), b(_b)
{}

RGB::RGB(const RGB& rgb)
: r(rgb.r)
, g(rgb.g)
, b(rgb.b)
{}

RGB::RGB(const RGBA& rgba)
: r(rgba.r)
, g(rgba.g)
, b(rgba.b)
{}

RGB::RGB(const CMYK& cmyk)
{
    fromCMYK(cmyk);
}

RGB::RGB(const HSL& hsl)
{
    fromHSL(hsl);
}

RGB::RGB(const HSV& hsv)
{
    fromHSV(hsv);
}

RGB::RGB(string hex)
{
    fromHEX(hex, true);
}

bool RGB::operator==(const RGB& other) const
{
    return (r == other.r && g == other.g && b == other.b);
}

bool RGB::operator!=(const RGB& other) const
{
    return !(*this == other);
}

bool RGB::operator==(const string hex) const
{
    return (*this == RGB(hex));
}

bool RGB::operator!=(const string hex) const
{
    return (*this != RGB(hex));
}

RGB RGB::operator+(const t_rgb cv)
{
    r = check((int)(r + cv));
    g = check((int)(g + cv));
    b = check((int)(b + cv));
    return *this;
}

RGB RGB::operator+(const RGB& other)
{
    r = check((int)(r + other.r));
    g = check((int)(g + other.g));
    b = check((int)(b + other.b));
    return *this;
}

RGB RGB::operator-(const t_rgb cv)
{
    r = check((int)(r - cv));
    g = check((int)(g - cv));
    b = check((int)(b - cv));
    return *this;
}

RGB RGB::operator-(const RGB& other)
{
    r = check((int)(r - other.r));
    g = check((int)(g - other.g));
    b = check((int)(b - other.b));
    return *this;
}

RGB RGB::operator*(const float scale)
{
    r = check((int)(r * scale));
    g = check((int)(g * scale));
    b = check((int)(b * scale));
    return *this;
}

RGB RGB::operator*(const RGB& other)
{
    r = check((int)(r * other.r));
    g = check((int)(g * other.g));
    b = check((int)(b * other.b));
    return *this;
}

RGB RGB::operator/(const float scale)
{
    r = check((int)(r / scale));
    g = check((int)(g / scale));
    b = check((int)(b / scale));
    return *this;
}

RGB RGB::operator/(const RGB& other)
{
    r = check((int)(r / other.r));
    g = check((int)(g / other.g));
    b = check((int)(b / other.b));
    return *this;
}

RGB RGB::operator%(const t_rgb cv)
{
    r = check((int)(r % cv));
    g = check((int)(g % cv));
    b = check((int)(b % cv));
    return *this;
}

RGB RGB::operator%(const float cv)
{
    r = check((int)fmod(r, cv));
    g = check((int)fmod(g, cv));
    b = check((int)fmod(b, cv));
    return *this;
}

RGB RGB::operator%(const RGB& other)
{
    r = check((int)(r % other.r));
    g = check((int)(g % other.g));
    b = check((int)(b % other.b));
    return *this;
}

RGB RGB::operator|(const RGB& other)
{
    r |= other.r;
    g |= other.g;
    b |= other.b;
    return *this;
}

RGB RGB::operator&(const RGB& other)
{
    r &= other.r;
    g &= other.g;
    b &= other.b;
    return *this = *this + other;
}

RGB RGB::opposite() {
    return *this = RGB(Chromatic::WHITE) - *this;
}

RGB RGB::dump()
{
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "RGB(%03d,%03d,%03d) HEX(%s)", r, g, b, toHEX().c_str());
    cout << txt << endl;
    return *this;
}

RGB RGB::random() {
    setrandomseed();
    r = randomAB(RGB::MIN, RGB::MAX);
    g = randomAB(RGB::MIN, RGB::MAX);
    b = randomAB(RGB::MIN, RGB::MAX);
    return *this = RGB(r,g,b);
}

RGB RGB::blend(const string hex)
{
    return *this | RGB(hex);
}

RGB RGB::blend(const string* hexArr, int size)
{
    int i = 0;
    while (size-- > 0) {
        *this | RGB(hexArr[i++]);
    }
    return *this;
}

RGB RGB::fromRGBA(const RGBA& rgba)
{
    return *this = RGB(rgba);
}

RGB RGB::fromCMYK(const CMYK& cmyk)
{
    return *this = CMYK(cmyk).toRGB();
}

RGB RGB::fromHSL(const HSL& hsl)
{
    return *this = HSL(hsl).toRGB();
}

RGB RGB::fromHSV(const HSV& hsv)
{
    return *this = HSV(hsv).toRGB();
}

RGB RGB::fromHEX(string hex, bool bCheckHex)
{
    clear();
    if(bCheckHex && !StringUtils::checkhex(hex)) return *this;
    
    unsigned long unHexSize = hex.size();
    unsigned long unSize = (unHexSize / 2) + (unHexSize % 2 == 0 ? 0 : 1);
    vector<t_rgb*> vecRGBA;
    vecRGBA.clear();
    vecRGBA.push_back(&r);
    vecRGBA.push_back(&g);
    vecRGBA.push_back(&b);
    for(unsigned long i=0,j=0; i<unSize && i<3; i++,j+=2) {
        int nhigh = StringUtils::hex01(hex.at(j)) * 16;
        int nlow  = (j+1) >= unHexSize ? 0 : StringUtils::hex01(hex.at(j+1));
        *vecRGBA.at(i) = t_rgb(nhigh + nlow);
    }
    return *this;
}

RGBA RGB::toRGBA()
{
    return RGBA(*this);
}

CMYK RGB::toCMYK()
{
    return CMYK(*this);
}

HSL RGB::toHSL()
{
    return HSL(*this);
}

HSV RGB::toHSV()
{
    return HSV(*this);
}

const string RGB::toHEX()
{
    char txt[8];
    memset(txt, 0 , sizeof(txt));
    sprintf(txt, "#%02X%02X%02X", r, g, b);
    return string(txt);
}

/**
 * Color constants
 */
const t_rgb RGB::MIN = 0;
const t_rgb RGB::MID = 127;
const t_rgb RGB::MAX = 255;
