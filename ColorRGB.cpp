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
using namespace Chromatic;

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

RGB RGB::operator =  (const string hex)
{
    return fromHEX(hex);
}

RGB RGB::operator =  (const char* hex)
{
    return fromHEX(string(hex));
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
    t_rgb _r = r | other.r;
    t_rgb _g = g | other.r;
    t_rgb _b = b | other.r;
    return RGB(_r, _g, _b);
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

RGB RGB::difference(const RGB& rgb) {
    t_rgb _r = abs(r - rgb.r);
    t_rgb _g = abs(g - rgb.g);
    t_rgb _b = abs(b - rgb.b);
    return RGB(_r, _g, _b);
}

RGB RGB::red(string cv) {
    r = getColorVecFromHex(cv);
    return *this;
}
RGB RGB::green(string cv) {
    g = getColorVecFromHex(cv);
    return *this;
}
RGB RGB::blue(string cv) {
    b = getColorVecFromHex(cv);
    return *this;
}

RGB RGB::clear(string hex) {
    return *this = RGB(hex);
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

RGB RGB::blend(const RGB& rgb) {
    return *this | rgb;
}

RGB RGB::blend(const string hex)
{
    return *this | RGB(hex);
}

/*
 * C = MIN(A,B)
 */
t_rgb _getDarkenCV(t_rgb a, t_rgb b) {
    return MIN(a, b);
}

/*
 * C = (A * B) / 255
 */
t_rgb _getMultiplyCV(t_rgb a, t_rgb b) {
    return a * b * 1.f / RGB::MAX;
}

/*
 * C = (B == 0 ? B : max(0, (255 - ((255 - A) << 8 ) / B)))
 */
t_rgb _getColorBurnCV(t_rgb a, t_rgb b) {
    return b == 0 ? b : MAX(0, (RGB::MAX - ((RGB::MAX - a) << 8 ) / b));
}

/*
 * C = (A + B < 255) ? 0 : (A + B - 255)
 */
t_rgb _getLinearBurnCV(t_rgb a, t_rgb b) {
    return (a + b < RGB::MAX) ? 0 : (a + b - RGB::MAX);
}

/*
 * 基色 <= 128 : 结果色 = 混合色 * 基色 / 128;
 * 基色 >= 128 : 结果色 = 255 - (255 - 混合色) * (255 - 基色) / 128;
 */
t_rgb _getOverLayCV(t_rgb a, t_rgb b) {
    if(a < RGB::MIDF)
        return a * b * 1.f / RGB::MIDF + .5f;
    else
        return RGB::MAX - (RGB::MAX - b) * (RGB::MAX - a) / RGB::MIDF + .5f;
}

/*
 * 变亮：C = (B > A) ? B : A
 */
t_rgb _getLightenCV(t_rgb a, t_rgb b) {
    return b > a ? b : a;
}

/*
 * C = 255 - (((255 - A) * (255 - B)) >> 8))
 */
t_rgb _getScreenCV(t_rgb a, t_rgb b)
{
    return RGB::MAX - (((RGB::MAX - a) * (RGB::MAX - b)) >> 8);
}


/*
 * C = (B == 255) ? B : min(255, ((A << 8 ) / (255 - B)))
 */
t_rgb _getColorDodgeCV(t_rgb a, t_rgb b)
{
    return (b == RGB::MAX) ? b : MIN(RGB::MAX, ((a << 8 ) / (RGB::MAX - b)));
}

/*
 * C = min(255, (A + B))
 */
t_rgb _getLinearDodgeCV(t_rgb a, t_rgb b)
{
    return MIN(RGB::MAX, a + b);
}

/*
 * C = B < 128 ? (2 * (( A >> 1) + 64)) * (B / 255) : (255 - ( 2 * (255 - ( (A >> 1) + 64 ) ) * ( 255 - B ) / 255 ));
 */
t_rgb _getSoftLightCV(t_rgb a, t_rgb b)
{
    return b < RGB::MID ? (2 * (( a >> 1) + 64)) * (b * 1.f / RGB::MAX) : (RGB::MAX - ( 2 * (RGB::MAX - ( (a >> 1) + 64 ) ) * ( RGB::MAX - b ) * 1.f / RGB::MAX ));
}

/*
 * Overlay(B,A) (A < 128) ? (2 * A * B / 255) : (255 - 2 * (255 - A) * (255 - B) / 255)
 */
t_rgb _getHardLightCV(t_rgb a, t_rgb b)
{
    return (a < RGB::MAX) ? (2.f * a * b / RGB::MAX) : (RGB::MAX - 2.f * (RGB::MAX - a) * (RGB::MAX - b) / RGB::MAX);
}


/*
 * Overlay(B,A) (A < 128) ? (2 * A * B / 255) : (255 - 2 * (255 - A) * (255 - B) / 255)
 */
t_rgb _getVividLight(t_rgb a, t_rgb b) {
    return b < RGB::MID ? (b == 0 ? 2 * b : MAX(0, (RGB::MAX - ((RGB::MAX - a) << 8 ) * 1.f / (2 * b)))) : ((2 * (b - RGB::MID)) == RGB::MAX ? (2 * (b - RGB::MID)) : MIN(RGB::MAX, ((a << 8 ) * 1.f / (RGB::MAX - (2 * (b - RGB::MID)) )))) ;
}

/*
 * C = min(255, max(0, ($B + 2 * $A) - 1))
 */
t_rgb _getLinearLightCV(t_rgb a, t_rgb b) {
    return MIN(RGB::MAX, MAX( 0, ((b + 2 * a) - RGB::MAX)));
}

/*
 * C = max(0, max(2 * B - 255, min(B, 2*A)))
 */
t_rgb _getPinLightCV(t_rgb a, t_rgb b) {
    return MAX(0, MAX(2 * a - RGB::MAX, MAX(b, 2 * a)));
}

/*
 * C = (VividLight(A,B) < 128) ? 0 : 255
 */
t_rgb _getHardMixCV(t_rgb a, t_rgb b) {
    return _getVividLight(a, b) < RGB::MID ? RGB::MIN : RGB::MAX;
}

/*
 * C = abs(A - B)
 */
t_rgb _getDifferenceCV(t_rgb a, t_rgb b) {
    return abs(a - b);
}

/*
 * C = A + B - 2 * A * B / 255
 */
t_rgb _getExclusionCV(t_rgb a, t_rgb b) {
    return a + b - 2 * a * b * 1.f / RGB::MAX;
}

//结果色 = 基色 - 混合色
t_rgb _getSubstractCV(t_rgb a, t_rgb b) {
    return a * 1.f / b * RGB::MAX;
}


typedef t_rgb (*GETCVFUNC)(t_rgb, t_rgb);
typedef RGB (*BLENDFUNC)(const RGB&, const RGB&, GETCVFUNC);

/*
 * 获取图层混合模式的计算方法
 * mode : 图层混合模式
 */
GETCVFUNC _getColorVecFunc(E_PS_BLEND_MODE mode) {
    switch (mode) {
        case eDarken:
            return _getDarkenCV;
        case eMultiply:
            return _getMultiplyCV;
        case eColorBurn:
            return _getColorBurnCV;
        case eLinearBurn:
            return _getLinearBurnCV;
        case eLighten:
            return _getLightenCV;
        case eScreen:
            return _getScreenCV;
        case eColorDodge:
            return _getColorDodgeCV;
        case eLinearDodge:
            return _getLinearDodgeCV;
        case eOverlay:
            return _getOverLayCV;
        case eSoftLight:
            return _getSoftLightCV;
        case eHardLight:
            return _getHardLightCV;
        case eLinearLight:
            return _getLinearLightCV;
        case ePinLight:
            return _getPinLightCV;
        case eHardMix:
            return _getHardMixCV;
        case eDifference:
            return _getDifferenceCV;
        case eExclusion:
            return _getExclusionCV;
        case eSubstract:
            return _getSubstractCV;
        case eNormal:
        default:
            NULL;
    }
    return NULL;
}

/*
 * 使用何种图层混合模式混合两种色值
 *    c1 : RGB图层1
 *    c2 : RGB图层2
 * cFunc : 图层混合计算方法(函数指针)
 */
RGB _blendWithMode(const RGB& c1, const RGB& c2, GETCVFUNC cFunc) {
    if(cFunc == NULL) return RGB(c2);
    return RGB(cFunc(c1.r, c2.r), cFunc(c1.g, c2.g), cFunc(c1.b, c2.b));
}

/*
 * 使用PS图层混合模式进行两个图层的混合计算
 *   c2 : RGB图层
 * mode : 混合模式
 */
RGB RGB::blend4PSMode(const RGB& c2, E_PS_BLEND_MODE mode) {
    if(*this == c2) return RGB(c2);
    GETCVFUNC cFunc = _getColorVecFunc(mode);
    return _blendWithMode(*this, c2, cFunc);
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
const float RGB::MIDF = 128.f;
