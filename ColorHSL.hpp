//
//  ColorHSL.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef ColorHSL_hpp
#define ColorHSL_hpp

#include "BaseMath.hpp"
#include <iostream>
#include <math.h>

struct RGB;
struct RGBA;
struct CMYK;

struct HSL {
    /* data */
    t_hsl_hue h;
    t_hsl_saturation s;
    t_hsl_lightness l;
    
    /* constructor */
    HSL();
    HSL(t_hsl_hue _h, t_hsl_saturation _s, t_hsl_lightness _l);
    
    /* operator */
    bool operator == (const HSL& other) const;
    bool operator != (const HSL& other) const;
    HSL  operator +  (const float cv);
    HSL  operator +  (const HSL& other);
    HSL  operator -  (const float cv);
    HSL  operator -  (const HSL& other);
    HSL  operator *  (const float scale);
    HSL  operator *  (const HSL& other);
    HSL  operator /  (const float scale);
    HSL  operator /  (const HSL& other);
    HSL  operator %  (const float c);
    HSL  operator %  (const HSL& other);
    
    bool equals(const HSL& other) {
        return (*this == other);
    }
    bool nequals(const HSL& other) {
        return (*this != other);
    }
    HSL add(const float cv) {
        return *this + cv;
    }
    HSL add(const HSL& other) {
        return *this + other;
    }
    HSL add(t_hsl_hue _h, t_hsl_saturation _s, t_hsl_lightness _l) {
        return *this + HSL(_h, _s, _l);
    }
    HSL sub(const float cv) {
        return *this - cv;
    }
    HSL sub(const HSL& other) {
        return *this - other;
    }
    HSL sub(t_hsl_hue _h, t_hsl_saturation _s, t_hsl_lightness _l) {
        return *this - HSL(_h, _s, _l);
    }
    HSL scale(float s) {
        return (*this) * s;
    }
    HSL scale(const HSL& other) {
        return *this * other;
    }
    HSL scale(float _h, float _s, float _l) {
        h = checkHue(h * _h);
        s = checkSaturation(s * _s);
        l = checkLightness(l * _l);
        return *this;
    }
    HSL divide(float d) {
        return (*this) / d;
    }
    HSL divide(const HSL& other) {
        return *this / other;
    }
    HSL divide(float _h, float _s, float _l) {
        h = checkHue(h / _h);
        s = checkSaturation(s / _s);
        l = checkLightness(l / _l);
        return *this;
    }
    HSL mod(float d) {
        return (*this) % d;
    }
    HSL mod(const HSL& other) {
        return *this % other;
    }
    HSL mod(float _h, float _s, float _l) {
        h = checkHue(fmod(h, _h));
        s = checkSaturation(fmod(s, _s));
        l = checkLightness(fmod(l, _l));
        return *this;
    }
    
    
    /* method */
    t_hsl_hue checkHue(t_hsl_hue cv) {
        if(cv < HSL::MIN_HUE) return HSL::MIN_HUE;
        if(cv > HSL::MAX_HUE) return HSL::MAX_HUE;
        return cv;
    }
    
    t_hsl_saturation checkSaturation(t_hsl_saturation cv) {
        if(cv < HSL::MIN_SATURATION) cv = HSL::MIN_SATURATION;
        if(cv > HSL::MAX_SATURATION) cv = HSL::MAX_SATURATION;
        return cv;
    }
    
    t_hsl_lightness checkLightness(t_hsl_lightness cv) {
        if(cv < HSL::MIN_LIGHTNESS) cv = HSL::MIN_LIGHTNESS;
        if(cv > HSL::MAX_LIGHTNESS) cv = HSL::MAX_LIGHTNESS;
        return cv;
    }
    
    HSL clear() {
        h = HSL::MIN_HUE;
        s = HSL::MIN_SATURATION;
        l = HSL::MIN_LIGHTNESS;
        return *this;
    }
    
    HSL dump();
    
    
    // getter/setter
    t_hsl_hue hue() {
        return h;
    }
    HSL hue(t_hsl_hue _h) {
        h = checkHue(_h);
        return *this;
    }
    t_hsl_saturation saturation() {
        return s;
    }
    HSL saturation(t_hsl_saturation _s) {
        s = checkSaturation(_s);
        return *this;
    }
    t_hsl_lightness lightness() {
        return l;
    }
    HSL lightness(t_hsl_lightness _l) {
        l = checkLightness(_l);
        return *this;
    }
    
    /* convertor */
    RGB toRGB();
    HSL fromRGB(const RGB& rgb);
    RGBA toRGBA();
    HSL fromRGBA(const RGBA& rgba);
    std::string tohex();
    HSL fromhex(std::string hex);
    CMYK toCMYK();
    HSL fromCMYK(const CMYK& cmyk);
    
    
    /* constants */
    static const t_hsl_hue MIN_HUE;
    static const t_hsl_hue MID_HUE;
    static const t_hsl_hue MAX_HUE;
    static const t_hsl_saturation MIN_SATURATION;
    static const t_hsl_saturation MID_SATURATION;
    static const t_hsl_saturation MAX_SATURATION;
    static const t_hsl_lightness MIN_LIGHTNESS;
    static const t_hsl_lightness MID_LIGHTNESS;
    static const t_hsl_lightness MAX_LIGHTNESS;
};


#endif /* ColorHSL_hpp */
