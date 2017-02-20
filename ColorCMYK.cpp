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

CMYK::CMYK(const CMYK& cmyk)
: c(cmyk.c), m(cmyk.m), y(cmyk.y), k(cmyk.k)
{}

CMYK::CMYK(const RGB& rgb)
{
    fromRGB(rgb);
}

CMYK::CMYK(const RGBA& rgba) {
    fromRGBA(rgba);
}

CMYK::CMYK(const HSL& hsl) {
    fromHSL(hsl);
}

CMYK::CMYK(const HSV& hsv) {
    fromHSV(hsv);
}

CMYK::CMYK(string hex) {
    fromHEX(hex);
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
    char txt[48];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "CMYK(%.03f,%.03f,%.03f,%.03f) HEX(%s)", c, m, y, k, toHEX().c_str());
    cout << txt << endl;
    return *this;
}

CMYK CMYK::random() {
    setrandomseed();
    c = random01();
    m = random01();
    y = random01();
    k = random01();
    return *this;
}

CMYK CMYK::fromRGB(const RGB& rgb) {
    t_cmyk c0 = RGB::MAX - rgb.r;
    t_cmyk m0 = RGB::MAX - rgb.g;
    t_cmyk y0 = RGB::MAX - rgb.b;
    k = min03(c0, m0, y0);
    c = (c0-k) * 1.f / ((RGB::MAX-k) == 0 ? 1 : (RGB::MAX-k));
    m = (m0-k) * 1.f / ((RGB::MAX-k) == 0 ? 1 : (RGB::MAX-k));
    y = (y0-k) * 1.f / ((RGB::MAX-k) == 0 ? 1 : (RGB::MAX-k));
    k = k * 1.f / RGB::MAX;
    return *this;
}

CMYK CMYK::fromRGBA(const RGBA& rgba) {
    return *this = RGB(rgba).toCMYK();
}

CMYK CMYK::fromHSL(const HSL& hsl) {
    return *this = RGB(hsl).toCMYK();
}

CMYK CMYK::fromHEX(string hex) {
    return *this = RGB(hex).toCMYK();
}

CMYK CMYK::fromHSV(const HSV& hsv) {
    return *this = RGB(hsv).toCMYK();
}

RGB CMYK::toRGB() {
    t_rgb r = RGB::MAX * (1.0f - c) * (1.0f - k);
    t_rgb g = RGB::MAX * (1.0f - m) * (1.0f - k);
    t_rgb b = RGB::MAX * (1.0f - y) * (1.0f - k);
    return RGB(r, g, b);
}

RGBA CMYK::toRGBA() {
    return toRGB().toRGBA();
}

HSL CMYK::toHSL() {
    return toRGB().toHSL();
}

HSV CMYK::toHSV() {
    return toRGB().toHSV();
}

const string CMYK::toHEX() {
    return toRGB().toHEX();
}


/* constants */
const t_cmyk CMYK::MIN = 0.000f;
const t_cmyk CMYK::MID = 0.500f;
const t_cmyk CMYK::MAX = 1.000f;
