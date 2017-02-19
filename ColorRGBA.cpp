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
using namespace Chromatic;

RGBA::RGBA()
: r(0), g(0), b(0), a(0)
{}

RGBA::RGBA(t_rgba _r, t_rgba _g, t_rgba _b, t_rgba _a)
: r(_r), g(_g), b(_b), a(_a)
{}

RGBA RGBA::fromAlphaF(t_rgba _r, t_rgba _g, t_rgba _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = check(_a * RGBA::MAX);
    return *this;
}

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
, a(RGBA::MAX)
{}

RGBA::RGBA(const CMYK& cmyk)
{
    fromCMYK(cmyk);
}

RGBA::RGBA(const HSL&  hsl)
{
    fromHSL(hsl);
}

RGBA::RGBA(const HSV&  hsv)
{
    fromHSV(hsv);
}

RGBA::RGBA(string hex)
{
    fromHEX(hex, false);
}

bool RGBA::operator==(const RGBA& other) const
{
    return (r == other.r && g == other.g && b == other.b && a == other.a);
}

bool RGBA::operator!=(const RGBA& other) const
{
    return !(*this == other);
}

RGBA RGBA::operator|(const RGBA& other) {
    return blend(other);
}

RGBA RGBA::operator|(const string hex) {
    return blend(RGBA(hex));
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

RGBA RGBA::operator%(const t_rgba cv)
{
    r = check((int)(r % cv));
    g = check((int)(g % cv));
    b = check((int)(b % cv));
    a = check((int)(a % cv));
    return *this;
}

RGBA RGBA::operator%(const float cv)
{
    r = check((int)fmod(r, cv));
    g = check((int)fmod(g, cv));
    b = check((int)fmod(b, cv));
    a = check((int)fmod(a, cv));
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
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "RGBA(%03d,%03d,%03d,%03d) HEX(%s)", r, g, b, a, toHEX().c_str());
    cout << txt << endl;
    return *this;
}

RGBA RGBA::random() {
    setrandomseed();
    r = randomAB(RGB::MIN, RGB::MAX);
    g = randomAB(RGB::MIN, RGB::MAX);
    b = randomAB(RGB::MIN, RGB::MAX);
    a = randomAB(RGB::MIN, RGB::MAX);
    return *this = RGBA(r,g,b,a);
}

RGBA RGBA::opposite() {
    return *this = RGBA(WHITE) - *this;
}

RGBA RGBA::blend(const string hex) {
    return blend(RGBA(hex));
}

RGBA RGBA::blend(const RGBA& rgba) {
    float a1 = a * 1.f / RGBA::MAX;
    float a2 = rgba.a * 1.f / RGBA::MAX;
    float ar = a1 + a2 - a1 * a2;
    
    r = (r * a1 + rgba.r * a2 - r * a1 * a2) / ar + .5f;
    g = (g * a1 + rgba.g * a2 - g * a1 * a2) / ar + .5f;
    b = (b * a1 + rgba.b * a2 - b * a1 * a2) / ar + .5f;
    a = ar * 255;
    
    return *this;
}

RGBA RGBA::fromRGB(const RGB& rgb) {
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
    a = RGBA::MAX;
    return *this;
}

RGBA RGBA::fromCMYK(const CMYK& cmyk)
{
    return *this = RGB(cmyk).toRGBA();
}

RGBA RGBA::fromHSL(const HSL &hsl)
{
    return *this = RGB(hsl).toRGBA();
}

RGBA RGBA::fromHSV(const HSV &hsv)
{
    return *this = RGB(hsv).toRGBA();
}

RGBA RGBA::fromHEX(string hex, bool bCheckHex) {
    clear();
    if(bCheckHex && !StringUtils::checkhex(hex)) return *this;
    
    unsigned long unHexSize = hex.size();
    unsigned long unSize = (unHexSize / 2) + (unHexSize % 2 == 0 ? 0 : 1);
    vector<t_rgba*> vecRGBA;
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

CMYK RGBA::toCMYK()
{
    return RGB(*this).toCMYK();
}

HSL RGBA::toHSL()
{
    return RGB(*this).toHSL();
}

HSV RGBA::toHSV()
{
    return RGB(*this).toHSV();
}

string RGBA::toHEX()
{
    std::string s_rgba("");
    s_rgba.append(StringUtils::hex02(red  ()));
    s_rgba.append(StringUtils::hex02(green()));
    s_rgba.append(StringUtils::hex02(blue ()));
    s_rgba.append(StringUtils::hex02(alpha()));
    return s_rgba;
}


/**
 * Color constants
 */
const t_rgba RGBA::MIN = 0;
const t_rgba RGBA::MID = 127;
const t_rgba RGBA::MAX = 255;
