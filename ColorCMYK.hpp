//
//  ColorCMYK.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef ColorCMYK_hpp
#define ColorCMYK_hpp

#include "BaseMath.hpp"
#include "BaseTypes.hpp"
using namespace std;

struct RGB;
struct RGBA;

struct CMYK {
    /* data */
    t_cmyk c;// cyan
    t_cmyk m;// magenta
    t_cmyk y;// yellow
    t_cmyk k;// black
    
    
    /* constructor */
    CMYK();
    CMYK(t_cmyk _c, t_cmyk _m, t_cmyk _y, t_cmyk _k);
    CMYK(const CMYK& cmyk);
    CMYK(const RGB& rgb);
    CMYK(const RGBA& rgba);
    CMYK(const HSL& hsl);
    CMYK(const HSV& hsv);
    CMYK(string hex);
    
    
    /* operator */
    bool operator == (const CMYK& other) const;
    bool operator != (const CMYK& other) const;
    CMYK operator +  (const t_cmyk cv);
    CMYK operator +  (const CMYK& other);
    CMYK operator -  (const t_cmyk cv);
    CMYK operator -  (const CMYK& other);
    CMYK operator *  (const t_cmyk scale);
    CMYK operator *  (const CMYK& other);
    CMYK operator /  (const t_cmyk scale);
    CMYK operator /  (const CMYK& other);
    CMYK operator %  (const t_cmyk cv);
    CMYK operator %  (const CMYK& other);
    
    bool equals(const CMYK& other) {
        return (*this == other);
    }
    bool nequals(const CMYK& other) {
        return (*this != other);
    }
    CMYK add(t_cmyk cv) {
        return *this + cv;
    }
    CMYK add(const CMYK& other) {
        return *this + other;
    }
    CMYK sub(t_cmyk cv) {
        return *this - cv;
    }
    CMYK sub(const CMYK& other) {
        return *this - other;
    }
    CMYK scale(float s) {
        return (*this) * s;
    }
    CMYK scale(const CMYK& other) {
        return *this * other;
    }
    CMYK divide(float d) {
        return (*this) / d;
    }
    CMYK divide(const CMYK& other) {
        return *this / other;
    }
    CMYK mod(float d) {
        return (*this) % d;
    }
    CMYK mod(const CMYK& other) {
        return *this % other;
    }
    
    
    /* methods */
    CMYK clear(t_cmyk cv=CMYK::MIN) {
        c = m = y = k = cv;
        return *this;
    }
    
    t_cmyk check(t_cmyk cv) {
        if(cv < CMYK::MIN) return CMYK::MIN;
        if(cv > CMYK::MAX) return CMYK::MAX;
        return (t_cmyk)cv;
    }
    
    CMYK dump();

    
    // getter/setter
    t_cmyk cyan() {
        return c;
    }
    t_cmyk magenta() {
        return m;
    }
    t_cmyk yellow() {
        return y;
    }
    t_cmyk black() {
        return k;
    }
    CMYK cyan(t_cmyk cv) {
        c = check(cv);
        return *this;
    }
    CMYK magenta(t_cmyk cv) {
        m = check(cv);
        return *this;
    }
    CMYK yellow(t_cmyk cv) {
        y = check(cv);
        return *this;
    }
    CMYK black(t_cmyk cv) {
        k = check(cv);
        return *this;
    }
    
    
    // convertor
    CMYK fromRGB(const RGB& rgb);
    CMYK fromRGBA(const RGBA& rgba);
    CMYK fromHSL(const HSL& hsl);
    CMYK fromHSV(const HSV& hsv);
    CMYK fromHEX(const string hex);
    RGB  toRGB();
    RGBA toRGBA();
    HSL  toHSL();
    HSV  toHSV();
    const string toHEX();
    
    
    /* constants */
    static const t_cmyk MIN;
    static const t_cmyk MID;
    static const t_cmyk MAX;
    
};

#endif /* ColorCMYK_hpp */
