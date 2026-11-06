#pragma once

typedef float hkReal;

// Havok packed colours: 0xAARRGGBB ints passed to the debug display calls. Only the named colours our units pass
// are listed (the exe has just the constants); the values are the standard web colour values.
class hkColor  // src: HAVOK_SRC (class and colour names)
{
  public:
    enum ExtendedColors  // src: HAVOK_SRC
    {
        GREEN = 0xFF008000,
        ORANGE = 0xFFFFA500,
        RED = 0xFFFF0000,
        ROSYBROWN = 0xFFBC8F8F,
        WHITE = 0xFFFFFFFF,
        WHITESMOKE = 0xFFF5F5F5,
        YELLOW = 0xFFFFFF00,
        YELLOWGREEN = 0xFF9ACD32,
    };

    // 8-bit channels -> packed colour; alpha opaque unless given
    static int __cdecl rgbFromChars(unsigned char ucR, unsigned char ucG, unsigned char ucB, unsigned char ucA = 0xff);
    // float channels in [0,1] -> packed colour (body in src/havok/common/base/types/color/hkcolor.cpp)
    static int __cdecl PackColorBigEndian(const hkReal fR, const hkReal fG, const hkReal fB, const hkReal fA = 1.0f);
};
