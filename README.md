# chromatic4cpp
给c++用的色值定义

**测试用例：**
``` cpp
//
//  main.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/1/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include <iostream>
#include "Chromatics/ColorRGBA.hpp"

void RGB_TestCase() {
    RGB case0 = RGB::REBECCAPURPLE;
    
    std::cout << "=> RGB original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15).dump();
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

    std::cout << std::endl << "=> from hex string(do check, this case will fail for invalid hex string):" << std::endl;
    case0.fromhex("80aF*U", true).dump();
    
    std::cout << std::endl << "=> from hex string(don't do check, will always succeed):" << std::endl;
    case0.fromhex("80aF*U", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.tohex() << std::endl;
    
    std::cout << std::endl << "=> from/to RGBA:" << std::endl;
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
}

void RGBA_TestCase() {
    RGBA case0 = RGBA::INDIGO;
    
    std::cout << "=> RGBA original data:" << std::endl;
    case0.dump();
    
    std::cout << std::endl << "=> single operator:" << std::endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15).dump();
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
    
    std::cout << std::endl << "=> from hex string (do check, this case will fail for invalid hex string):" << std::endl;
    case0.fromhex("80aF*UE", true).dump();
    
    std::cout << std::endl << "=> from hex string (don't do check, will always succeed):" << std::endl;
    case0.fromhex("80aF*UE", false).dump();
    
    std::cout << std::endl << "=> to hex string:" << std::endl;
    std::cout << case0.tohex() << std::endl;
    
    std::cout << std::endl << "=> from/to RGB:" << std::endl;
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    std::cout << std::endl << "=> clear with:" << std::endl;
    case0.clear(255).dump();
}

int main() {
    RGB_TestCase();
    RGBA_TestCase();
}

```

**输出：**

``` plaintext
=> RGB original data:
RGB(102,051,153), HEX(663399)

=> single operator:
RGB(103,052,154), HEX(67349a)
RGB(102,051,153), HEX(663399)
RGB(204,102,255), HEX(cc66ff)
RGB(102,051,127), HEX(66337f)
RGB(012,006,007), HEX(0c0607)

=> mixed  operator:
RGB(167,167,167), HEX(a7a7a7)
RGB(166,166,166), HEX(a6a6a6)
RGB(255,255,255), HEX(ffffff)
RGB(127,127,127), HEX(7f7f7f)
RGB(007,007,007), HEX(070707)

=> use scale:
RGB(075,075,075), HEX(4b4b4b)

=> use divide:
RGB(037,037,037), HEX(252525)

=> from hex string(do check, this case will fail for invalid hex string):
RGB(000,000,000), HEX(000000)

=> from hex string(don't do check, will always succeed):
RGB(128,175,000), HEX(80af00)

=> to hex string:
80af00

=> from/to RGBA:
RGBA(128,175,000,255), HEX(80af00ff)
RGB(128,175,000), HEX(80af00)

=> clear with:
RGB(255,255,255), HEX(ffffff)
=> RGBA original data:
RGBA(075,000,130,255), HEX(4b0082ff)

=> single operator:
RGBA(076,001,131,255), HEX(4c0183ff)
RGBA(075,000,130,254), HEX(4b0082fe)
RGBA(150,000,255,255), HEX(9600ffff)
RGBA(075,000,127,127), HEX(4b007f7f)
RGBA(000,000,007,007), HEX(00000707)

=> mixed  operator:
RGBA(167,167,167,167), HEX(a7a7a7a7)
RGBA(166,166,166,166), HEX(a6a6a6a6)
RGBA(255,255,255,255), HEX(ffffffff)
RGBA(127,127,127,127), HEX(7f7f7f7f)
RGBA(007,007,007,007), HEX(07070707)

=> use scale:
RGBA(075,075,075,075), HEX(4b4b4b4b)

=> use divide:
RGBA(037,037,037,037), HEX(25252525)

=> from hex string (do check, this case will fail for invalid hex string):
RGBA(000,000,000,000), HEX(00000000)

=> from hex string (don't do check, will always succeed):
RGBA(128,175,000,224), HEX(80af00e0)

=> to hex string:
80af00e0

=> from/to RGB:
RGB(128,175,000), HEX(80af00)
RGBA(128,175,000,255), HEX(80af00ff)

=> clear with:
RGBA(255,255,255,255), HEX(ffffffff)
Program ended with exit code: 0
```

**预定义的色值：**
```cpp
const RGB RGB::INDIGO = RGB("4B0082");
const RGB RGB::GOLD = RGB("FFD700");
const RGB RGB::HOTPINK = RGB("FF69B4");
const RGB RGB::FIREBRICK = RGB("B22222");
const RGB RGB::INDIANRED = RGB("CD5C5C");
const RGB RGB::YELLOW = RGB("FFFF00");
const RGB RGB::MISTYROSE = RGB("FFE4E1");
const RGB RGB::DARKOLIVEGREEN = RGB("556B2F");
const RGB RGB::OLIVE = RGB("808000");
const RGB RGB::DARKSEAGREEN = RGB("8FBC8F");
const RGB RGB::PINK = RGB("FFC0CB");
const RGB RGB::TOMATO = RGB("FF6347");
const RGB RGB::LIGHTCORAL = RGB("F08080");
const RGB RGB::ORANGERED = RGB("FF4500");
const RGB RGB::NAVAJOWHITE = RGB("FFDEAD");
const RGB RGB::LIME = RGB("00FF00");
const RGB RGB::PALEGREEN = RGB("98FB98");
const RGB RGB::DARKSLATEGREY = RGB("2F4F4F");
const RGB RGB::GREENYELLOW = RGB("ADFF2F");
const RGB RGB::BURLYWOOD = RGB("DEB887");
const RGB RGB::SEASHELL = RGB("FFF5EE");
const RGB RGB::MEDIUMSPRINGGREEN = RGB("00FA9A");
const RGB RGB::FUCHSIA = RGB("FF00FF");
const RGB RGB::PAPAYAWHIP = RGB("FFEFD5");
const RGB RGB::BLANCHEDALMOND = RGB("FFEBCD");
const RGB RGB::CHARTREUSE = RGB("7FFF00");
const RGB RGB::DIMGRAY = RGB("696969");
const RGB RGB::BLACK = RGB("000000");
const RGB RGB::PEACHPUFF = RGB("FFDAB9");
const RGB RGB::SPRINGGREEN = RGB("00FF7F");
const RGB RGB::AQUAMARINE = RGB("7FFFD4");
const RGB RGB::WHITE = RGB("FFFFFF");
const RGB RGB::ORANGE = RGB("FFA500");
const RGB RGB::LIGHTSALMON = RGB("FFA07A");
const RGB RGB::DARKSLATEGRAY = RGB("2F4F4F");
const RGB RGB::BROWN = RGB("A52A2A");
const RGB RGB::IVORY = RGB("FFFFF0");
const RGB RGB::DODGERBLUE = RGB("1E90FF");
const RGB RGB::PERU = RGB("CD853F");
const RGB RGB::LAWNGREEN = RGB("7CFC00");
const RGB RGB::CHOCOLATE = RGB("D2691E");
const RGB RGB::CRIMSON = RGB("DC143C");
const RGB RGB::FORESTGREEN = RGB("228B22");
const RGB RGB::DARKGREY = RGB("A9A9A9");
const RGB RGB::LIGHTSEAGREEN = RGB("20B2AA");
const RGB RGB::CYAN = RGB("00FFFF");
const RGB RGB::MINTCREAM = RGB("F5FFFA");
const RGB RGB::SILVER = RGB("C0C0C0");
const RGB RGB::ANTIQUEWHITE = RGB("FAEBD7");
const RGB RGB::MEDIUMORCHID = RGB("BA55D3");
const RGB RGB::SKYBLUE = RGB("87CEEB");
const RGB RGB::GRAY = RGB("808080");
const RGB RGB::DARKTURQUOISE = RGB("00CED1");
const RGB RGB::GOLDENROD = RGB("DAA520");
const RGB RGB::DARKGREEN = RGB("006400");
const RGB RGB::FLORALWHITE = RGB("FFFAF0");
const RGB RGB::DARKVIOLET = RGB("9400D3");
const RGB RGB::DARKGRAY = RGB("A9A9A9");
const RGB RGB::MOCCASIN = RGB("FFE4B5");
const RGB RGB::SADDLEBROWN = RGB("8B4513");
const RGB RGB::GREY = RGB("808080");
const RGB RGB::DARKSLATEBLUE = RGB("483D8B");
const RGB RGB::LIGHTSKYBLUE = RGB("87CEFA");
const RGB RGB::LIGHTPINK = RGB("FFB6C1");
const RGB RGB::MEDIUMVIOLETRED = RGB("C71585");
const RGB RGB::SLATEGREY = RGB("708090");
const RGB RGB::RED = RGB("FF0000");
const RGB RGB::DEEPPINK = RGB("FF1493");
const RGB RGB::LIMEGREEN = RGB("32CD32");
const RGB RGB::DARKMAGENTA = RGB("8B008B");
const RGB RGB::PALEGOLDENROD = RGB("EEE8AA");
const RGB RGB::PLUM = RGB("DDA0DD");
const RGB RGB::TURQUOISE = RGB("40E0D0");
const RGB RGB::LIGHTGREY = RGB("D3D3D3");
const RGB RGB::LIGHTGOLDENRODYELLOW = RGB("FAFAD2");
const RGB RGB::DARKGOLDENROD = RGB("B8860B");
const RGB RGB::LAVENDER = RGB("E6E6FA");
const RGB RGB::MAROON = RGB("800000");
const RGB RGB::YELLOWGREEN = RGB("9ACD32");
const RGB RGB::SANDYBROWN = RGB("F4A460");
const RGB RGB::THISTLE = RGB("D8BFD8");
const RGB RGB::VIOLET = RGB("EE82EE");
const RGB RGB::NAVY = RGB("000080");
const RGB RGB::MAGENTA = RGB("FF00FF");
const RGB RGB::DIMGREY = RGB("696969");
const RGB RGB::TAN = RGB("D2B48C");
const RGB RGB::ROSYBROWN = RGB("BC8F8F");
const RGB RGB::OLIVEDRAB = RGB("6B8E23");
const RGB RGB::BLUE = RGB("0000FF");
const RGB RGB::LIGHTBLUE = RGB("ADD8E6");
const RGB RGB::GHOSTWHITE = RGB("F8F8FF");
const RGB RGB::HONEYDEW = RGB("F0FFF0");
const RGB RGB::CORNFLOWERBLUE = RGB("6495ED");
const RGB RGB::SLATEBLUE = RGB("6A5ACD");
const RGB RGB::LINEN = RGB("FAF0E6");
const RGB RGB::DARKBLUE = RGB("00008B");
const RGB RGB::POWDERBLUE = RGB("B0E0E6");
const RGB RGB::SEAGREEN = RGB("2E8B57");
const RGB RGB::DARKKHAKI = RGB("BDB76B");
const RGB RGB::SNOW = RGB("FFFAFA");
const RGB RGB::SIENNA = RGB("A0522D");
const RGB RGB::MEDIUMBLUE = RGB("0000CD");
const RGB RGB::ROYALBLUE = RGB("4169E1");
const RGB RGB::LIGHTCYAN = RGB("E0FFFF");
const RGB RGB::GREEN = RGB("008000");
const RGB RGB::MEDIUMPURPLE = RGB("9370DB");
const RGB RGB::MIDNIGHTBLUE = RGB("191970");
const RGB RGB::CORNSILK = RGB("FFF8DC");
const RGB RGB::PALETURQUOISE = RGB("AFEEEE");
const RGB RGB::BISQUE = RGB("FFE4C4");
const RGB RGB::SLATEGRAY = RGB("708090");
const RGB RGB::DARKCYAN = RGB("008B8B");
const RGB RGB::KHAKI = RGB("F0E68C");
const RGB RGB::WHEAT = RGB("F5DEB3");
const RGB RGB::TEAL = RGB("008080");
const RGB RGB::DARKORCHID = RGB("9932CC");
const RGB RGB::DEEPSKYBLUE = RGB("00BFFF");
const RGB RGB::SALMON = RGB("FA8072");
const RGB RGB::DARKRED = RGB("8B0000");
const RGB RGB::STEELBLUE = RGB("4682B4");
const RGB RGB::PALEVIOLETRED = RGB("DB7093");
const RGB RGB::LIGHTSLATEGRAY = RGB("778899");
const RGB RGB::ALICEBLUE = RGB("F0F8FF");
const RGB RGB::LIGHTSLATEGREY = RGB("778899");
const RGB RGB::LIGHTGREEN = RGB("90EE90");
const RGB RGB::ORCHID = RGB("DA70D6");
const RGB RGB::GAINSBORO = RGB("DCDCDC");
const RGB RGB::MEDIUMSEAGREEN = RGB("3CB371");
const RGB RGB::LIGHTGRAY = RGB("D3D3D3");
const RGB RGB::MEDIUMTURQUOISE = RGB("48D1CC");
const RGB RGB::LEMONCHIFFON = RGB("FFFACD");
const RGB RGB::CADETBLUE = RGB("5F9EA0");
const RGB RGB::LIGHTYELLOW = RGB("FFFFE0");
const RGB RGB::LAVENDERBLUSH = RGB("FFF0F5");
const RGB RGB::CORAL = RGB("FF7F50");
const RGB RGB::PURPLE = RGB("800080");
const RGB RGB::AQUA = RGB("00FFFF");
const RGB RGB::WHITESMOKE = RGB("F5F5F5");
const RGB RGB::MEDIUMSLATEBLUE = RGB("7B68EE");
const RGB RGB::DARKORANGE = RGB("FF8C00");
const RGB RGB::MEDIUMAQUAMARINE = RGB("66CDAA");
const RGB RGB::DARKSALMON = RGB("E9967A");
const RGB RGB::BEIGE = RGB("F5F5DC");
const RGB RGB::BLUEVIOLET = RGB("8A2BE2");
const RGB RGB::AZURE = RGB("F0FFFF");
const RGB RGB::LIGHTSTEELBLUE = RGB("B0C4DE");
const RGB RGB::OLDLACE = RGB("FDF5E6");
const RGB RGB::REBECCAPURPLE = RGB("663399");

const RGBA RGBA::INDIGO = RGBA("4B0082FF");
const RGBA RGBA::GOLD = RGBA("FFD700FF");
const RGBA RGBA::HOTPINK = RGBA("FF69B4FF");
const RGBA RGBA::FIREBRICK = RGBA("B22222FF");
const RGBA RGBA::INDIANRED = RGBA("CD5C5CFF");
const RGBA RGBA::YELLOW = RGBA("FFFF00FF");
const RGBA RGBA::MISTYROSE = RGBA("FFE4E1FF");
const RGBA RGBA::DARKOLIVEGREEN = RGBA("556B2FFF");
const RGBA RGBA::OLIVE = RGBA("808000FF");
const RGBA RGBA::DARKSEAGREEN = RGBA("8FBC8FFF");
const RGBA RGBA::PINK = RGBA("FFC0CBFF");
const RGBA RGBA::TOMATO = RGBA("FF6347FF");
const RGBA RGBA::LIGHTCORAL = RGBA("F08080FF");
const RGBA RGBA::ORANGERED = RGBA("FF4500FF");
const RGBA RGBA::NAVAJOWHITE = RGBA("FFDEADFF");
const RGBA RGBA::LIME = RGBA("00FF00FF");
const RGBA RGBA::PALEGREEN = RGBA("98FB98FF");
const RGBA RGBA::DARKSLATEGREY = RGBA("2F4F4FFF");
const RGBA RGBA::GREENYELLOW = RGBA("ADFF2FFF");
const RGBA RGBA::BURLYWOOD = RGBA("DEB887FF");
const RGBA RGBA::SEASHELL = RGBA("FFF5EEFF");
const RGBA RGBA::MEDIUMSPRINGGREEN = RGBA("00FA9AFF");
const RGBA RGBA::FUCHSIA = RGBA("FF00FFFF");
const RGBA RGBA::PAPAYAWHIP = RGBA("FFEFD5FF");
const RGBA RGBA::BLANCHEDALMOND = RGBA("FFEBCDFF");
const RGBA RGBA::CHARTREUSE = RGBA("7FFF00FF");
const RGBA RGBA::DIMGRAY = RGBA("696969FF");
const RGBA RGBA::BLACK = RGBA("000000FF");
const RGBA RGBA::PEACHPUFF = RGBA("FFDAB9FF");
const RGBA RGBA::SPRINGGREEN = RGBA("00FF7FFF");
const RGBA RGBA::AQUAMARINE = RGBA("7FFFD4FF");
const RGBA RGBA::WHITE = RGBA("FFFFFFFF");
const RGBA RGBA::ORANGE = RGBA("FFA500FF");
const RGBA RGBA::LIGHTSALMON = RGBA("FFA07AFF");
const RGBA RGBA::DARKSLATEGRAY = RGBA("2F4F4FFF");
const RGBA RGBA::BROWN = RGBA("A52A2AFF");
const RGBA RGBA::IVORY = RGBA("FFFFF0FF");
const RGBA RGBA::DODGERBLUE = RGBA("1E90FFFF");
const RGBA RGBA::PERU = RGBA("CD853FFF");
const RGBA RGBA::LAWNGREEN = RGBA("7CFC00FF");
const RGBA RGBA::CHOCOLATE = RGBA("D2691EFF");
const RGBA RGBA::CRIMSON = RGBA("DC143CFF");
const RGBA RGBA::FORESTGREEN = RGBA("228B22FF");
const RGBA RGBA::DARKGREY = RGBA("A9A9A9FF");
const RGBA RGBA::LIGHTSEAGREEN = RGBA("20B2AAFF");
const RGBA RGBA::CYAN = RGBA("00FFFFFF");
const RGBA RGBA::MINTCREAM = RGBA("F5FFFAFF");
const RGBA RGBA::SILVER = RGBA("C0C0C0FF");
const RGBA RGBA::ANTIQUEWHITE = RGBA("FAEBD7FF");
const RGBA RGBA::MEDIUMORCHID = RGBA("BA55D3FF");
const RGBA RGBA::SKYBLUE = RGBA("87CEEBFF");
const RGBA RGBA::GRAY = RGBA("808080FF");
const RGBA RGBA::DARKTURQUOISE = RGBA("00CED1FF");
const RGBA RGBA::GOLDENROD = RGBA("DAA520FF");
const RGBA RGBA::DARKGREEN = RGBA("006400FF");
const RGBA RGBA::FLORALWHITE = RGBA("FFFAF0FF");
const RGBA RGBA::DARKVIOLET = RGBA("9400D3FF");
const RGBA RGBA::DARKGRAY = RGBA("A9A9A9FF");
const RGBA RGBA::MOCCASIN = RGBA("FFE4B5FF");
const RGBA RGBA::SADDLEBROWN = RGBA("8B4513FF");
const RGBA RGBA::GREY = RGBA("808080FF");
const RGBA RGBA::DARKSLATEBLUE = RGBA("483D8BFF");
const RGBA RGBA::LIGHTSKYBLUE = RGBA("87CEFAFF");
const RGBA RGBA::LIGHTPINK = RGBA("FFB6C1FF");
const RGBA RGBA::MEDIUMVIOLETRED = RGBA("C71585FF");
const RGBA RGBA::SLATEGREY = RGBA("708090FF");
const RGBA RGBA::RED = RGBA("FF0000FF");
const RGBA RGBA::DEEPPINK = RGBA("FF1493FF");
const RGBA RGBA::LIMEGREEN = RGBA("32CD32FF");
const RGBA RGBA::DARKMAGENTA = RGBA("8B008BFF");
const RGBA RGBA::PALEGOLDENROD = RGBA("EEE8AAFF");
const RGBA RGBA::PLUM = RGBA("DDA0DDFF");
const RGBA RGBA::TURQUOISE = RGBA("40E0D0FF");
const RGBA RGBA::LIGHTGREY = RGBA("D3D3D3FF");
const RGBA RGBA::LIGHTGOLDENRODYELLOW = RGBA("FAFAD2FF");
const RGBA RGBA::DARKGOLDENROD = RGBA("B8860BFF");
const RGBA RGBA::LAVENDER = RGBA("E6E6FAFF");
const RGBA RGBA::MAROON = RGBA("800000FF");
const RGBA RGBA::YELLOWGREEN = RGBA("9ACD32FF");
const RGBA RGBA::SANDYBROWN = RGBA("F4A460FF");
const RGBA RGBA::THISTLE = RGBA("D8BFD8FF");
const RGBA RGBA::VIOLET = RGBA("EE82EEFF");
const RGBA RGBA::NAVY = RGBA("000080FF");
const RGBA RGBA::MAGENTA = RGBA("FF00FFFF");
const RGBA RGBA::DIMGREY = RGBA("696969FF");
const RGBA RGBA::TAN = RGBA("D2B48CFF");
const RGBA RGBA::ROSYBROWN = RGBA("BC8F8FFF");
const RGBA RGBA::OLIVEDRAB = RGBA("6B8E23FF");
const RGBA RGBA::BLUE = RGBA("0000FFFF");
const RGBA RGBA::LIGHTBLUE = RGBA("ADD8E6FF");
const RGBA RGBA::GHOSTWHITE = RGBA("F8F8FFFF");
const RGBA RGBA::HONEYDEW = RGBA("F0FFF0FF");
const RGBA RGBA::CORNFLOWERBLUE = RGBA("6495EDFF");
const RGBA RGBA::SLATEBLUE = RGBA("6A5ACDFF");
const RGBA RGBA::LINEN = RGBA("FAF0E6FF");
const RGBA RGBA::DARKBLUE = RGBA("00008BFF");
const RGBA RGBA::POWDERBLUE = RGBA("B0E0E6FF");
const RGBA RGBA::SEAGREEN = RGBA("2E8B57FF");
const RGBA RGBA::DARKKHAKI = RGBA("BDB76BFF");
const RGBA RGBA::SNOW = RGBA("FFFAFAFF");
const RGBA RGBA::SIENNA = RGBA("A0522DFF");
const RGBA RGBA::MEDIUMBLUE = RGBA("0000CDFF");
const RGBA RGBA::ROYALBLUE = RGBA("4169E1FF");
const RGBA RGBA::LIGHTCYAN = RGBA("E0FFFFFF");
const RGBA RGBA::GREEN = RGBA("008000FF");
const RGBA RGBA::MEDIUMPURPLE = RGBA("9370DBFF");
const RGBA RGBA::MIDNIGHTBLUE = RGBA("191970FF");
const RGBA RGBA::CORNSILK = RGBA("FFF8DCFF");
const RGBA RGBA::PALETURQUOISE = RGBA("AFEEEEFF");
const RGBA RGBA::BISQUE = RGBA("FFE4C4FF");
const RGBA RGBA::SLATEGRAY = RGBA("708090FF");
const RGBA RGBA::DARKCYAN = RGBA("008B8BFF");
const RGBA RGBA::KHAKI = RGBA("F0E68CFF");
const RGBA RGBA::WHEAT = RGBA("F5DEB3FF");
const RGBA RGBA::TEAL = RGBA("008080FF");
const RGBA RGBA::DARKORCHID = RGBA("9932CCFF");
const RGBA RGBA::DEEPSKYBLUE = RGBA("00BFFFFF");
const RGBA RGBA::SALMON = RGBA("FA8072FF");
const RGBA RGBA::DARKRED = RGBA("8B0000FF");
const RGBA RGBA::STEELBLUE = RGBA("4682B4FF");
const RGBA RGBA::PALEVIOLETRED = RGBA("DB7093FF");
const RGBA RGBA::LIGHTSLATEGRAY = RGBA("778899FF");
const RGBA RGBA::ALICEBLUE = RGBA("F0F8FFFF");
const RGBA RGBA::LIGHTSLATEGREY = RGBA("778899FF");
const RGBA RGBA::LIGHTGREEN = RGBA("90EE90FF");
const RGBA RGBA::ORCHID = RGBA("DA70D6FF");
const RGBA RGBA::GAINSBORO = RGBA("DCDCDCFF");
const RGBA RGBA::MEDIUMSEAGREEN = RGBA("3CB371FF");
const RGBA RGBA::LIGHTGRAY = RGBA("D3D3D3FF");
const RGBA RGBA::MEDIUMTURQUOISE = RGBA("48D1CCFF");
const RGBA RGBA::LEMONCHIFFON = RGBA("FFFACDFF");
const RGBA RGBA::CADETBLUE = RGBA("5F9EA0FF");
const RGBA RGBA::LIGHTYELLOW = RGBA("FFFFE0FF");
const RGBA RGBA::LAVENDERBLUSH = RGBA("FFF0F5FF");
const RGBA RGBA::CORAL = RGBA("FF7F50FF");
const RGBA RGBA::PURPLE = RGBA("800080FF");
const RGBA RGBA::AQUA = RGBA("00FFFFFF");
const RGBA RGBA::WHITESMOKE = RGBA("F5F5F5FF");
const RGBA RGBA::MEDIUMSLATEBLUE = RGBA("7B68EEFF");
const RGBA RGBA::DARKORANGE = RGBA("FF8C00FF");
const RGBA RGBA::MEDIUMAQUAMARINE = RGBA("66CDAAFF");
const RGBA RGBA::DARKSALMON = RGBA("E9967AFF");
const RGBA RGBA::BEIGE = RGBA("F5F5DCFF");
const RGBA RGBA::BLUEVIOLET = RGBA("8A2BE2FF");
const RGBA RGBA::AZURE = RGBA("F0FFFFFF");
const RGBA RGBA::LIGHTSTEELBLUE = RGBA("B0C4DEFF");
const RGBA RGBA::OLDLACE = RGBA("FDF5E6FF");
const RGBA RGBA::REBECCAPURPLE = RGBA("663399FF");
```
