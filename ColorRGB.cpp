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

RGB::RGB(std::string hex)
{
    fromhex(hex, false);
}

bool RGB::operator==(const RGB& other) const
{
    return (r == other.r && g == other.g && b == other.b);
}

bool RGB::operator!=(const RGB& other) const
{
    return !(*this == other);
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

RGB RGB::operator%(const RGB& other)
{
    r = check((int)(r % other.r));
    g = check((int)(g % other.g));
    b = check((int)(b % other.b));
    return *this;
}

RGB RGB::dump()
{
    char txt[128];
    memset(txt, 0, sizeof(txt));
    CMYK cmyk = toCMYK();
    sprintf(txt, "RGB(%03d,%03d,%03d) HEX(%s) CMYK(%.03f,%.03f,%.03f,%.03f)",
            r, g, b,
            tohex().c_str(),
            cmyk.c, cmyk.m, cmyk.y, cmyk.k);
    std::cout << txt << std::endl;
    return *this;
}

RGBA RGB::toRGBA()
{
    return RGBA(r,g,b,RGB::MAX);
}

RGB RGB::fromRGBA(const RGBA& rgba)
{
    return RGB(rgba);
}

const std::string RGB::tohex()
{
    std::string s_rgb("");
    s_rgb.append(StringUtils::hex02(red  ()));
    s_rgb.append(StringUtils::hex02(green()));
    s_rgb.append(StringUtils::hex02(blue ()));
    return s_rgb;
}

RGB RGB::fromhex(std::string hex, bool bCheckHex)
{
    clear();
    if(bCheckHex && !StringUtils::checkhex(hex)) return *this;
    
    unsigned long unHexSize = hex.size();
    unsigned long unSize = (unHexSize / 2) + (unHexSize % 2 == 0 ? 0 : 1);
    std::vector<t_rgb*> vecRGBA;
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

CMYK RGB::toCMYK()
{
    return CMYK(*this);
}

RGB RGB::fromCMYK(const CMYK& cmyk)
{
    r = 255 * (1.0f - cmyk.c) * (1.0f - cmyk.k);
    g = 255 * (1.0f - cmyk.m) * (1.0f - cmyk.k);
    b = 255 * (1.0f - cmyk.y) * (1.0f - cmyk.k);
    return *this;
}

/**
 * Color constants
 */
const t_rgb RGB::MIN = 0;
const t_rgb RGB::MID = 127;
const t_rgb RGB::MAX = 255;
