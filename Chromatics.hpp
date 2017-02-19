//
//  Chromatics.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/18.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatics_hpp
#define Chromatics_hpp

#include <iostream>
#include "BaseMath.hpp"
#include "BaseTypes.hpp"
#include "ColorRGB.hpp"
#include "ColorRGBA.hpp"
#include "ColorCMYK.hpp"
#include "ColorHSL.hpp"
#include "ColorHSV.hpp"
using namespace std;

template<class T> int getArrayLen(T& array)
{//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
    return (sizeof(array) / sizeof(array[0]));
}

namespace Chromatic {
    const string INDIGO                = "4B0082";
    const string GOLD                  = "FFD700";
    const string HOTPINK               = "FF69B4";
    const string FIREBRICK             = "B22222";
    const string INDIANRED             = "CD5C5C";
    const string YELLOW                = "FFFF00";
    const string MISTYROSE             = "FFE4E1";
    const string DARKOLIVEGREEN        = "556B2F";
    const string OLIVE                 = "808000";
    const string DARKSEAGREEN          = "8FBC8F";
    const string PINK                  = "FFC0CB";
    const string TOMATO                = "FF6347";
    const string LIGHTCORAL            = "F08080";
    const string ORANGERED             = "FF4500";
    const string NAVAJOWHITE           = "FFDEAD";
    const string LIME                  = "00FF00";
    const string PALEGREEN             = "98FB98";
    const string DARKSLATEGREY         = "2F4F4F";
    const string GREENYELLOW           = "ADFF2F";
    const string BURLYWOOD             = "DEB887";
    const string SEASHELL              = "FFF5EE";
    const string MEDIUMSPRINGGREEN     = "00FA9A";
    const string FUCHSIA               = "FF00FF";
    const string PAPAYAWHIP            = "FFEFD5";
    const string BLANCHEDALMOND        = "FFEBCD";
    const string CHARTREUSE            = "7FFF00";
    const string DIMGRAY               = "696969";
    const string BLACK                 = "000000";
    const string PEACHPUFF             = "FFDAB9";
    const string SPRINGGREEN           = "00FF7F";
    const string AQUAMARINE            = "7FFFD4";
    const string WHITE                 = "FFFFFF";
    const string ORANGE                = "FFA500";
    const string LIGHTSALMON           = "FFA07A";
    const string DARKSLATEGRAY         = "2F4F4F";
    const string BROWN                 = "A52A2A";
    const string IVORY                 = "FFFFF0";
    const string DODGERBLUE            = "1E90FF";
    const string PERU                  = "CD853F";
    const string LAWNGREEN             = "7CFC00";
    const string CHOCOLATE             = "D2691E";
    const string CRIMSON               = "DC143C";
    const string FORESTGREEN           = "228B22";
    const string DARKGREY              = "A9A9A9";
    const string LIGHTSEAGREEN         = "20B2AA";
    const string CYAN                  = "00FFFF";
    const string MINTCREAM             = "F5FFFA";
    const string SILVER                = "C0C0C0";
    const string ANTIQUEWHITE          = "FAEBD7";
    const string MEDIUMORCHID          = "BA55D3";
    const string SKYBLUE               = "87CEEB";
    const string GRAY                  = "808080";
    const string DARKTURQUOISE         = "00CED1";
    const string GOLDENROD             = "DAA520";
    const string DARKGREEN             = "006400";
    const string FLORALWHITE           = "FFFAF0";
    const string DARKVIOLET            = "9400D3";
    const string DARKGRAY              = "A9A9A9";
    const string MOCCASIN              = "FFE4B5";
    const string SADDLEBROWN           = "8B4513";
    const string GREY                  = "808080";
    const string DARKSLATEBLUE         = "483D8B";
    const string LIGHTSKYBLUE          = "87CEFA";
    const string LIGHTPINK             = "FFB6C1";
    const string MEDIUMVIOLETRED       = "C71585";
    const string SLATEGREY             = "708090";
    const string RED                   = "FF0000";
    const string DEEPPINK              = "FF1493";
    const string LIMEGREEN             = "32CD32";
    const string DARKMAGENTA           = "8B008B";
    const string PALEGOLDENROD         = "EEE8AA";
    const string PLUM                  = "DDA0DD";
    const string TURQUOISE             = "40E0D0";
    const string LIGHTGREY             = "D3D3D3";
    const string LIGHTGOLDENRODYELLOW  = "FAFAD2";
    const string DARKGOLDENROD         = "B8860B";
    const string LAVENDER              = "E6E6FA";
    const string MAROON                = "800000";
    const string YELLOWGREEN           = "9ACD32";
    const string SANDYBROWN            = "F4A460";
    const string THISTLE               = "D8BFD8";
    const string VIOLET                = "EE82EE";
    const string NAVY                  = "000080";
    const string MAGENTA               = "FF00FF";
    const string DIMGREY               = "696969";
    const string TAN                   = "D2B48C";
    const string ROSYBROWN             = "BC8F8F";
    const string OLIVEDRAB             = "6B8E23";
    const string BLUE                  = "0000FF";
    const string LIGHTBLUE             = "ADD8E6";
    const string GHOSTWHITE            = "F8F8FF";
    const string HONEYDEW              = "F0FFF0";
    const string CORNFLOWERBLUE        = "6495ED";
    const string SLATEBLUE             = "6A5ACD";
    const string LINEN                 = "FAF0E6";
    const string DARKBLUE              = "00008B";
    const string POWDERBLUE            = "B0E0E6";
    const string SEAGREEN              = "2E8B57";
    const string DARKKHAKI             = "BDB76B";
    const string SNOW                  = "FFFAFA";
    const string SIENNA                = "A0522D";
    const string MEDIUMBLUE            = "0000CD";
    const string ROYALBLUE             = "4169E1";
    const string LIGHTCYAN             = "E0FFFF";
    const string GREEN                 = "008000";
    const string MEDIUMPURPLE          = "9370DB";
    const string MIDNIGHTBLUE          = "191970";
    const string CORNSILK              = "FFF8DC";
    const string PALETURQUOISE         = "AFEEEE";
    const string BISQUE                = "FFE4C4";
    const string SLATEGRAY             = "708090";
    const string DARKCYAN              = "008B8B";
    const string KHAKI                 = "F0E68C";
    const string WHEAT                 = "F5DEB3";
    const string TEAL                  = "008080";
    const string DARKORCHID            = "9932CC";
    const string DEEPSKYBLUE           = "00BFFF";
    const string SALMON                = "FA8072";
    const string DARKRED               = "8B0000";
    const string STEELBLUE             = "4682B4";
    const string PALEVIOLETRED         = "DB7093";
    const string LIGHTSLATEGRAY        = "778899";
    const string ALICEBLUE             = "F0F8FF";
    const string LIGHTSLATEGREY        = "778899";
    const string LIGHTGREEN            = "90EE90";
    const string ORCHID                = "DA70D6";
    const string GAINSBORO             = "DCDCDC";
    const string MEDIUMSEAGREEN        = "3CB371";
    const string LIGHTGRAY             = "D3D3D3";
    const string MEDIUMTURQUOISE       = "48D1CC";
    const string LEMONCHIFFON          = "FFFACD";
    const string CADETBLUE             = "5F9EA0";
    const string LIGHTYELLOW           = "FFFFE0";
    const string LAVENDERBLUSH         = "FFF0F5";
    const string CORAL                 = "FF7F50";
    const string PURPLE                = "800080";
    const string AQUA                  = "00FFFF";
    const string WHITESMOKE            = "F5F5F5";
    const string MEDIUMSLATEBLUE       = "7B68EE";
    const string DARKORANGE            = "FF8C00";
    const string MEDIUMAQUAMARINE      = "66CDAA";
    const string DARKSALMON            = "E9967A";
    const string BEIGE                 = "F5F5DC";
    const string BLUEVIOLET            = "8A2BE2";
    const string AZURE                 = "F0FFFF";
    const string LIGHTSTEELBLUE        = "B0C4DE";
    const string OLDLACE               = "FDF5E6";
    const string REBECCAPURPLE         = "663399";
}

#endif /* Chromatics_hpp */
