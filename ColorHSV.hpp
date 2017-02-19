//
//  ColorHSV.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef ColorHSV_hpp
#define ColorHSV_hpp

#include <iostream>
#include "BaseMath.hpp"
#include "BaseTypes.hpp"
using namespace std;

struct RGB;
struct RGBA;
struct CMYK;
struct HSL;

struct HSV {
    /* data */
    t_hsv_hue h;
    t_hsv_saturation s;
    t_hsv_value v;
    
    /* constructor */
    HSV();
    HSV(t_hsv_hue _h, t_hsv_saturation _s, t_hsv_value _v);
    HSV(const HSV& hsv);
    HSV(const RGB& rgb);
    HSV(const RGBA& rgba);
    HSV(const CMYK& cmyk);
    HSV(const HSL& hsl);
    HSV(const string hex);
    
    
    /* operator */
    bool operator == (const HSV& other) const;
    bool operator != (const HSV& other) const;
    HSV  operator +  (const float cv);
    HSV  operator +  (const HSV& other);
    HSV  operator -  (const float cv);
    HSV  operator -  (const HSV& other);
    HSV  operator *  (const float scale);
    HSV  operator *  (const HSV& other);
    HSV  operator /  (const float scale);
    HSV  operator /  (const HSV& other);
    HSV  operator %  (const float c);
    HSV  operator %  (const HSV& other);
    
    bool equals(const HSL& other) {
        return (*this == other);
    }
    bool nequals(const HSL& other) {
        return (*this != other);
    }
    HSV add(const float cv) {
        return *this + cv;
    }
    HSV add(const HSV& other) {
        return *this + other;
    }
    HSV add(t_hsv_hue _h, t_hsv_saturation _s, t_hsv_value _v) {
        return *this + HSV(_h, _s, _v);
    }
    HSV sub(const float cv) {
        return *this - cv;
    }
    HSV sub(const HSV& other) {
        return *this - other;
    }
    HSV sub(t_hsv_hue _h, t_hsv_saturation _s, t_hsv_value _v) {
        return *this - HSV(_h, _s, _v);
    }
    HSV scale(float s) {
        return (*this) * s;
    }
    HSV scale(const HSL& other) {
        return *this * other;
    }
    HSV scale(float _h, float _s, float _v) {
        h = checkHue(h * _h);
        s = checkSaturation(s * _s);
        v = checkValue(v * _v);
        return *this;
    }
    HSV divide(float d) {
        return (*this) / d;
    }
    HSV divide(const HSL& other) {
        return *this / other;
    }
    HSV divide(float _h, float _s, float _v) {
        h = checkHue(h / _h);
        s = checkSaturation(s / _s);
        v = checkValue(v / _v);
        return *this;
    }
    HSV mod(float d) {
        return (*this) % d;
    }
    HSV mod(const HSV& other) {
        return *this % other;
    }
    HSV mod(float _h, float _s, float _v) {
        h = checkHue(fmod(h, _h));
        s = checkSaturation(fmod(s, _s));
        v = checkValue(fmod(v, _v));
        return *this;
    }

    
    /* method */
    t_hsv_hue checkHue(t_hsv_hue cv) {
        if(cv < HSV::MIN_HUE) return HSV::MIN_HUE;
        if(cv > HSV::MAX_HUE) return HSV::MAX_HUE;
        return cv;
    }
    
    t_hsv_saturation checkSaturation(t_hsv_saturation cv) {
        if(cv < HSV::MIN_SATURATION) cv = HSV::MIN_SATURATION;
        if(cv > HSV::MAX_SATURATION) cv = HSV::MAX_SATURATION;
        return cv;
    }
    
    t_hsv_value checkValue(t_hsv_value cv) {
        if(cv < HSV::MIN_VALUE) cv = HSV::MIN_VALUE;
        if(cv > HSV::MAX_VALUE) cv = HSV::MAX_VALUE;
        return cv;
    }
    
    HSV clear() {
        h = HSV::MIN_HUE;
        s = HSV::MIN_SATURATION;
        v = HSV::MIN_VALUE;
        return *this;
    }
    
    HSV dump();
    HSV random();
    
    
    // getter/setter
    t_hsv_hue hue() {
        return h;
    }
    HSV hue(t_hsv_hue _h) {
        h = checkHue(_h);
        return *this;
    }
    t_hsv_saturation saturation() {
        return s;
    }
    HSV saturation(t_hsv_saturation _s) {
        s = checkSaturation(_s);
        return *this;
    }
    t_hsv_value value() {
        return v;
    }
    HSV value(t_hsv_value _v) {
        v = checkValue(_v);
        return *this;
    }
    
    
    /* convertor */
    HSV fromRGB(const RGB& rgb);
    HSV fromRGBA(const RGBA& rgba);
    HSV fromCMYK(const CMYK& cmyk);
    HSV fromHSL(const HSL& hsl);
    HSV fromHEX(string hex);
    RGB  toRGB();
    RGBA toRGBA();
    CMYK toCMYK();
    HSL  toHSL();
    string toHEX();
    
    
    /* constants */
    static const t_hsv_hue MIN_HUE;
    static const t_hsv_hue MID_HUE;
    static const t_hsv_hue MAX_HUE;
    static const t_hsv_saturation MIN_SATURATION;
    static const t_hsv_saturation MID_SATURATION;
    static const t_hsv_saturation MAX_SATURATION;
    static const t_hsv_value MIN_VALUE;
    static const t_hsv_value MID_VALUE;
    static const t_hsv_value MAX_VALUE;
};


#endif /* ColorHSV_hpp */
