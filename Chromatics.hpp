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
#include "ColorRGB.hpp"
#include "ColorRGBA.hpp"
#include "ColorCMYK.hpp"
#include "ColorHSL.hpp"
#include "ColorHSV.hpp"

namespace Chromatic {
    const std::string INDIGO                = "4B0082";
    const std::string GOLD                  = "FFD700";
    const std::string HOTPINK               = "FF69B4";
    const std::string FIREBRICK             = "B22222";
    const std::string INDIANRED             = "CD5C5C";
    const std::string YELLOW                = "FFFF00";
    const std::string MISTYROSE             = "FFE4E1";
    const std::string DARKOLIVEGREEN        = "556B2F";
    const std::string OLIVE                 = "808000";
    const std::string DARKSEAGREEN          = "8FBC8F";
    const std::string PINK                  = "FFC0CB";
    const std::string TOMATO                = "FF6347";
    const std::string LIGHTCORAL            = "F08080";
    const std::string ORANGERED             = "FF4500";
    const std::string NAVAJOWHITE           = "FFDEAD";
    const std::string LIME                  = "00FF00";
    const std::string PALEGREEN             = "98FB98";
    const std::string DARKSLATEGREY         = "2F4F4F";
    const std::string GREENYELLOW           = "ADFF2F";
    const std::string BURLYWOOD             = "DEB887";
    const std::string SEASHELL              = "FFF5EE";
    const std::string MEDIUMSPRINGGREEN     = "00FA9A";
    const std::string FUCHSIA               = "FF00FF";
    const std::string PAPAYAWHIP            = "FFEFD5";
    const std::string BLANCHEDALMOND        = "FFEBCD";
    const std::string CHARTREUSE            = "7FFF00";
    const std::string DIMGRAY               = "696969";
    const std::string BLACK                 = "000000";
    const std::string PEACHPUFF             = "FFDAB9";
    const std::string SPRINGGREEN           = "00FF7F";
    const std::string AQUAMARINE            = "7FFFD4";
    const std::string WHITE                 = "FFFFFF";
    const std::string ORANGE                = "FFA500";
    const std::string LIGHTSALMON           = "FFA07A";
    const std::string DARKSLATEGRAY         = "2F4F4F";
    const std::string BROWN                 = "A52A2A";
    const std::string IVORY                 = "FFFFF0";
    const std::string DODGERBLUE            = "1E90FF";
    const std::string PERU                  = "CD853F";
    const std::string LAWNGREEN             = "7CFC00";
    const std::string CHOCOLATE             = "D2691E";
    const std::string CRIMSON               = "DC143C";
    const std::string FORESTGREEN           = "228B22";
    const std::string DARKGREY              = "A9A9A9";
    const std::string LIGHTSEAGREEN         = "20B2AA";
    const std::string CYAN                  = "00FFFF";
    const std::string MINTCREAM             = "F5FFFA";
    const std::string SILVER                = "C0C0C0";
    const std::string ANTIQUEWHITE          = "FAEBD7";
    const std::string MEDIUMORCHID          = "BA55D3";
    const std::string SKYBLUE               = "87CEEB";
    const std::string GRAY                  = "808080";
    const std::string DARKTURQUOISE         = "00CED1";
    const std::string GOLDENROD             = "DAA520";
    const std::string DARKGREEN             = "006400";
    const std::string FLORALWHITE           = "FFFAF0";
    const std::string DARKVIOLET            = "9400D3";
    const std::string DARKGRAY              = "A9A9A9";
    const std::string MOCCASIN              = "FFE4B5";
    const std::string SADDLEBROWN           = "8B4513";
    const std::string GREY                  = "808080";
    const std::string DARKSLATEBLUE         = "483D8B";
    const std::string LIGHTSKYBLUE          = "87CEFA";
    const std::string LIGHTPINK             = "FFB6C1";
    const std::string MEDIUMVIOLETRED       = "C71585";
    const std::string SLATEGREY             = "708090";
    const std::string RED                   = "FF0000";
    const std::string DEEPPINK              = "FF1493";
    const std::string LIMEGREEN             = "32CD32";
    const std::string DARKMAGENTA           = "8B008B";
    const std::string PALEGOLDENROD         = "EEE8AA";
    const std::string PLUM                  = "DDA0DD";
    const std::string TURQUOISE             = "40E0D0";
    const std::string LIGHTGREY             = "D3D3D3";
    const std::string LIGHTGOLDENRODYELLOW  = "FAFAD2";
    const std::string DARKGOLDENROD         = "B8860B";
    const std::string LAVENDER              = "E6E6FA";
    const std::string MAROON                = "800000";
    const std::string YELLOWGREEN           = "9ACD32";
    const std::string SANDYBROWN            = "F4A460";
    const std::string THISTLE               = "D8BFD8";
    const std::string VIOLET                = "EE82EE";
    const std::string NAVY                  = "000080";
    const std::string MAGENTA               = "FF00FF";
    const std::string DIMGREY               = "696969";
    const std::string TAN                   = "D2B48C";
    const std::string ROSYBROWN             = "BC8F8F";
    const std::string OLIVEDRAB             = "6B8E23";
    const std::string BLUE                  = "0000FF";
    const std::string LIGHTBLUE             = "ADD8E6";
    const std::string GHOSTWHITE            = "F8F8FF";
    const std::string HONEYDEW              = "F0FFF0";
    const std::string CORNFLOWERBLUE        = "6495ED";
    const std::string SLATEBLUE             = "6A5ACD";
    const std::string LINEN                 = "FAF0E6";
    const std::string DARKBLUE              = "00008B";
    const std::string POWDERBLUE            = "B0E0E6";
    const std::string SEAGREEN              = "2E8B57";
    const std::string DARKKHAKI             = "BDB76B";
    const std::string SNOW                  = "FFFAFA";
    const std::string SIENNA                = "A0522D";
    const std::string MEDIUMBLUE            = "0000CD";
    const std::string ROYALBLUE             = "4169E1";
    const std::string LIGHTCYAN             = "E0FFFF";
    const std::string GREEN                 = "008000";
    const std::string MEDIUMPURPLE          = "9370DB";
    const std::string MIDNIGHTBLUE          = "191970";
    const std::string CORNSILK              = "FFF8DC";
    const std::string PALETURQUOISE         = "AFEEEE";
    const std::string BISQUE                = "FFE4C4";
    const std::string SLATEGRAY             = "708090";
    const std::string DARKCYAN              = "008B8B";
    const std::string KHAKI                 = "F0E68C";
    const std::string WHEAT                 = "F5DEB3";
    const std::string TEAL                  = "008080";
    const std::string DARKORCHID            = "9932CC";
    const std::string DEEPSKYBLUE           = "00BFFF";
    const std::string SALMON                = "FA8072";
    const std::string DARKRED               = "8B0000";
    const std::string STEELBLUE             = "4682B4";
    const std::string PALEVIOLETRED         = "DB7093";
    const std::string LIGHTSLATEGRAY        = "778899";
    const std::string ALICEBLUE             = "F0F8FF";
    const std::string LIGHTSLATEGREY        = "778899";
    const std::string LIGHTGREEN            = "90EE90";
    const std::string ORCHID                = "DA70D6";
    const std::string GAINSBORO             = "DCDCDC";
    const std::string MEDIUMSEAGREEN        = "3CB371";
    const std::string LIGHTGRAY             = "D3D3D3";
    const std::string MEDIUMTURQUOISE       = "48D1CC";
    const std::string LEMONCHIFFON          = "FFFACD";
    const std::string CADETBLUE             = "5F9EA0";
    const std::string LIGHTYELLOW           = "FFFFE0";
    const std::string LAVENDERBLUSH         = "FFF0F5";
    const std::string CORAL                 = "FF7F50";
    const std::string PURPLE                = "800080";
    const std::string AQUA                  = "00FFFF";
    const std::string WHITESMOKE            = "F5F5F5";
    const std::string MEDIUMSLATEBLUE       = "7B68EE";
    const std::string DARKORANGE            = "FF8C00";
    const std::string MEDIUMAQUAMARINE      = "66CDAA";
    const std::string DARKSALMON            = "E9967A";
    const std::string BEIGE                 = "F5F5DC";
    const std::string BLUEVIOLET            = "8A2BE2";
    const std::string AZURE                 = "F0FFFF";
    const std::string LIGHTSTEELBLUE        = "B0C4DE";
    const std::string OLDLACE               = "FDF5E6";
    const std::string REBECCAPURPLE         = "663399";
}

#endif /* Chromatics_hpp */
