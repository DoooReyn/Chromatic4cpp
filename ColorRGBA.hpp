//
//  ColorRGBA.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/16.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef ColorRGBA_hpp
#define ColorRGBA_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "StringUtils.hpp"

typedef unsigned char  t_rgb;
typedef unsigned char  t_rgba;
typedef unsigned short d_rgb;
typedef unsigned short d_rgba;

// forward declaration
struct RGBA;

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
    RGB(const RGB &rgb);
    RGB(const RGBA& rgba);
    RGB(std::string hex);
    
    /* operator */
    bool operator == (const RGB& other) const;
    bool operator != (const RGB& other) const;
    
    RGB  operator + (const t_rgb cv);
    RGB  operator + (const RGB& other);
    
    RGB  operator - (const t_rgb cv);
    RGB  operator - (const RGB& other);
    
    RGB  operator * (const float scale);
    RGB  operator * (const RGB& other);
    
    RGB  operator / (const float scale);
    RGB  operator / (const RGB& other);
    
    RGB  operator % (const t_rgb c);
    RGB  operator % (const RGB& other);
    
    
    /* methods */
    bool equals(const RGB& other)
    {
        return (*this == other);
    }
    
    RGB scale(float s);
    
    RGB divide(float d);
    
    RGB clear(t_rgb v=MIN) {
        r = g = b = v;
        return *this;
    }
    
    RGB dump()
    {
        std::cout
        << "RGB("
        << StringUtils::fill03(red())
        << ","
        << StringUtils::fill03(green())
        << ","
        << StringUtils::fill03(blue())
        << "), "
        << "HEX("
        << tohex().c_str()
        << ")"
        << std::endl;
        
        return *this;
    }
    
    d_rgb red()
    {
        return (d_rgb)r;
    }
    
    d_rgb green()
    {
        return (d_rgb)g;
    }
    
    d_rgb blue()
    {
        return (d_rgb)b;
    }
    
    t_rgb check(int n_rgb) {
        if( n_rgb < 0) n_rgb = 0;
        if( n_rgb > 255) n_rgb = 255;
        return (t_rgb)n_rgb;
    }

    const std::string tohex()
    {
        std::string s_rgb("");
        s_rgb.append(StringUtils::hex02(red  ()));
        s_rgb.append(StringUtils::hex02(green()));
        s_rgb.append(StringUtils::hex02(blue ()));
        return s_rgb;
    }
    
    RGB fromhex(std::string hex, bool bCheckHex=false) {
        clear();
        if(bCheckHex && !StringUtils::checkhex(hex)) return *this;
        
        unsigned long unHexSize = hex.size();
        unsigned long unSize = (unHexSize / 2) + (unHexSize % 2 == 0 ? 0 : 1);
        std::vector<t_rgb*> vecRGBA;
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
    
    RGBA toRGBA();
    RGB fromRGBA(const RGBA& rgba);
    
    /* constants */
    static const RGB WHITE;
    static const RGB YELLOW;
    static const RGB BLUE;
    static const RGB GREEN;
    static const RGB RED;
    static const RGB MAGENTA;
    static const RGB BLACK;
    static const RGB ORANGE;
    static const RGB GRAY;
    static const RGB INDIGO;
    static const RGB GOLD;
    static const RGB HOTPINK;
    static const RGB FIREBRICK;
    static const RGB INDIANRED;
    static const RGB MISTYROSE;
    static const RGB DARKOLIVEGREEN;
    static const RGB OLIVE;
    static const RGB DARKSEAGREEN;
    static const RGB PINK;
    static const RGB TOMATO;
    static const RGB LIGHTCORAL;
    static const RGB ORANGERED;
    static const RGB NAVAJOWHITE;
    static const RGB LIME;
    static const RGB PALEGREEN;
    static const RGB DARKSLATEGREY;
    static const RGB GREENYELLOW;
    static const RGB BURLYWOOD;
    static const RGB SEASHELL;
    static const RGB MEDIUMSPRINGGREEN;
    static const RGB FUCHSIA;
    static const RGB PAPAYAWHIP;
    static const RGB BLANCHEDALMOND;
    static const RGB CHARTREUSE;
    static const RGB DIMGRAY;
    static const RGB PEACHPUFF;
    static const RGB SPRINGGREEN;
    static const RGB AQUAMARINE;
    static const RGB LIGHTSALMON;
    static const RGB DARKSLATEGRAY;
    static const RGB BROWN;
    static const RGB IVORY;
    static const RGB DODGERBLUE;
    static const RGB PERU;
    static const RGB LAWNGREEN;
    static const RGB CHOCOLATE;
    static const RGB CRIMSON;
    static const RGB FORESTGREEN;
    static const RGB DARKGREY;
    static const RGB LIGHTSEAGREEN;
    static const RGB CYAN;
    static const RGB MINTCREAM;
    static const RGB SILVER;
    static const RGB ANTIQUEWHITE;
    static const RGB MEDIUMORCHID;
    static const RGB SKYBLUE;
    static const RGB DARKTURQUOISE;
    static const RGB GOLDENROD;
    static const RGB DARKGREEN;
    static const RGB FLORALWHITE;
    static const RGB DARKVIOLET;
    static const RGB DARKGRAY;
    static const RGB MOCCASIN;
    static const RGB SADDLEBROWN;
    static const RGB GREY;
    static const RGB DARKSLATEBLUE;
    static const RGB LIGHTSKYBLUE;
    static const RGB LIGHTPINK;
    static const RGB MEDIUMVIOLETRED;
    static const RGB SLATEGREY;
    static const RGB DEEPPINK;
    static const RGB LIMEGREEN;
    static const RGB DARKMAGENTA;
    static const RGB PALEGOLDENROD;
    static const RGB PLUM;
    static const RGB TURQUOISE;
    static const RGB LIGHTGREY;
    static const RGB LIGHTGOLDENRODYELLOW;
    static const RGB DARKGOLDENROD;
    static const RGB LAVENDER;
    static const RGB MAROON;
    static const RGB YELLOWGREEN;
    static const RGB SANDYBROWN;
    static const RGB THISTLE;
    static const RGB VIOLET;
    static const RGB NAVY;
    static const RGB DIMGREY;
    static const RGB TAN;
    static const RGB ROSYBROWN;
    static const RGB OLIVEDRAB;
    static const RGB LIGHTBLUE;
    static const RGB GHOSTWHITE;
    static const RGB HONEYDEW;
    static const RGB CORNFLOWERBLUE;
    static const RGB SLATEBLUE;
    static const RGB LINEN;
    static const RGB DARKBLUE;
    static const RGB POWDERBLUE;
    static const RGB SEAGREEN;
    static const RGB DARKKHAKI;
    static const RGB SNOW;
    static const RGB SIENNA;
    static const RGB MEDIUMBLUE;
    static const RGB ROYALBLUE;
    static const RGB LIGHTCYAN;
    static const RGB MEDIUMPURPLE;
    static const RGB MIDNIGHTBLUE;
    static const RGB CORNSILK;
    static const RGB PALETURQUOISE;
    static const RGB BISQUE;
    static const RGB SLATEGRAY;
    static const RGB DARKCYAN;
    static const RGB KHAKI;
    static const RGB WHEAT;
    static const RGB TEAL;
    static const RGB DARKORCHID;
    static const RGB DEEPSKYBLUE;
    static const RGB SALMON;
    static const RGB DARKRED;
    static const RGB STEELBLUE;
    static const RGB PALEVIOLETRED;
    static const RGB LIGHTSLATEGRAY;
    static const RGB ALICEBLUE;
    static const RGB LIGHTSLATEGREY;
    static const RGB LIGHTGREEN;
    static const RGB ORCHID;
    static const RGB GAINSBORO;
    static const RGB MEDIUMSEAGREEN;
    static const RGB LIGHTGRAY;
    static const RGB MEDIUMTURQUOISE;
    static const RGB LEMONCHIFFON;
    static const RGB CADETBLUE;
    static const RGB LIGHTYELLOW;
    static const RGB LAVENDERBLUSH;
    static const RGB CORAL;
    static const RGB PURPLE;
    static const RGB AQUA;
    static const RGB WHITESMOKE;
    static const RGB MEDIUMSLATEBLUE;
    static const RGB DARKORANGE;
    static const RGB MEDIUMAQUAMARINE;
    static const RGB DARKSALMON;
    static const RGB BEIGE;
    static const RGB BLUEVIOLET;
    static const RGB AZURE;
    static const RGB LIGHTSTEELBLUE;
    static const RGB OLDLACE;
    static const RGB REBECCAPURPLE;
    
    static const t_rgb MIN;
    static const t_rgb MID;
    static const t_rgb MAX;
};

struct RGBA  {
public:
    /* data */
    t_rgba r;
    t_rgba g;
    t_rgba b;
    t_rgba a;
    
    
    /* constructor */
    RGBA();
    RGBA(t_rgb _r, t_rgb _g, t_rgb _b, t_rgb _a);
    RGBA(const RGBA& other);
    RGBA(const RGB& other);
    RGBA(std::string hex);
    
    
    /* operator */
    bool operator == (const RGBA& other) const;
    bool operator != (const RGBA& other) const;
    
    RGBA  operator +  (const t_rgba cv);
    RGBA  operator +  (const RGBA& other);
    
    RGBA  operator -  (const t_rgba cv);
    RGBA  operator -  (const RGBA& other);
    
    RGBA  operator *  (const float scale);
    RGBA  operator *  (const RGBA& other);
    
    RGBA  operator /  (const float scale);
    RGBA  operator /  (const RGBA& other);
    
    RGBA  operator %  (const t_rgba cv);
    RGBA  operator %  (const RGBA& other);
    
    
    /* methods */
    bool equals(const RGBA& other)
    {
        return (*this == other);
    }
    
    RGBA scale(float s);
    
    RGBA divide(float d);
    
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

    RGBA clear(t_rgba v=MIN) {
        r = g = b = a = v;
        return *this;
    }
    
    t_rgba check(int n_rgb) {
        if( n_rgb < 0) n_rgb = 0;
        if( n_rgb > 255) n_rgb = 255;
        return (t_rgba)n_rgb;
    }
    
    RGBA dump()
    {
        std::cout
        << "RGBA("
        << StringUtils::fill03(red())
        << ","
        << StringUtils::fill03(green())
        << ","
        << StringUtils::fill03(blue())
        << ","
        << StringUtils::fill03(alpha())
        << "), "
        << "HEX("
        << tohex().c_str()
        << ")"
        << std::endl;
        
        return *this;
    }

    const std::string tohex()
    {
        std::string s_rgba("");
        s_rgba.append(StringUtils::hex02(red  ()));
        s_rgba.append(StringUtils::hex02(green()));
        s_rgba.append(StringUtils::hex02(blue ()));
        s_rgba.append(StringUtils::hex02(alpha()));
        return s_rgba;
    }
    
    RGBA fromhex(std::string hex, bool bCheckHex=false) {
        clear();
        if(bCheckHex && !StringUtils::checkhex(hex)) return *this;
        
        unsigned long unHexSize = hex.size();
        unsigned long unSize = (unHexSize / 2) + (unHexSize % 2 == 0 ? 0 : 1);
        std::vector<t_rgba*> vecRGBA;
        vecRGBA.clear();
        vecRGBA.push_back(&r);
        vecRGBA.push_back(&g);
        vecRGBA.push_back(&b);
        vecRGBA.push_back(&a);
        for(unsigned long i=0,j=0; i<unSize && i<4; i++,j+=2) {
            int nhigh = StringUtils::hex01(hex.at(j)) * 16;
            int nlow  = (j+1) >= unHexSize ? 0 : StringUtils::hex01(hex.at(j+1));
            *vecRGBA.at(i) = t_rgba(nhigh + nlow);
        }
        return *this;
    }
    
    RGB toRGB() {
        return RGB(r,g,b);
    }
    
    RGBA fromRGB(const RGB& rgb) {
        r = rgb.r;
        g = rgb.g;
        b = rgb.b;
        a = RGBA::MAX;
        return *this;
    }
    
    
    /* constants */
    static const RGBA WHITE;
    static const RGBA YELLOW;
    static const RGBA BLUE;
    static const RGBA GREEN;
    static const RGBA RED;
    static const RGBA MAGENTA;
    static const RGBA BLACK;
    static const RGBA ORANGE;
    static const RGBA GRAY;
    static const RGBA INDIGO;
    static const RGBA GOLD;
    static const RGBA HOTPINK;
    static const RGBA FIREBRICK;
    static const RGBA INDIANRED;
    static const RGBA MISTYROSE;
    static const RGBA DARKOLIVEGREEN;
    static const RGBA OLIVE;
    static const RGBA DARKSEAGREEN;
    static const RGBA PINK;
    static const RGBA TOMATO;
    static const RGBA LIGHTCORAL;
    static const RGBA ORANGERED;
    static const RGBA NAVAJOWHITE;
    static const RGBA LIME;
    static const RGBA PALEGREEN;
    static const RGBA DARKSLATEGREY;
    static const RGBA GREENYELLOW;
    static const RGBA BURLYWOOD;
    static const RGBA SEASHELL;
    static const RGBA MEDIUMSPRINGGREEN;
    static const RGBA FUCHSIA;
    static const RGBA PAPAYAWHIP;
    static const RGBA BLANCHEDALMOND;
    static const RGBA CHARTREUSE;
    static const RGBA DIMGRAY;
    static const RGBA PEACHPUFF;
    static const RGBA SPRINGGREEN;
    static const RGBA AQUAMARINE;
    static const RGBA LIGHTSALMON;
    static const RGBA DARKSLATEGRAY;
    static const RGBA BROWN;
    static const RGBA IVORY;
    static const RGBA DODGERBLUE;
    static const RGBA PERU;
    static const RGBA LAWNGREEN;
    static const RGBA CHOCOLATE;
    static const RGBA CRIMSON;
    static const RGBA FORESTGREEN;
    static const RGBA DARKGREY;
    static const RGBA LIGHTSEAGREEN;
    static const RGBA CYAN;
    static const RGBA MINTCREAM;
    static const RGBA SILVER;
    static const RGBA ANTIQUEWHITE;
    static const RGBA MEDIUMORCHID;
    static const RGBA SKYBLUE;
    static const RGBA DARKTURQUOISE;
    static const RGBA GOLDENROD;
    static const RGBA DARKGREEN;
    static const RGBA FLORALWHITE;
    static const RGBA DARKVIOLET;
    static const RGBA DARKGRAY;
    static const RGBA MOCCASIN;
    static const RGBA SADDLEBROWN;
    static const RGBA GREY;
    static const RGBA DARKSLATEBLUE;
    static const RGBA LIGHTSKYBLUE;
    static const RGBA LIGHTPINK;
    static const RGBA MEDIUMVIOLETRED;
    static const RGBA SLATEGREY;
    static const RGBA DEEPPINK;
    static const RGBA LIMEGREEN;
    static const RGBA DARKMAGENTA;
    static const RGBA PALEGOLDENROD;
    static const RGBA PLUM;
    static const RGBA TURQUOISE;
    static const RGBA LIGHTGREY;
    static const RGBA LIGHTGOLDENRODYELLOW;
    static const RGBA DARKGOLDENROD;
    static const RGBA LAVENDER;
    static const RGBA MAROON;
    static const RGBA YELLOWGREEN;
    static const RGBA SANDYBROWN;
    static const RGBA THISTLE;
    static const RGBA VIOLET;
    static const RGBA NAVY;
    static const RGBA DIMGREY;
    static const RGBA TAN;
    static const RGBA ROSYBROWN;
    static const RGBA OLIVEDRAB;
    static const RGBA LIGHTBLUE;
    static const RGBA GHOSTWHITE;
    static const RGBA HONEYDEW;
    static const RGBA CORNFLOWERBLUE;
    static const RGBA SLATEBLUE;
    static const RGBA LINEN;
    static const RGBA DARKBLUE;
    static const RGBA POWDERBLUE;
    static const RGBA SEAGREEN;
    static const RGBA DARKKHAKI;
    static const RGBA SNOW;
    static const RGBA SIENNA;
    static const RGBA MEDIUMBLUE;
    static const RGBA ROYALBLUE;
    static const RGBA LIGHTCYAN;
    static const RGBA MEDIUMPURPLE;
    static const RGBA MIDNIGHTBLUE;
    static const RGBA CORNSILK;
    static const RGBA PALETURQUOISE;
    static const RGBA BISQUE;
    static const RGBA SLATEGRAY;
    static const RGBA DARKCYAN;
    static const RGBA KHAKI;
    static const RGBA WHEAT;
    static const RGBA TEAL;
    static const RGBA DARKORCHID;
    static const RGBA DEEPSKYBLUE;
    static const RGBA SALMON;
    static const RGBA DARKRED;
    static const RGBA STEELBLUE;
    static const RGBA PALEVIOLETRED;
    static const RGBA LIGHTSLATEGRAY;
    static const RGBA ALICEBLUE;
    static const RGBA LIGHTSLATEGREY;
    static const RGBA LIGHTGREEN;
    static const RGBA ORCHID;
    static const RGBA GAINSBORO;
    static const RGBA MEDIUMSEAGREEN;
    static const RGBA LIGHTGRAY;
    static const RGBA MEDIUMTURQUOISE;
    static const RGBA LEMONCHIFFON;
    static const RGBA CADETBLUE;
    static const RGBA LIGHTYELLOW;
    static const RGBA LAVENDERBLUSH;
    static const RGBA CORAL;
    static const RGBA PURPLE;
    static const RGBA AQUA;
    static const RGBA WHITESMOKE;
    static const RGBA MEDIUMSLATEBLUE;
    static const RGBA DARKORANGE;
    static const RGBA MEDIUMAQUAMARINE;
    static const RGBA DARKSALMON;
    static const RGBA BEIGE;
    static const RGBA BLUEVIOLET;
    static const RGBA AZURE;
    static const RGBA LIGHTSTEELBLUE;
    static const RGBA OLDLACE;
    static const RGBA REBECCAPURPLE;
    
    static const t_rgba MIN;
    static const t_rgba MID;
    static const t_rgba MAX;
};


#endif /* ColorRGBA_hpp */
