
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00e63c60: the skeleton of src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp
// with declarations corrected to what the original code does (unit: void __cdecl FUN_00e63c60(bool *); -> int __cdecl FUN_00e63c60(bool *);). Move the function to its real unit once
// that unit declares it this way.

// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkaSplineCompressedAnimation.h"

extern char DAT_010c3aa0[];
extern void __cdecl _hkErrorMessage(const char* message);
extern int __cdecl Hksystemtime_Time64_Thunk();
extern "C" void _ReadWriteBarrier(void);

static int hexDigit(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

static char* findDot(char* p)
{
    while (p)
    {
        if (!*p || *p == '.')
        {
            _ReadWriteBarrier();
            break;
        }
        ++p;
    }
    return p;
}

static void invalidKey()
{
    _hkErrorMessage("Product:hka Key Code is invalid.\nPlease contact Havok.com\nNo simulation possible.");
}

// @fnv 0x00e63c60
// src: XBOX_PDB 0x00e63c60
int __cdecl hkaProcessFlyingColors(bool* valid)
{
    *valid = false;
    int status = 0;
    unsigned long second;
    second = 0xfffffffful;
    int first;
    first = -1;
    char* p;
    p = DAT_010c3aa0 + 2;
    int digit = hexDigit(*p++);
    while (digit >= 0)
    {
        first = (first << 4) + digit;
        digit = hexDigit(*p++);
    }
    p += 2;
    digit = hexDigit(*p++);
    while (digit >= 0)
    {
        second = (second << 4) + digit;
        digit = hexDigit(*p++);
    }

    unsigned char expires = (unsigned char)(((unsigned int)first >> 31) & 1);

    char* dot = findDot(DAT_010c3aa0);
    if (!dot)
    {
        invalidKey();
        return 1;
    }
    dot = findDot(dot + 1);
    if (!dot)
    {
        invalidKey();
        return 1;
    }
    ++dot;

    if (expires)
    {
        first = (first ^ 0xd4efe34a) & 0x7fffffff;
        int now = Hksystemtime_Time64_Thunk() >> 8;
        int remaining = first - now;
        if (first < now || remaining > 0x96c99)
        {
            _hkErrorMessage(
                "Product:hka Key Code has expired .\nPlease contact Havok.com for an extension.\nNo simulation possible.");
            return 2;
        }
        if (remaining < 0xd2f)
            status = 3;
    }
    else
    {
        int hash = 0;
        while (*dot)
        {
            hash = hash * 23 + *++dot;
        }
        hash = (hash ^ 0xd4efe34a) & 0x7fffffff;
        if (second != hash)
        {
            invalidKey();
            return 1;
        }
    }
    *valid = true;
    return status;
}
