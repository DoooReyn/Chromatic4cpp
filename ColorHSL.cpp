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

HSL::HSL(t_hsl_hue _h, t_hsl_saturation _s, t_hsl_lightness _l)
: h(checkHue(_h))
, s(checkSaturation(_s))
, l(checkLightness(_l))
{}

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
    char txt[128];
    memset(txt, 0, sizeof(txt));
    RGB rgb = toRGB();
    CMYK cmyk = toCMYK();
    sprintf(txt, "HSL(%03d,%.03f,%.03f) RGB(%03d,%03d,%03d) HEX(%s) CMYK(%.03f,%.03f,%.03f,%.03f)",
            h, s, l,
            rgb.r, rgb.g, rgb.b,
            tohex().c_str(),
            cmyk.c, cmyk.m, cmyk.y, cmyk.k
            );
    std::cout << txt << std::endl;
    return *this;
}

float hue2rgb(float p, float q, float t) {
    if(t < 0) t += 1;
    if(t > 0) t -= 1;
    if(t < 1.f / 6) return p + (q - p) * 6 * t;
    if(t < 1.f / 2) return q;
    if(t < 2.f / 3) return p + (q - p) * ( 2.f / 3 - t) * 6;
    return p;
}

RGB HSL::toRGB() {
    float r = 0.f, g = 0.f, b = 0.f;
    float c = (1 - fabs(2 * l - 1)) * s;
    float x = c * (1 - abs((h / 60) % 2 - 1));
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
        r = c; g= 0; b = x;
    }
    r = (r + m) * RGB::MAX + .5f;
    g = (g + m) * RGB::MAX + .5f;
    b = (b + m) * RGB::MAX + .5f;
    return RGB(r, g, b);
}

float max03f(float f1, float f2, float f3) {
    return MAX(MAX(f1, f2), f3);
}
float min03f(float f1, float f2, float f3) {
    return MIN(MIN(f1, f2), f3);
}

HSL HSL::fromRGB(const RGB& rgb) {
    float r = rgb.r * 1.f / RGB::MAX;
    float g = rgb.g * 1.f / RGB::MAX;
    float b = rgb.b * 1.f / RGB::MAX;
    float cmax = max03f(r, g, b);
    float cmin = min03f(r, g, b);
    float delta = cmax - cmin;
    l = (cmax + cmin) / 2;
    if(cmax == cmin) {
        h = s = 0;
    } else if (cmax == r) {
        h = 60 * fmod((g - b) / delta, 6);
    } else if (cmax == g) {
        h = 60 * ((b - r) / delta + 2);
    } else if (cmax == b) {
        h = 60 * ((r - g) / delta + 4);
    }
    if(cmax != cmin) {
        s = 1 - delta / (1-fabs(2*l-1));
    }
    
    return *this;
}

RGBA HSL::toRGBA() {
    return toRGB().toRGBA();
}

HSL HSL::fromRGBA(const RGBA& rgba) {
    return fromRGB(RGB(rgba));
}

std::string HSL::tohex() {
    return toRGB().tohex();
}

HSL HSL::fromhex(std::string hex) {
    return fromRGB(RGB(hex));
}

CMYK HSL::toCMYK() {
    return toRGB().toCMYK();
}

HSL HSL::fromCMYK(const CMYK& cmyk) {
    return fromRGB(RGB(cmyk));
}


const t_hsl_hue HSL::MIN_HUE = 0;
const t_hsl_hue HSL::MID_HUE = 180;
const t_hsl_hue HSL::MAX_HUE = 359;
const t_hsl_saturation HSL::MIN_SATURATION = 0.000f;
const t_hsl_saturation HSL::MID_SATURATION = 0.500f;
const t_hsl_saturation HSL::MAX_SATURATION = 1.000f;
const t_hsl_lightness HSL::MIN_LIGHTNESS = 0.000f;
const t_hsl_lightness HSL::MID_LIGHTNESS = 0.500f;
const t_hsl_lightness HSL::MAX_LIGHTNESS = 1.000f;
