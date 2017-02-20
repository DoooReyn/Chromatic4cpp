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
    return a * b / 255;
}

/*
 * C = (B == 0 ? B : max(0, (255 - ((255 - A) << 8 ) / B)))
 */
t_rgb _getColorBurnCV(t_rgb a, t_rgb b) {
    return b == 0 ? b : MAX(0, (255 - ((255 - a) << 8 ) / b));
}

/*
 * C = (A + B < 255) ? 0 : (A + B - 255)
 */
t_rgb _getLinearBurnCV(t_rgb a, t_rgb b) {
    return (a + b < 255) ? 0 : (a + b - 255);
}

/*
 * 基色 <= 128 : 结果色 = 混合色 * 基色 / 128;
 * 基色 >= 128 : 结果色 = 255 - (255 - 混合色) * (255 - 基色) / 128;
 */
t_rgb _getOverLayCV(t_rgb a, t_rgb b) {
    if(a < RGB::MIDF)
        return a * b / RGB::MIDF + .5f;
    else
        return RGB::MAX - (RGB::MAX - b) * (RGB::MAX - a) / RGB::MIDF + .5f;
}

/* PS图层混合模型 : 开始 */
// Below blending modes are from PhotoShop
//    RGB blendPS4Darken(const RGB& rgb);     //变暗
//    RGB blendPS4Multiply(const RGB& rgb);   //正片叠底
//    RGB blendPS4ColorBurn(const RGB& rgb);  //颜色加深
//    RGB blendPS4LinearBurn(const RGB& rgb); //线性加深
//    RGB blendPS4Darker(const RGB& rgb);     //深色
//    RGB blendPS4Lighten(const RGB& rgb);    //变亮
//    RGB blendPS4Screen(const RGB& rgb);     //滤色
//    RGB blendPS4ColorDodge(const RGB& rgb); //颜色减淡
//    RGB blendPS4LinearDodge(const RGB& rgb);//线性减淡
//    RGB blendPS4Lighter(const RGB& rgb);    //浅色
//    RGB blendPS4Overlay(const RGB& rgb);    //叠加
//    RGB blendPS4SoftLight(const RGB& rgb);  //柔光
//    RGB blendPS4HardLight(const RGB& rgb);  //强光
//    RGB blendPS4VividLight(const RGB& rgb); //亮光
//    RGB blendPS4LinearLight(const RGB& rgb);//线性光
//    RGB blendPS4PinLight(const RGB& rgb);   //点光
//    RGB blendPS4HardMix(const RGB& rgb);    //实色混合
//    RGB blendPS4Diffenrence(const RGB& rgb);//差值
//    RGB blendPS4Exclusion(const RGB& rgb);  //排除
//    RGB blendPS4Subtract(const RGB& rgb);   //减去
//    RGB blendPS4Divide(const RGB& rgb);     //划分
//    RGB blendPS4Hue(const RGB& rgb);        //色相
//    RGB blendPS4Saturation(const RGB& rgb); //饱和度
//    RGB blendPS4Color(const RGB& rgb);      //颜色
//    RGB blendPS4Luminosity(const RGB& rgb); //明度
//    RGB blendPS4Dissolve(const RGB& rgb);   //溶解（跟图像有关，暂时不在计划内）
/* PS图层混合模型 : 结束 */

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
        case eOverlay:
            return _getOverLayCV;
        case eColorBurn:
            return _getColorBurnCV;
        case eLinearBurn:
            return _getLinearBurnCV;
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
