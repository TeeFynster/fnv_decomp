// src/havok/common/base/math/types/hkmathtypes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/types/hkmathtypes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00cbfe20
// src: HAVOK_LIB 0x00cbfe20
int __cdecl hkMath_hkFloorToInt(float afValue)
{
    union fiu
    {
        float f;
        int i;
        unsigned u;
    };

    fiu convert;
    convert.f = afValue;

    int fracMask = 0xff800000;

    unsigned int exp = convert.u & 0x7f800000;
    exp >>= 0x017;
    exp -= 0x07f;

    int lshift = int(exp) - 0x17;
    int rshift = 0x17 - int(exp);

    int sign = (lshift - 1) >> 0x01f;
    lshift &= ~sign;
    rshift &= sign;

    int nexp = (convert.i) & 0x7fffffff;
    nexp = (nexp - 1) >> 0x01f;
    convert.i &= ~nexp;

    fracMask >>= (0x17 & sign) - rshift;
    fracMask |= ~sign;

    sign = (int)(convert.u & 0x80000000);
    sign >>= 0x01f;

    int iExpSign = int(exp) >> 0x01f;
    int iNotExpSign = ~iExpSign;
    int iHalfBit = 0x800000 >> exp;
    int iRoundBit = ~((~fracMask & convert.i) - 1) & iHalfBit;
    int iMantissa = (iRoundBit & sign) + (iNotExpSign & convert.i);
    int y = ((iMantissa & 0x7fffff) | (((iExpSign & sign) | iNotExpSign) & 0x800000)) & fracMask;
    int res = (y << 0x01) - 1;
    res |= sign;
    res -= y;
    res += 1;
    res >>= rshift;
    res <<= lshift;
    return res;
}

// Converts a float to int via bit manipulation, handling exponent, sign, and fractional truncation.
// @fnv 0x00cbfef0
// src: HAVOK_LIB 0x00cbfef0
int __cdecl hkMath_hkFloatToInt(float value)
{
    union
    {
        float f;
        int i;
        unsigned u;
    } convert;
    convert.f = value;
    int fracMask = 0xff800000;
    unsigned int exp = convert.u & 0x7f800000;
    exp >>= 23;
    exp -= 127;
    int lshift = int(exp) - 23;
    int rshift = 23 - int(exp);
    int sign = (lshift - 1) >> 31;
    lshift &= ~sign;
    rshift &= sign;
    int nexp = convert.i & 0x7fffffff;
    nexp = (nexp - 1) >> 31;
    convert.i &= ~nexp;
    fracMask >>= (23 & sign) - rshift;
    fracMask |= ~sign;
    sign = convert.i >> 31;
    convert.i &= 0x7fffff;
    convert.i |= 0x800000;
    convert.i &= fracMask;
    int y = convert.i;
    convert.i = (convert.i << 1) - 1;
    convert.i |= sign;
    convert.i -= y;
    convert.i += 1;
    convert.i &= ~(int(exp) >> 31);
    convert.i >>= rshift;
    convert.i <<= lshift;
    return convert.i;
}
