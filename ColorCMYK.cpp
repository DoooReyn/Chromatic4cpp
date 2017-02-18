//
//  ColorCMYK.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatics.hpp"
#include <iostream>
#include <math.h>

CMYK::CMYK()
: c(0), m(0), y(0), k(0)
{}

CMYK::CMYK(t_cmyk _c, t_cmyk _m, t_cmyk _y, t_cmyk _k)
: c(check(_c)), m(check(_m)), y(check(_y)), k(check(_k))
{}

t_cmyk min03(t_cmyk v1, t_cmyk v2, t_cmyk v3)
{
    t_cmyk tmp = MIN(v1,v2);
    tmp = MIN(tmp, v3);
    return tmp;
}

CMYK::CMYK(const RGB& rgb)
{
    t_cmyk c0 = 255 - rgb.r;
    t_cmyk m0 = 255 - rgb.g;
    t_cmyk y0 = 255 - rgb.b;
    k = min03(c0, m0, y0);
    c = (c0-k) * 1.f / (255-k);
    m = (m0-k) * 1.f / (255-k);
    y = (y0-k) * 1.f / (255-k);
    k = k * 1.f / 255;
}

CMYK::CMYK(const RGBA& rgba) {
    *this = CMYK(RGB(rgba));
}

CMYK::CMYK(std::string hex) {
    *this = CMYK(RGB(hex));
}

bool CMYK::operator == (const CMYK& other) const {
    return (c == other.c && m == other.m && y == other.y && k == other.k);
}

bool CMYK::operator != (const CMYK& other) const {
    return !(c == other.c && m == other.m && y == other.y && k == other.k);
}

CMYK CMYK::operator + (const t_cmyk cv){
    c = check(c + cv);
    m = check(m + cv);
    y = check(y + cv);
    k = check(k + cv);
    return *this;
}

CMYK CMYK::operator + (const CMYK& other) {
    c = check(c + other.c);
    m = check(m + other.m);
    y = check(y + other.y);
    k = check(k + other.k);
    return *this;
}

CMYK CMYK::operator - (const t_cmyk cv) {
    c = check(c - cv);
    m = check(m - cv);
    y = check(y - cv);
    k = check(k - cv);
    return *this;
}

CMYK CMYK::operator - (const CMYK& other) {
    c = check(c - other.c);
    m = check(m - other.m);
    y = check(y - other.y);
    k = check(k - other.k);
    return *this;
}

CMYK CMYK::operator * (const t_cmyk scale) {
    c = check(c * scale);
    m = check(m * scale);
    y = check(y * scale);
    k = check(k * scale);
    return *this;
}

CMYK CMYK::operator * (const CMYK& other) {
    c = check(c * other.c);
    m = check(m * other.m);
    y = check(y * other.y);
    k = check(k * other.k);
    return *this;
}

CMYK CMYK::operator / (const t_cmyk scale) {
    c = check(c / scale);
    m = check(m / scale);
    y = check(y / scale);
    k = check(k / scale);
    return *this;
}

CMYK CMYK::operator / (const CMYK& other) {
    c = check(c / other.c);
    m = check(m / other.m);
    y = check(y / other.y);
    k = check(k / other.k);
    return *this;
}

CMYK CMYK::operator % (const t_cmyk cv) {
    c = check(fmod(c, cv));
    m = check(fmod(m, cv));
    y = check(fmod(y, cv));
    k = check(fmod(k, cv));
    
    return *this;
}

CMYK CMYK::operator % (const CMYK& other) {
    c = check(fmod(c, other.c));
    m = check(fmod(m, other.m));
    y = check(fmod(y, other.y));
    k = check(fmod(k, other.k));
    return *this;
}

CMYK CMYK::dump() {
    char txt[128];
    memset(txt, 0, sizeof(txt));
    RGB rgb = toRGB();
    sprintf(txt, "CMYK(%.03f,%.03f,%.03f,%.03f) RGB(%03d,%03d,%03d) HEX(%s)",
            c, m, y, k,
            rgb.r, rgb.g, rgb.b,
            rgb.tohex().c_str());
    std::cout << txt << std::endl;
    return *this;
}

CMYK CMYK::fromRGB(const RGB& other) {
    return *this = CMYK(other);
}

RGB CMYK::toRGB() {
    t_rgb r = 255 * (1.0f - c) * (1.0f - k);
    t_rgb g = 255 * (1.0f - m) * (1.0f - k);
    t_rgb b = 255 * (1.0f - y) * (1.0f - k);
    return RGB(r, g, b);
}

CMYK CMYK::fromRGBA(const RGBA& other) {
    return *this = CMYK(other);
}

RGBA CMYK::toRGBA() {
    return RGBA(*this);
}

const std::string CMYK::tohex() {
    return toRGB().tohex();
}

CMYK CMYK::fromhex(std::string hex) {
    return *this = CMYK(hex);
}

const t_cmyk CMYK::MIN = 0.000f;
const t_cmyk CMYK::MID = 50.000f;
const t_cmyk CMYK::MAX = 100.000f;

