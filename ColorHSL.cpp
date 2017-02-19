//
//  ColorHSL.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatics.hpp"
#include <math.h>

HSL::HSL()
: h(HSL::MIN_HUE)
, s(HSL::MIN_SATURATION)
, l(HSL::MIN_LIGHTNESS)
{}

HSL::HSL(const HSL& other)
: h(other.h)
, s(other.s)
, l(other.l)
{}

HSL::HSL(t_hsl_hue _h, t_hsl_saturation _s, t_hsl_lightness _l)
: h(checkHue(_h))
, s(checkSaturation(_s))
, l(checkLightness(_l))
{}

HSL::HSL(const RGB& rgb)
{
    fromRGB(rgb);
}

HSL::HSL(const RGBA& rgba)
{
    fromRGBA(rgba);
}

HSL::HSL(const CMYK& cmyk)
{
    fromCMYK(cmyk);
}

HSL::HSL(const HSV& hsv)
{
    fromHSV(hsv);
}

HSL::HSL(const string hex)
{
    fromHEX(hex);
}

bool HSL::operator == (const HSL& other) const {
    return (h == other.h && s == other.s && l == other.l);
}

bool HSL::operator != (const HSL& other) const {
    return !(h == other.h && s == other.s && l == other.l);
}

HSL HSL::operator + (const float cv) {
    h = checkHue(h + cv);
    s = checkSaturation(s + cv);
    l = checkLightness(l + cv);
    return *this;
}

HSL HSL::operator + (const HSL& other) {
    h = checkHue(h + other.h);
    s = checkSaturation(s + other.s);
    l = checkLightness(l + other.l);
    return *this;
}

HSL HSL::operator - (const float cv) {
    h = checkHue(h - (int)cv);
    s = checkSaturation(s - cv);
    l = checkLightness(l - cv);
    return *this;
}

HSL HSL::operator - (const HSL& other) {
    h = checkHue(h - other.h);
    s = checkSaturation(s - other.s);
    l = checkLightness(l - other.l);
    return *this;
}

HSL HSL::operator * (const float scale)  {
    h = checkHue(h * scale);
    s = checkSaturation(s * scale);
    l = checkLightness(l * scale);
   return *this;
}

HSL HSL::operator * (const HSL& other)  {
    h = checkHue(h * other.h);
    s = checkSaturation(s * other.s);
    l = checkLightness(l * other.l);
   return *this;
}

HSL HSL::operator / (const float scale)  {
    h = checkHue(h / scale);
    s = checkSaturation(s / scale);
    l = checkLightness(l / scale);
    return *this;
}

HSL HSL::operator / (const HSL& other) {
    h = checkHue(h / other.h);
    s = checkSaturation(s / other.s);
    l = checkLightness(l / other.l);
   return *this;
}

HSL HSL::operator % (const float c) {
   return *this;
}

HSL HSL::operator % (const HSL& other) {
    h = checkHue(h % other.h);
    s = checkSaturation(fmod(s, other.s));
    l = checkLightness(fmod(l, other.l));
    return *this;
}

HSL HSL::dump() {
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "HSL(%03d,%.03f,%.03f) HEX(%s)", h, s, l, toHEX().c_str());
    std::cout << txt << std::endl;
    return *this;
}

HSL HSL::random() {
    setrandomseed();
    h = randomAB(HSL::MIN_HUE, HSL::MAX_HUE);
    s = random01();
    l = random01();
    return *this;
}

HSL HSL::fromRGB(const RGB& rgb) {
    float r = rgb.r * 1.f / RGB::MAX;
    float g = rgb.g * 1.f / RGB::MAX;
    float b = rgb.b * 1.f / RGB::MAX;
    float cmax = max03f(r, g, b);
    float cmin = min03f(r, g, b);
    float delta = cmax - cmin;
    l = (cmax + cmin) / 2.f;
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
    if(l == 0 || cmax == cmin) {
        s = 0;
    } else if ( 0 < l && l <= 0.5f) {
        s = delta / 2 / l;
    } else if ( l > 0.5f ) {
        s = delta / 2 / (1-l);
    }
    
    return *this;
}

HSL HSL::fromRGBA(const RGBA& rgba) {
    return *this = RGB(rgba).toHSL();
}

HSL HSL::fromCMYK(const CMYK& cmyk) {
    return *this = RGB(cmyk).toHSL();
}

HSL HSL::fromHSV(const HSV &hsv) {
    return *this = RGB(hsv).toHSL();
}

HSL HSL::fromHEX(string hex) {
    return *this = RGB(hex).toHSL();
}

RGB HSL::toRGB() {
    float r = 0.f, g = 0.f, b = 0.f;
    float c = (1 - fabs(2 * l - 1)) * s;
    float x = c * (1 - fabs(fmod(h / 60.f, 2) - 1));
    float m = l - c / 2.f;
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

RGBA HSL::toRGBA() {
    return toRGB().toRGBA();
}

CMYK HSL::toCMYK() {
    return toRGB().toCMYK();
}

HSV HSL::toHSV() {
    return toRGB().toHSV();
}

string HSL::toHEX() {
    return toRGB().toHEX();
}


/* constants */
const t_hsl_hue HSL::MIN_HUE = 0;
const t_hsl_hue HSL::MID_HUE = 180;
const t_hsl_hue HSL::MAX_HUE = 359;
const t_hsl_saturation HSL::MIN_SATURATION = 0.000f;
const t_hsl_saturation HSL::MID_SATURATION = 0.500f;
const t_hsl_saturation HSL::MAX_SATURATION = 1.000f;
const t_hsl_lightness HSL::MIN_LIGHTNESS = 0.000f;
const t_hsl_lightness HSL::MID_LIGHTNESS = 0.500f;
const t_hsl_lightness HSL::MAX_LIGHTNESS = 1.000f;
