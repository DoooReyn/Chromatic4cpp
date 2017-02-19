//
//  ColorRGB.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef ColorRGB_hpp
#define ColorRGB_hpp

#include "BaseMath.hpp"
#include "BaseTypes.hpp"
using namespace std;

struct RGBA;
struct CMYK;
struct HSL;
struct HSV;

struct RGB
{
public:
    /* data */
    t_rgb r;
    t_rgb g;
    t_rgb b;
    
    
    /* constructor */
    RGB();
    RGB(t_rgb _r, t_rgb _g, t_rgb _b);
    RGB(const RGB & rgb);
    RGB(const RGBA& rgba);
    RGB(const CMYK& cmyk);
    RGB(const HSL&  hsl);
    RGB(const HSV&  hsv);
    RGB(string hex);
    
    
    /* operator */
    bool operator == (const RGB& other) const;
    bool operator != (const RGB& other) const;
    bool operator == (const string hex) const;
    bool operator != (const string hex) const;
    RGB  operator |  (const RGB& other);
    RGB  operator &  (const RGB& other);
    RGB  operator +  (const t_rgb cv);
    RGB  operator +  (const RGB& other);
    RGB  operator -  (const t_rgb cv);
    RGB  operator -  (const RGB& other);
    RGB  operator *  (const float scale);
    RGB  operator *  (const RGB& other);
    RGB  operator /  (const float scale);
    RGB  operator /  (const RGB& other);
    RGB  operator %  (const t_rgb c);
    RGB  operator %  (const float c);
    RGB  operator %  (const RGB& other);
    
    bool equals(const RGB& other) {
        return (*this == other);
    }
    bool equals(const string hex) {
        return (*this == RGB(hex));
    }
    bool nequals(const RGBA& other) {
        return (*this != other);
    }
    bool nequals(const string hex) {
        return (*this != RGB(hex));
    }
    RGB add(t_rgb cv){
        return *this + cv;
    }
    RGB add(const RGB& other){
        return *this + other;
    }
    RGB sub(t_rgb cv) {
        return *this - cv;
    }
    RGB sub(const RGB& other) {
        return *this - other;
    }
    RGB scale(float s) {
        return (*this) * s;
    }
    RGB scale(const RGB& other) {
        return *this * other;
    }
    RGB divide(float d) {
        return (*this) / d;
    }
    RGB divide(const RGB& other) {
        return *this / other;
    }
    RGB mod(float d) {
        return (*this) % d;
    }
    RGB mod(const RGB& other) {
        return *this % other;
    }
    RGB opposite();
    
    
    /* methods */
    RGB clear(t_rgb v=MIN) {
        r = g = b = v;
        return *this;
    }
    
    RGB dump();
    
    t_rgb check(int n_rgb) {
        if( n_rgb < 0) n_rgb = 0;
        if( n_rgb > 255) n_rgb = 255;
        return (t_rgb)n_rgb;
    }
    
    RGB blend(const string hex);
    RGB blend(const string* hexArr, int size=0);
    
    
    // getter/setter
    d_rgb red() {
        return (d_rgb)r;
    }
    d_rgb green() {
        return (d_rgb)g;
    }
    d_rgb blue() {
        return (d_rgb)b;
    }
    RGB red(t_rgb cv) {
        r = cv;
        return *this;
    }
    RGB green(t_rgb cv) {
        g = cv;
        return *this;
    }
    RGB blue(t_rgb cv) {
        b = cv;
        return *this;
    }
    
    
    // convertor
    RGB fromRGBA(const RGBA& rgba);
    RGB fromCMYK(const CMYK& cmyk);
    RGB fromHSL(const HSL& hsl);
    RGB fromHSV(const HSV& hsv);
    RGB fromHEX(string hex, bool bCheckHex=false);
    RGBA toRGBA();
    CMYK toCMYK();
    HSL  toHSL();
    HSV  toHSV();
    const string toHEX();
    
    /* constants */
    static const t_rgb MIN;
    static const t_rgb MID;
    static const t_rgb MAX;
};

#endif /* ColorRGB_hpp */
