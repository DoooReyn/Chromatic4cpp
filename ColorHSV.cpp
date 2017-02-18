//
//  ColorHSV.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatics.hpp"
#include <iostream>

HSV::HSV()
: h(HSV::MIN_HUE)
, s(HSV::MIN_SATURATION)
, v(HSV::MIN_VALUE)
{}

HSV::HSV(t_hsv_hue _h, t_hsv_saturation _s, t_hsv_value _v)
: h(_h), s(_s), v(_v)
{}

HSV::HSV(const HSV& hsv)
: h(hsv.h), s(hsv.s), v(hsv.v)
{}

HSV::HSV(const RGB& rgb)
{
    fromRGB(rgb);
}

HSV::HSV(const RGBA& rgba)
{
    fromRGBA(rgba);
}

HSV::HSV(const CMYK& cmyk)
{
    fromCMYK(cmyk);
}

HSV::HSV(const HSL& hsl)
{
    fromHSL(hsl);
}

HSV::HSV(const std::string hex)
{
    fromHEX(hex);
}

bool HSV::operator == (const HSV& other) const {
    return (h == other.h && s == other.s && v == other.v);
}

bool HSV::operator != (const HSV& other) const {
    return !(h == other.h && s == other.s && v == other.v);
}

HSV HSV::operator + (const float cv) {
    h = checkHue(h + cv);
    s = checkSaturation(s + cv);
    v = checkValue(v + cv);
    return *this;
}

HSV HSV::operator + (const HSV& other) {
    h = checkHue(h + other.h);
    s = checkSaturation(s + other.s);
    v = checkValue(v + other.v);
    return *this;
}

HSV HSV::operator - (const float cv) {
    h = checkHue(h - (int)cv);
    s = checkSaturation(s - cv);
    v = checkValue(v - cv);
    return *this;
}

HSV HSV::operator - (const HSV& other) {
    h = checkHue(h - other.h);
    s = checkSaturation(s - other.s);
    v = checkValue(v - other.v);
    return *this;
}

HSV HSV::operator * (const float scale)  {
    h = checkHue(h * scale);
    s = checkSaturation(s * scale);
    v = checkValue(v * scale);
    return *this;
}

HSV HSV::operator * (const HSV& other)  {
    h = checkHue(h * other.h);
    s = checkSaturation(s * other.s);
    v = checkValue(v * other.v);
    return *this;
}

HSV HSV::operator / (const float scale)  {
    h = checkHue(h / scale);
    s = checkSaturation(s / scale);
    v = checkValue(v / scale);
    return *this;
}

HSV HSV::operator / (const HSV& other) {
    h = checkHue(h / other.h);
    s = checkSaturation(s / other.s);
    v = checkValue(v / other.v);
    return *this;
}

HSV HSV::operator % (const float c) {
    return *this;
}

HSV HSV::operator % (const HSV& other) {
    h = checkHue(h % other.h);
    s = checkSaturation(fmod(s, other.s));
    v = checkValue(fmod(v, other.v));
    return *this;
}

HSV HSV::dump() {
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "HSV(%03d,%.03f,%.03f) HEX(%s)", h, s, v, toHEX().c_str());
    std::cout << txt << std::endl;
    return *this;
}

HSV HSV::fromRGB(const RGB& rgb) {
    float r = rgb.r * 1.f / RGB::MAX;
    float g = rgb.g * 1.f / RGB::MAX;
    float b = rgb.b * 1.f / RGB::MAX;
    float cmax = max03f(r, g, b);
    float cmin = min03f(r, g, b);
    float delta = cmax - cmin;
    v = cmax;
    if(cmax == cmin) {
        h = 0;
    } else if (cmax == r && g >= b) {
        h = 60 * ((g - b) / delta + 0);
    } else if (cmax == r && g < b) {
        h = 60 * ((g - b) / delta + 6);
    } else if (cmax == g) {
        h = 60 * ((b - r) / delta + 2);
    } else if (cmax == b) {
        h = 60 * ((r - g) / delta + 4);
    }
    if(cmax == 0) {
        s = 0;
    } else {
        s = 1 - cmin / cmax;
    }
    return *this;
}

HSV HSV::fromRGBA(const RGBA& rgba) {
    return *this = RGB(rgba).toHSV();
    return *this;
}

HSV HSV::fromCMYK(const CMYK& cmyk) {
    return *this = RGB(cmyk).toHSV();
    return *this;
}

HSV HSV::fromHSL(const HSL& hsl) {
    return *this = RGB(hsl).toHSV();
    return *this;
}

HSV HSV::fromHEX(std::string hex) {
    return *this = RGB(hex).toHSV();
}

RGB HSV::toRGB() {
    float r = .0f, g = .0f, b = .0f;
    float c = v * s;
    float x = c * (1 - fabs(fmod(h / 60.f, 2) - 1));
    float m = v - c;
    if(h < 60) {
        r = c; g = x; b = 0;
    } else if (h < 120) {
        r = x; g = c; b = 0;
    } else if (h < 180) {
        r = 0; g = c; b = x;
    } else if (h < 240) {
        r = 0; g = x; b = c;
    } else if ( h < 300) {
        r = x; g = 0; b = c;
    } else if ( h < 360) {
        r = c; g = 0; b = x;
    }
    r = (r + m) * RGB::MAX + .5f;
    g = (g + m) * RGB::MAX + .5f;
    b = (b + m) * RGB::MAX + .5f;
    return RGB(r, g, b);
}

RGBA HSV::toRGBA() {
    return toRGB().toRGBA();
}

CMYK HSV::toCMYK() {
    return toRGB().toCMYK();
}

HSL HSV::toHSL() {
    return toRGB().toHSL();
}

std::string HSV::toHEX() {
    return toRGB().toHEX();
}


/* constants */
const t_hsv_hue HSV::MIN_HUE = 0;
const t_hsv_hue HSV::MID_HUE = 180;
const t_hsv_hue HSV::MAX_HUE = 359;
const t_hsv_saturation HSV::MIN_SATURATION = 0.000f;
const t_hsv_saturation HSV::MID_SATURATION = 0.500f;
const t_hsv_saturation HSV::MAX_SATURATION = 1.000f;
const t_hsv_value HSV::MIN_VALUE = 0.000f;
const t_hsv_value HSV::MID_VALUE = 0.500f;
const t_hsv_value HSV::MAX_VALUE = 1.000f;
