# chromatic4cpp

## 一、介绍
`chromatic4cpp` 致力于为 `C++` 的色值操作和相互转换提供便利，当前已经支持 `RGB，RGBA，CMYK，HSL，HSV` 五种色值类型。

**chromatic4cpp 主要特点有：**
- 支持色值之间的运算（加、减、乘、除、取余、等于、不等于 及其他）；
- 支持十六进制色值与 `RGB，RGBA，CMYK，HSL，HSV` 之间的转换；
- 提供了丰富的十六进制预定义色值*（无 `Alpha` 通道）*；
- 不同模式下的随机色值；
- 不同模式之间的色值比对；
- ...

**chromatic4cpp 的主要接口如下：**
- `equals` : 同等于
- `nequals` : 同不等于
- `add` : 同加法
- `sub` : 同减法
- `scale` : 同乘法
- `divide` : 同除法
- `mod` : 同取模
- `clear` : 清空色值
- `check` : 检查输入的色值是否有效（结果会获得有效的色值）
- `dump` : 打印色值 *[输出自身的格式和十六进制格式]*
- `red` : 获取/设置 r 位色值
- `green` : 获取/设置 RGB 模式下的 g 位色值
- `blue` : 获取/设置 RGB 模式下的 b 位色值
- `alpha` : 获取/设置 RGB 模式下的 a 位色值
- `cyan` : 获取/设置 CMYK 模式下的 c 位色值
- `yellow` : 获取/设置 CMYK 模式下的 y 位色值
- `magenta` : 获取/设置 CMYK 模式下的 m 位色值
- `black` : 获取/设置 CMYK 模式下的 k 位色值
- `hue` : 获取/设置 HSL/HSV 模式下的 h 位色值
- `saturation` : 获取/设置 HSL/HSV 模式下的 s 位色值
- `lightness` : 获取/设置 HSL 模式下的 l 位色值
- `value` : 获取/设置 HSV 模式下的 v 位色值
- `fromRGB(A)` : 从 RGB(A) 模式转换
- `fromCMYK` : 从 CMYK 模式转换
- `fromHSL(V)` :从 HSL(V) 模式转换
- `fromHEX` : 从十六进制模式转换
- `toRGB(A)` : 转换为 RGB(A) 模式
- `toCMYK` : 转换为 CMYK 模式
- `toHSL(V)` :转换为 HSL(V) 模式
- `toHEX` : 转换为十六进制模式
- `blend` : 混合色值计算（色值叠加计算，目前只支持 RGB 和 RGBA）
- `opposite` : 获取 RGB(A) 色值的相反色
- `Chromatic::equals` : 宽松比对两种色彩模式的色值是否相等
- `Chromatic::sequals` : 严格比对两种色彩模式的色值是否相等
- `random` : 获取随机色值


## 二、测试用例

``` cpp
//
//  main.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/1/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "Chromatics/Chromatics.hpp"
#include "StringUtils.hpp"
using namespace Chromatic;
using namespace std;

void RGB_TestCase() {
    cout << "<# RGB TestCase Start" << endl;
    
    cout << "=> RGB original data:" << endl;
    RGB case0 = RGB(Chromatic::REBECCAPURPLE);
    case0.dump();
    
    cout << endl << "=> single operator:" << endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    cout << endl << "=> mixed  operator:" << endl;
    case0.clear(166);
    (case0+RGB(1,1,1)).dump();
    (case0-RGB(1,1,1)).dump();
    (case0*RGB(2,2,2)).dump();
    (case0/RGB(2,2,2)).dump();
    (case0%RGB(15,15,15)).dump();
    
    cout << endl << "=> use scale:" << endl;
    (case0.scale(10.8).dump());
    
    cout << endl << "=> use divide:" << endl;
    (case0.divide(2).dump());

    cout << endl << "=> from hex string(do check):" << endl;
    case0.fromHEX("80aF*U", true).dump();
    
    cout << endl << "=> from hex string(do not check):" << endl;
    case0.fromHEX("80aF*U", false).dump();
    
    cout << endl << "=> to hex string:" << endl;
    cout << case0.toHEX() << endl;
    
    cout << endl << "=> from/to RGBA:" << endl;
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    cout << endl << "=> clear with:" << endl;
    case0.clear(255).dump();
    
    cout << endl << "=> RED + LIME = YELLOW : " << endl;
    (RGB(Chromatic::RED) + RGB(Chromatic::LIME)).dump();
    RGB(Chromatic::YELLOW).dump();
    
    cout << endl << "=> convertor: " << endl;
    RGB rgb = RGB().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    rgb.toRGBA().dump();
    rgb.toCMYK().dump();
    rgb.toHSL().dump();
    
    cout << "!!! RGB TestCase End #>" << endl << endl;
}


void RGBA_TestCase() {
    cout << "<# RGBA TestCase Start" << endl;
    
    RGBA case0 = RGBA(Chromatic::INDIGO);
    
    cout << "=> RGBA original data:" << endl;
    case0.dump();
    
    cout << endl << "=> single operator:" << endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    cout << endl << "=> mixed  operator:" << endl;
    case0.clear(166);
    (case0+RGBA(1,1,1,1)).dump();
    (case0-RGBA(1,1,1,1)).dump();
    (case0*RGBA(2,2,2,2)).dump();
    (case0/RGBA(2,2,2,2)).dump();
    (case0%RGBA(15,15,15,15)).dump();
    
    cout << endl << "=> use scale:" << endl;
    (case0.scale(10.8).dump());
    
    cout << endl << "=> use divide:" << endl;
    (case0.divide(2).dump());
    
    cout << endl << "=> from hex string (do check):" << endl;
    case0.fromHEX("80aF*UE", true).dump();
    
    cout << endl << "=> from hex string (do not check):" << endl;
    case0.fromHEX("80aF*UE", false).dump();
    
    cout << endl << "=> to hex string:" << endl;
    cout << case0.toHEX() << endl;
    
    cout << endl << "=> from/to RGB:" << endl;
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    cout << endl << "=> clear with:" << endl;
    case0.clear(255).dump();
    
    cout << endl << "=> convertor: " << endl;
    RGBA rgba = RGBA().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    rgba.toRGB().dump();
    rgba.toCMYK().dump();
    rgba.toHSL().dump();
    
    cout << "!!! RGBA TestCase End #>" << endl << endl;
}

void CMYK_TestCase() {
    cout << "<# CMYK TestCase Start " << endl;
    
    CMYK cmyk = CMYK().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    cmyk.toRGB().dump();
    cmyk.toHSL().dump();
    cmyk.toRGBA().dump();
    
    cout << "!!! CMYK TestCase END #>" << endl << endl;
}

void HSL_TestCase() {
    cout << "<# HSL TestCase Start " << endl;
    
    HSL hsl = HSL().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    hsl.toRGB().dump();
    hsl.toCMYK().dump();
    hsl.toRGBA().dump();
    
    cout << "!!! HSL TestCase Start #>" << endl << endl;
}

void HSV_TestCase() {
    cout << "<# HSV TestCase Start" << endl;
    HSV hsv = HSV().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    hsv.toRGB().dump();
    hsv.toCMYK().dump();
    hsv.toRGBA().dump();
    cout << "!!! HSV TestCase End #>" << endl << endl;
}


void RGB_Blend_TestCase() {
    cout << "<# RGB Blend TestCase Start" << endl;
    
    bool bBlendRedLime = RGB(RED).blend(LIME) == YELLOW;
    cout << "Red blend Lime = Yellow ? ";
    bBlendRedLime ? cout << "True" : cout << "False";
    cout << endl;
    
    bBlendRedLime = RGB(RED).blend(LIME) + RGB(YELLOW).opposite() == WHITE;
    cout << "Red blend Green = Yellow ? ";
    bBlendRedLime ? cout << "True" : cout << "False";
    cout << endl;
    
    cout << "!!! RGB Blend TestCase End #>" << endl << endl;
}

void RGBA_Blend_TestCase() {
    cout << "<# RGBA Blend TestCase Start" << endl;
    
    RGBA c1 = RGBA().fromAlphaF(235, 152, 80, 0.6f).dump();
    RGBA c2 = RGBA().fromAlphaF(234, 97, 124, 0.8f).dump();
    c1.blend(c2).dump();
    
    cout << "RGBA Blend TestCase End #>" << endl << endl;
}

void ColorRandom_TestCase() {
    cout << "<# Color Random TestCase Start" << endl;
    
    RGB  c1 = RGB().random().dump();
    randomColor(c1).dump();
    RGBA c2 = RGBA().random().dump();
    randomColor(c2).dump();
    CMYK c3 = CMYK().random().dump();
    randomColor(c3).dump();
    HSL  c4 = HSL().random().dump();
    randomColor(c4).dump();
    HSV  c5 = HSV().random().dump();
    randomColor(c5).dump();
    
    cout << "!!! Color Random TestCase End #>" << endl << endl;
}

void CompareColor_TestCase() {
    cout << "<# Compare Color With Mode Start" << endl;
    
    RGB  c1 = RGB(LIMEGREEN).dump();
    RGBA c2 = RGBA(LIMEGREEN).alpha(88).dump();
    CMYK c3 = CMYK(LIMEGREEN).dump();
    HSL  c4 = HSL(LIMEGREEN).dump();
    HSV  c5 = HSV(LIMEGREEN).dump();
    cout << "[Color Value] LIMEGREEN: HEX(#32CD32)" << endl;
    cout << "[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV " << endl;
    cout << "[CampareMode] loose :" << endl;
    cout << "c1 == c2 ? " << (equals(c1, c2) ? "True" : "False") << endl;
    cout << "c1 == c3 ? " << (equals(c1, c3) ? "True" : "False") << endl;
    cout << "c1 == c4 ? " << (equals(c1, c4) ? "True" : "False") << endl;
    cout << "c1 == c5 ? " << (equals(c1, c5) ? "True" : "False") << endl;
    cout << "c2 == c3 ? " << (equals(c2, c3) ? "True" : "False") << endl;
    cout << "c2 == c4 ? " << (equals(c2, c4) ? "True" : "False") << endl;
    cout << "c2 == c5 ? " << (equals(c2, c5) ? "True" : "False") << endl;
    cout << "c3 == c4 ? " << (equals(c3, c4) ? "True" : "False") << endl;
    cout << "c3 == c5 ? " << (equals(c3, c5) ? "True" : "False") << endl;
    cout << "c4 == c5 ? " << (equals(c4, c5) ? "True" : "False") << endl;
    cout << "[Color Value] LIMEGREEN: HEX(#32CD32)" << endl;
    cout << "[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV " << endl;
    cout << "[CampareMode] strict :" << endl;
    cout << "c1 == c2 ? " << (sequals(c1, c2) ? "True" : "False") << endl;
    cout << "c1 == c3 ? " << (sequals(c1, c3) ? "True" : "False") << endl;
    cout << "c1 == c4 ? " << (sequals(c1, c4) ? "True" : "False") << endl;
    cout << "c1 == c5 ? " << (sequals(c1, c5) ? "True" : "False") << endl;
    cout << "c2 == c3 ? " << (sequals(c2, c3) ? "True" : "False") << endl;
    cout << "c2 == c4 ? " << (sequals(c2, c4) ? "True" : "False") << endl;
    cout << "c2 == c5 ? " << (sequals(c2, c5) ? "True" : "False") << endl;
    cout << "c3 == c4 ? " << (sequals(c3, c4) ? "True" : "False") << endl;
    cout << "c3 == c5 ? " << (sequals(c3, c5) ? "True" : "False") << endl;
    cout << "c4 == c5 ? " << (sequals(c4, c5) ? "True" : "False") << endl;
    
    cout << "!!! Compare Color With Mode End #>" << endl << endl;
}

int main() {
    RGB_TestCase();
    RGBA_TestCase();
    CMYK_TestCase();
    HSL_TestCase();
    HSV_TestCase();
    RGB_Blend_TestCase();
    RGBA_Blend_TestCase();
    ColorRandom_TestCase();
    CompareColor_TestCase();
}

```

**输出：**

``` zsh
<# RGB TestCase Start
=> RGB original data:
RGB(102,051,153) HEX(#663399)

=> single operator:
RGB(103,052,154) HEX(#67349A)
RGB(102,051,153) HEX(#663399)
RGB(204,102,255) HEX(#CC66FF)
RGB(102,051,127) HEX(#66337F)
RGB(012,006,007) HEX(#0C0607)

=> mixed  operator:
RGB(167,167,167) HEX(#A7A7A7)
RGB(166,166,166) HEX(#A6A6A6)
RGB(255,255,255) HEX(#FFFFFF)
RGB(127,127,127) HEX(#7F7F7F)
RGB(007,007,007) HEX(#070707)

=> use scale:
RGB(075,075,075) HEX(#4B4B4B)

=> use divide:
RGB(037,037,037) HEX(#252525)

=> from hex string(do check):
RGB(000,000,000) HEX(#000000)

=> from hex string(do not check):
RGB(128,175,000) HEX(#80AF00)

=> to hex string:
#80AF00

=> from/to RGBA:
RGBA(128,175,000,000) HEX(#80AF0000)
RGB(128,175,000) HEX(#80AF00)

=> clear with:
RGB(255,255,255) HEX(#FFFFFF)

=> RED + LIME = YELLOW : 
RGB(255,255,000) HEX(#FFFF00)
RGB(255,255,000) HEX(#FFFF00)

=> convertor: 
RGB(250,235,215) HEX(#FAEBD7)
RGBA(250,235,215,000) HEX(#FAEBD700)
CMYK(0.000,0.060,0.140,0.020) HEX(#FAEBD7)
HSL(034,0.778,0.912) HEX(#FAEBD7)
!!! RGB TestCase End #>

<# RGBA TestCase Start
=> RGBA original data:
RGBA(075,000,130,000) HEX(#4B008200)

=> single operator:
RGBA(076,001,131,001) HEX(#4C018301)
RGBA(075,000,130,000) HEX(#4B008200)
RGBA(150,000,255,000) HEX(#9600FF00)
RGBA(075,000,127,000) HEX(#4B007F00)
RGBA(000,000,007,000) HEX(#00000700)

=> mixed  operator:
RGBA(167,167,167,167) HEX(#A7A7A7A7)
RGBA(166,166,166,166) HEX(#A6A6A6A6)
RGBA(255,255,255,255) HEX(#FFFFFFFF)
RGBA(127,127,127,127) HEX(#7F7F7F7F)
RGBA(007,007,007,007) HEX(#07070707)

=> use scale:
RGBA(075,075,075,075) HEX(#4B4B4B4B)

=> use divide:
RGBA(037,037,037,037) HEX(#25252525)

=> from hex string (do check):
RGBA(000,000,000,000) HEX(#00000000)

=> from hex string (do not check):
RGBA(128,175,000,224) HEX(#80AF00E0)

=> to hex string:
#80AF00E0

=> from/to RGB:
RGB(128,175,000) HEX(#80AF00)
RGBA(128,175,000,000) HEX(#80AF0000)

=> clear with:
RGBA(255,255,255,255) HEX(#FFFFFFFF)

=> convertor: 
RGBA(250,235,215,000) HEX(#FAEBD700)
RGB(250,235,215) HEX(#FAEBD7)
CMYK(0.000,0.060,0.140,0.020) HEX(#FAEBD7)
HSL(034,0.778,0.912) HEX(#FAEBD7)
!!! RGBA TestCase End #>

<# CMYK TestCase Start 
CMYK(0.000,0.060,0.140,0.020) HEX(#FAEBD7)
RGB(250,235,215) HEX(#FAEBD7)
HSL(034,0.778,0.912) HEX(#FAEBD7)
RGBA(250,235,215,000) HEX(#FAEBD700)
!!! CMYK TestCase END #>

<# HSL TestCase Start 
HSL(034,0.778,0.912) HEX(#FAEBD7)
RGB(250,235,215) HEX(#FAEBD7)
CMYK(0.000,0.060,0.140,0.020) HEX(#FAEBD7)
RGBA(250,235,215,000) HEX(#FAEBD700)
!!! HSL TestCase Start #>

<# HSV TestCase Start
HSV(034,0.140,0.980) HEX(#FAEBD7)
RGB(250,235,215) HEX(#FAEBD7)
CMYK(0.000,0.060,0.140,0.020) HEX(#FAEBD7)
RGBA(250,235,215,000) HEX(#FAEBD700)
!!! HSV TestCase End #>

<# RGB Blend TestCase Start
Red blend Lime = Yellow ? True
Red blend Green = Yellow ? True
!!! RGB Blend TestCase End #>

<# RGBA Blend TestCase Start
RGBA(235,152,080,153) HEX(#EB985099)
RGBA(234,097,124,204) HEX(#EA617CCC)
RGBA(234,104,118,234) HEX(#EA6876EA)
RGBA Blend TestCase End #>

<# Color Random TestCase Start
RGB(135,012,182) HEX(#870CB6)
RGB(211,129,080) HEX(#D38150)
RGBA(203,078,031,087) HEX(#CB4E1F57)
RGBA(120,105,210,236) HEX(#7869D2EC)
CMYK(0.631,0.390,0.383,0.965) HEX(#030505)
CMYK(0.569,0.416,0.865,0.759) HEX(#1A2308)
HSL(345,0.917,0.390) HEX(#BF0836)
HSL(175,0.758,0.220) HEX(#0E635C)
HSV(219,0.490,0.770) HEX(#6486C4)
HSV(174,0.375,0.618) HEX(#629E98)
!!! Color Random TestCase End #>

<# Compare Color With Mode Start
RGB(050,205,050) HEX(#32CD32)
RGBA(050,205,050,088) HEX(#32CD3258)
CMYK(0.756,0.000,0.756,0.196) HEX(#32CD32)
HSL(120,0.608,0.500) HEX(#32CD32)
HSV(120,0.756,0.804) HEX(#32CD32)
[Color Value] LIMEGREEN: HEX(#32CD32)
[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV 
[CampareMode] loose :
c1 == c2 ? True
c1 == c3 ? True
c1 == c4 ? True
c1 == c5 ? True
c2 == c3 ? True
c2 == c4 ? True
c2 == c5 ? True
c3 == c4 ? True
c3 == c5 ? True
c4 == c5 ? True
[Color Value] LIMEGREEN: HEX(#32CD32)
[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV 
[CampareMode] strict :
c1 == c2 ? False
c1 == c3 ? True
c1 == c4 ? True
c1 == c5 ? True
c2 == c3 ? False
c2 == c4 ? False
c2 == c5 ? False
c3 == c4 ? True
c3 == c5 ? True
c4 == c5 ? True
!!! Compare Color With Mode End #>

```

## 三、预定义的色值
```cpp
const std::string INDIGO = "4B0082FF";
const std::string GOLD = "FFD700FF";
const std::string HOTPINK = "FF69B4FF";
const std::string FIREBRICK = "B22222FF";
const std::string INDIANRED = "CD5C5CFF";
const std::string YELLOW = "FFFF00FF";
const std::string MISTYROSE = "FFE4E1FF";
const std::string DARKOLIVEGREEN = "556B2FFF";
const std::string OLIVE = "808000FF";
const std::string DARKSEAGREEN = "8FBC8FFF";
const std::string PINK = "FFC0CBFF";
const std::string TOMATO = "FF6347FF";
const std::string LIGHTCORAL = "F08080FF";
const std::string ORANGERED = "FF4500FF";
const std::string NAVAJOWHITE = "FFDEADFF";
const std::string LIME = "00FF00FF";
const std::string PALEGREEN = "98FB98FF";
const std::string DARKSLATEGREY = "2F4F4FFF";
const std::string GREENYELLOW = "ADFF2FFF";
const std::string BURLYWOOD = "DEB887FF";
const std::string SEASHELL = "FFF5EEFF";
const std::string MEDIUMSPRINGGREEN = "00FA9AFF";
const std::string FUCHSIA = "FF00FFFF";
const std::string PAPAYAWHIP = "FFEFD5FF";
const std::string BLANCHEDALMOND = "FFEBCDFF";
const std::string CHARTREUSE = "7FFF00FF";
const std::string DIMGRAY = "696969FF";
const std::string BLACK = "000000FF";
const std::string PEACHPUFF = "FFDAB9FF";
const std::string SPRINGGREEN = "00FF7FFF";
const std::string AQUAMARINE = "7FFFD4FF";
const std::string WHITE = "FFFFFFFF";
const std::string ORANGE = "FFA500FF";
const std::string LIGHTSALMON = "FFA07AFF";
const std::string DARKSLATEGRAY = "2F4F4FFF";
const std::string BROWN = "A52A2AFF";
const std::string IVORY = "FFFFF0FF";
const std::string DODGERBLUE = "1E90FFFF";
const std::string PERU = "CD853FFF";
const std::string LAWNGREEN = "7CFC00FF";
const std::string CHOCOLATE = "D2691EFF";
const std::string CRIMSON = "DC143CFF";
const std::string FORESTGREEN = "228B22FF";
const std::string DARKGREY = "A9A9A9FF";
const std::string LIGHTSEAGREEN = "20B2AAFF";
const std::string CYAN = "00FFFFFF";
const std::string MINTCREAM = "F5FFFAFF";
const std::string SILVER = "C0C0C0FF";
const std::string ANTIQUEWHITE = "FAEBD7FF";
const std::string MEDIUMORCHID = "BA55D3FF";
const std::string SKYBLUE = "87CEEBFF";
const std::string GRAY = "808080FF";
const std::string DARKTURQUOISE = "00CED1FF";
const std::string GOLDENROD = "DAA520FF";
const std::string DARKGREEN = "006400FF";
const std::string FLORALWHITE = "FFFAF0FF";
const std::string DARKVIOLET = "9400D3FF";
const std::string DARKGRAY = "A9A9A9FF";
const std::string MOCCASIN = "FFE4B5FF";
const std::string SADDLEBROWN = "8B4513FF";
const std::string GREY = "808080FF";
const std::string DARKSLATEBLUE = "483D8BFF";
const std::string LIGHTSKYBLUE = "87CEFAFF";
const std::string LIGHTPINK = "FFB6C1FF";
const std::string MEDIUMVIOLETRED = "C71585FF";
const std::string SLATEGREY = "708090FF";
const std::string RED = "FF0000FF";
const std::string DEEPPINK = "FF1493FF";
const std::string LIMEGREEN = "32CD32FF";
const std::string DARKMAGENTA = "8B008BFF";
const std::string PALEGOLDENROD = "EEE8AAFF";
const std::string PLUM = "DDA0DDFF";
const std::string TURQUOISE = "40E0D0FF";
const std::string LIGHTGREY = "D3D3D3FF";
const std::string LIGHTGOLDENRODYELLOW = "FAFAD2FF";
const std::string DARKGOLDENROD = "B8860BFF";
const std::string LAVENDER = "E6E6FAFF";
const std::string MAROON = "800000FF";
const std::string YELLOWGREEN = "9ACD32FF";
const std::string SANDYBROWN = "F4A460FF";
const std::string THISTLE = "D8BFD8FF";
const std::string VIOLET = "EE82EEFF";
const std::string NAVY = "000080FF";
const std::string MAGENTA = "FF00FFFF";
const std::string DIMGREY = "696969FF";
const std::string TAN = "D2B48CFF";
const std::string ROSYBROWN = "BC8F8FFF";
const std::string OLIVEDRAB = "6B8E23FF";
const std::string BLUE = "0000FFFF";
const std::string LIGHTBLUE = "ADD8E6FF";
const std::string GHOSTWHITE = "F8F8FFFF";
const std::string HONEYDEW = "F0FFF0FF";
const std::string CORNFLOWERBLUE = "6495EDFF";
const std::string SLATEBLUE = "6A5ACDFF";
const std::string LINEN = "FAF0E6FF";
const std::string DARKBLUE = "00008BFF";
const std::string POWDERBLUE = "B0E0E6FF";
const std::string SEAGREEN = "2E8B57FF";
const std::string DARKKHAKI = "BDB76BFF";
const std::string SNOW = "FFFAFAFF";
const std::string SIENNA = "A0522DFF";
const std::string MEDIUMBLUE = "0000CDFF";
const std::string ROYALBLUE = "4169E1FF";
const std::string LIGHTCYAN = "E0FFFFFF";
const std::string GREEN = "008000FF";
const std::string MEDIUMPURPLE = "9370DBFF";
const std::string MIDNIGHTBLUE = "191970FF";
const std::string CORNSILK = "FFF8DCFF";
const std::string PALETURQUOISE = "AFEEEEFF";
const std::string BISQUE = "FFE4C4FF";
const std::string SLATEGRAY = "708090FF";
const std::string DARKCYAN = "008B8BFF";
const std::string KHAKI = "F0E68CFF";
const std::string WHEAT = "F5DEB3FF";
const std::string TEAL = "008080FF";
const std::string DARKORCHID = "9932CCFF";
const std::string DEEPSKYBLUE = "00BFFFFF";
const std::string SALMON = "FA8072FF";
const std::string DARKRED = "8B0000FF";
const std::string STEELBLUE = "4682B4FF";
const std::string PALEVIOLETRED = "DB7093FF";
const std::string LIGHTSLATEGRAY = "778899FF";
const std::string ALICEBLUE = "F0F8FFFF";
const std::string LIGHTSLATEGREY = "778899FF";
const std::string LIGHTGREEN = "90EE90FF";
const std::string ORCHID = "DA70D6FF";
const std::string GAINSBORO = "DCDCDCFF";
const std::string MEDIUMSEAGREEN = "3CB371FF";
const std::string LIGHTGRAY = "D3D3D3FF";
const std::string MEDIUMTURQUOISE = "48D1CCFF";
const std::string LEMONCHIFFON = "FFFACDFF";
const std::string CADETBLUE = "5F9EA0FF";
const std::string LIGHTYELLOW = "FFFFE0FF";
const std::string LAVENDERBLUSH = "FFF0F5FF";
const std::string CORAL = "FF7F50FF";
const std::string PURPLE = "800080FF";
const std::string AQUA = "00FFFFFF";
const std::string WHITESMOKE = "F5F5F5FF";
const std::string MEDIUMSLATEBLUE = "7B68EEFF";
const std::string DARKORANGE = "FF8C00FF";
const std::string MEDIUMAQUAMARINE = "66CDAAFF";
const std::string DARKSALMON = "E9967AFF";
const std::string BEIGE = "F5F5DCFF";
const std::string BLUEVIOLET = "8A2BE2FF";
const std::string AZURE = "F0FFFFFF";
const std::string LIGHTSTEELBLUE = "B0C4DEFF";
const std::string OLDLACE = "FDF5E6FF";
const std::string REBECCAPURPLE = "663399FF";
```
