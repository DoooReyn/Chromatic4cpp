//
//  ColorRGBA.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/16.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef ColorRGBA_hpp
#define ColorRGBA_hpp

#include "BaseMath.hpp"

struct RGB;
struct CMYK;


struct RGBA  {
public:
    /* data */
    t_rgba r;
    t_rgba g;
    t_rgba b;
    t_rgba a;
    
    
    /* constructor */
    RGBA();
    RGBA(t_rgba _r, t_rgba _g, t_rgba _b, t_rgba _a);
    RGBA(const RGBA& other);
    RGBA(const RGB& other);
    RGBA(const CMYK& cmyk);
    RGBA(std::string hex);
    
    
    /* operator */
    bool operator == (const RGBA& other) const;
    bool operator != (const RGBA& other) const;
    RGBA operator +  (const t_rgba cv);
    RGBA operator +  (const RGBA& other);
    RGBA operator -  (const t_rgba cv);
    RGBA operator -  (const RGBA& other);
    RGBA operator *  (const float scale);
    RGBA operator *  (const RGBA& other);
    RGBA operator /  (const float scale);
    RGBA operator /  (const RGBA& other);
    RGBA operator %  (const t_rgba cv);
    RGBA operator %  (const float cv);
    RGBA operator %  (const RGBA& other);
    
    bool equals(const RGBA& other) {
        return (*this == other);
    }
    bool nequals(const RGBA& other) {
        return (*this != other);
    }
    RGBA add(t_rgba cv) {
        return *this + cv;
    }
    RGBA add(const RGBA& other) {
        return *this + other;
    }
    RGBA sub(t_rgba cv) {
        return *this - cv;
    }
    RGBA sub(const RGBA& other) {
        return *this - other;
    }
    RGBA scale(float s) {
        return (*this) * s;
    }
    RGBA scale(const RGBA& other) {
        return *this * other;
    }
    RGBA divide(float d) {
        return (*this) / d;
    }
    RGBA divide(const RGBA& other) {
        return *this / other;
    }
    RGBA mod(float d) {
        return (*this) % d;
    }
    RGBA mod(const RGBA& other) {
        return *this % other;
    }
    
    /* methods */
    RGBA clear(t_rgba v=MIN) {
        r = g = b = a = v;
        return *this;
    }
    
    t_rgba check(t_cmyk n_rgb) {
        if( n_rgb < 0) n_rgb = 0;
        if( n_rgb > 255) n_rgb = 255;
        return (t_rgba)n_rgb;
    }
    
    RGBA dump();

    
    /* getter/setter */
    
    d_rgba red() {
        return (d_rgba)r;
    }
    d_rgba green() {
        return (d_rgba)g;
    }
    d_rgba blue() {
        return (d_rgba)b;
    }
    d_rgba alpha() {
        return (d_rgba)a;
    }
    RGBA red(t_rgba cv) {
        r = cv;
        return *this;
    }
    RGBA green(t_rgba cv) {
        g = cv;
        return *this;
    }
    RGBA blue(t_rgba cv) {
        b = cv;
        return *this;
    }
    RGBA alpha(t_rgba cv) {
        a = cv;
        return *this;
    }
    
    /* convertor */
    RGB toRGB();
    RGBA fromRGB(const RGB& rgb);
    std::string tohex();
    RGBA fromhex(std::string hex, bool bCheckHex=false);
    CMYK toCMYK();
    RGBA fromCMYK(const CMYK& cmyk);
    
    
    /* constants */
    static const t_rgba MIN;
    static const t_rgba MID;
    static const t_rgba MAX;
};


#endif /* ColorRGBA_hpp */
