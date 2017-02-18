# chromatic4cpp
> chromatic4cpp 致力于为 c++ 的色值操作提供便利，目前仅支持 RGB 和 RGBA 两种色值类型。
chromatic4cpp 主要特点有：
- 支持色值之间的运算（加、减、乘、除、取余、等于、不等于）；
- 支持十六进制色值与RGB、RGBA之间的转换；
- 提供了丰富的RGB、RGBA预定义色值；
chromatic4cpp 的主要接口如下：
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


**测试用例：**
``` cpp
#include <iostream>
#include "Chromatics/Chromatics.hpp"

void RGB_TestCase() {
    RGB case0 = RGB(Chromatic::REBECCAPURPLE);
    
    std::cout << "==================== RGB TestCase Start ===================" << std::endl;
    
    std::cout << "=> RGB original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    std::cout << std::endl << "=> mixed  operator:" << std::endl;
    case0.clear(166);
    (case0+RGB(1,1,1)).dump();
    (case0-RGB(1,1,1)).dump();
    (case0*RGB(2,2,2)).dump();
    (case0/RGB(2,2,2)).dump();
    (case0%RGB(15,15,15)).dump();
    
    std::cout << std::endl << "=> use scale:" << std::endl;
    (case0.scale(10.8).dump());
    
    std::cout << std::endl << "=> use divide:" << std::endl;
    (case0.divide(2).dump());

    std::cout << std::endl << "=> from hex string(do check):" << std::endl;
    case0.fromHEX("80aF*U", true).dump();
    
    std::cout << std::endl << "=> from hex string(do not check):" << std::endl;
    case0.fromHEX("80aF*U", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.toHEX() << std::endl;
    
    std::cout << std::endl << "=> from/to RGBA:" << std::endl;
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
    
    std::cout << std::endl << "=> RED + LIME = YELLOW : " << std::endl;
    (RGB(Chromatic::RED) + RGB(Chromatic::LIME)).dump();
    RGB(Chromatic::YELLOW).dump();
    
    std::cout << std::endl << "=> convertor: " << std::endl;
    RGB rgb = RGB().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    rgb.toRGBA().dump();
    rgb.toCMYK().dump();
    rgb.toHSL().dump();
    
    std::cout << "==================== RGB TestCase End =====================" << std::endl << std::endl;
}


void RGBA_TestCase() {
    std::cout << "=================== RGBA TestCase Start ===================" << std::endl;
    RGBA case0 = RGBA(Chromatic::INDIGO);
    
    std::cout << "=> RGBA original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    std::cout << std::endl << "=> mixed  operator:" << std::endl;
    case0.clear(166);
    (case0+RGBA(1,1,1,1)).dump();
    (case0-RGBA(1,1,1,1)).dump();
    (case0*RGBA(2,2,2,2)).dump();
    (case0/RGBA(2,2,2,2)).dump();
    (case0%RGBA(15,15,15,15)).dump();
    
    std::cout << std::endl << "=> use scale:" << std::endl;
    (case0.scale(10.8).dump());
    
    std::cout << std::endl << "=> use divide:" << std::endl;
    (case0.divide(2).dump());
    
    std::cout << std::endl << "=> from hex string (do check):" << std::endl;
    case0.fromHEX("80aF*UE", true).dump();
    
    std::cout << std::endl << "=> from hex string (do not check):" << std::endl;
    case0.fromHEX("80aF*UE", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.toHEX() << std::endl;
    
    std::cout << std::endl << "=> from/to RGB:" << std::endl;
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
    
    std::cout << std::endl << "=> convertor: " << std::endl;
    RGBA rgba = RGBA().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    rgba.toRGB().dump();
    rgba.toCMYK().dump();
    rgba.toHSL().dump();
    std::cout << "=================== RGBA TestCase End =====================" << std::endl << std::endl;
}

void CMYK_TestCase() {
    std::cout << "=================== CMYK TestCase Start ===================" << std::endl;
    CMYK cmyk = CMYK().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    cmyk.toRGB().dump();
    cmyk.toHSL().dump();
    cmyk.toRGBA().dump();
    std::cout << "=================== CMYK TestCase END =====================" << std::endl << std::endl;
}

void HSL_TestCase() {
    std::cout << "==================== HSL TestCase Start ===================" << std::endl;
    HSL hsl = HSL().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    hsl.toRGB().dump();
    hsl.toCMYK().dump();
    hsl.toRGBA().dump();
    std::cout << "==================== HSL TestCase Start ===================" << std::endl << std::endl;
}

void HSV_TestCase() {
    std::cout << "==================== HSL TestCase Start ===================" << std::endl;
    HSV hsv = HSV().fromHEX(Chromatic::ANTIQUEWHITE).dump();
    hsv.toRGB().dump();
    hsv.toCMYK().dump();
    hsv.toRGBA().dump();
    std::cout << "==================== HSL TestCase Start ===================" << std::endl << std::endl;
}

int main() {
    RGB_TestCase();
    RGBA_TestCase();
    CMYK_TestCase();
    HSL_TestCase();
    HSV_TestCase();
}



```

## 输出

``` zsh
==================== RGB TestCase Start ===================
=> RGB original data:
RGB(102,051,153) HEX(663399)

=> single operator:
RGB(103,052,154) HEX(67349a)
RGB(102,051,153) HEX(663399)
RGB(204,102,255) HEX(cc66ff)
RGB(102,051,127) HEX(66337f)
RGB(012,006,007) HEX(0c0607)

=> mixed  operator:
RGB(167,167,167) HEX(a7a7a7)
RGB(166,166,166) HEX(a6a6a6)
RGB(255,255,255) HEX(ffffff)
RGB(127,127,127) HEX(7f7f7f)
RGB(007,007,007) HEX(070707)

=> use scale:
RGB(075,075,075) HEX(4b4b4b)

=> use divide:
RGB(037,037,037) HEX(252525)

=> from hex string(do check):
RGB(000,000,000) HEX(000000)

=> from hex string(do not check):
RGB(128,175,000) HEX(80af00)

=> to hex string:
80af00

=> from/to RGBA:
RGBA(128,175,000,255) HEX(80af00ff)
RGB(128,175,000) HEX(80af00)

=> clear with:
RGB(255,255,255) HEX(ffffff)

=> RED + LIME = YELLOW : 
RGB(255,255,000) HEX(ffff00)
RGB(255,255,000) HEX(ffff00)

=> convertor: 
RGB(250,235,215) HEX(faebd7)
RGBA(250,235,215,255) HEX(faebd7ff)
CMYK(0.000,0.060,0.140,0.020) HEX(faebd7)
HSL(034,0.778,0.912) HEX(faebd7)
==================== RGB TestCase End =====================

=================== RGBA TestCase Start ===================
=> RGBA original data:
RGBA(075,000,130,255) HEX(4b0082ff)

=> single operator:
RGBA(076,001,131,255) HEX(4c0183ff)
RGBA(075,000,130,254) HEX(4b0082fe)
RGBA(150,000,255,255) HEX(9600ffff)
RGBA(075,000,127,127) HEX(4b007f7f)
RGBA(000,000,007,007) HEX(00000707)

=> mixed  operator:
RGBA(167,167,167,167) HEX(a7a7a7a7)
RGBA(166,166,166,166) HEX(a6a6a6a6)
RGBA(255,255,255,255) HEX(ffffffff)
RGBA(127,127,127,127) HEX(7f7f7f7f)
RGBA(007,007,007,007) HEX(07070707)

=> use scale:
RGBA(075,075,075,075) HEX(4b4b4b4b)

=> use divide:
RGBA(037,037,037,037) HEX(25252525)

=> from hex string (do check):
RGBA(000,000,000,000) HEX(00000000)

=> from hex string (do not check):
RGBA(128,175,000,224) HEX(80af00e0)

=> to hex string:
80af00e0

=> from/to RGB:
RGB(128,175,000) HEX(80af00)
RGBA(128,175,000,255) HEX(80af00ff)

=> clear with:
RGBA(255,255,255,255) HEX(ffffffff)

=> convertor: 
RGBA(250,235,215,255) HEX(faebd7ff)
RGB(250,235,215) HEX(faebd7)
CMYK(0.000,0.060,0.140,0.020) HEX(faebd7)
HSL(034,0.778,0.912) HEX(faebd7)
=================== RGBA TestCase End =====================

=================== CMYK TestCase Start ===================
CMYK(0.000,0.060,0.140,0.020) HEX(faebd7)
RGB(250,235,215) HEX(faebd7)
HSL(034,0.778,0.912) HEX(faebd7)
RGBA(250,235,215,255) HEX(faebd7ff)
=================== CMYK TestCase END =====================

==================== HSL TestCase Start ===================
HSL(034,0.778,0.912) HEX(faebd7)
RGB(250,235,215) HEX(faebd7)
CMYK(0.000,0.060,0.140,0.020) HEX(faebd7)
RGBA(250,235,215,255) HEX(faebd7ff)
==================== HSL TestCase Start ===================

==================== HSL TestCase Start ===================
HSV(034,0.140,0.980) HEX(faebd7)
RGB(250,235,215) HEX(faebd7)
CMYK(0.000,0.060,0.140,0.020) HEX(faebd7)
RGBA(250,235,215,255) HEX(faebd7ff)
==================== HSL TestCase Start ===================

Program ended with exit code: 0
```

## 预定义的色值
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
