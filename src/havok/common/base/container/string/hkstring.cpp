
// src/havok/common/base/container/string/hkstring.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstring.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkBool.h"

extern "C" void __cdecl FUN_00ecc7b0(char* dest, const char* src, int count);

// @fnv 0x00cb10b0
void __cdecl CopyIfNonEmpty(char* dest, const char* src, int count)
{
    if (count)
        FUN_00ecc7b0(dest, src, count);
}

void __cdecl FUN_00ec8d33(int a, int b, int c);

// @fnv 0x00cb10f0
void __cdecl CallWithZeroMiddleArg(int aiFirst, int aiThird)
{
    FUN_00ec8d33(aiFirst, 0, aiThird);
}

extern "C" BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl CallSwappedArgs(BSAudio*, int);

// @fnv 0x00cb13c0
void __cdecl FUN_00cb13c0(int aiAudio)
{
    CallSwappedArgs((BSAudio*)aiAudio, (int)FUN_00c85750()->pListener);
}

double __cdecl FUN_00ecdf2d(unsigned int value, int mode);
// @fnv 0x00cb1110
float __cdecl ConvertToFloat(unsigned int value)
{
    return FUN_00ecdf2d(value, 0);
}

// Returns true if str begins with prefix by comparing characters until the prefix's null terminator.
// @fnv 0x00cb1310
hkBool StartsWith(const char* acString, const char* prefix)
{
    for (int i = 0; prefix[i] != 0; ++i)
    {
        if (acString[i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}

int __cdecl FUN_00cb10d0(const char* text);

// Compares the tail of text against suffix and stores whether text ends with suffix into result.
// @fnv 0x00cb1340
bool* __cdecl EndsWith(bool* result, const char* text, const char* suffix)
{
    int textLength = FUN_00cb10d0(text);
    int suffixLength = FUN_00cb10d0(suffix);
    if (textLength < suffixLength)
    {
        *result = false;
        return result;
    }
    int offset = textLength - suffixLength;
    for (int i = 0; i < suffixLength; ++i)
    {
        if (text[offset + i] != suffix[i])
        {
            *result = false;
            return result;
        }
    }
    *result = true;
    return result;
}


// hkMemoryRouter (Havok 7.1 Common/Base/Memory/Router/hkMemoryRouter.h), 0x24 bytes: the ctor 0x00c85770 clears
// m_stack (3 words) and the temp/heap/debug/solver/global allocators, not m_userData. (The shared hkMemoryRouter.h
// stand-in models only its first 0x14 bytes.)
#include "../../../../../../include/hkMemoryRouter.h"
void __cdecl FUN_00cb11b0(int a, int b, int c);

// Reads pListener from the BSAudio returned by FUN_00c85750 and passes it with a and b to FUN_00cb11b0.
// @fnv 0x00cb13e0
void __cdecl FUN_00cb13e0(int aiArg1, int aiArg2)
{
    hkMemoryRouter router;
    int c = (int)FUN_00c85750()->pListener;
    FUN_00cb11b0(aiArg1, aiArg2, c);
}

// @fnv 0x00cb1090
void __cdecl FUN_00cb1090(char* pcDest, const char* pcSrc)
{
    const char* s = pcSrc;
    char c;
    char* d = pcDest;
    int iOffset = d - s;
    do
    {
        c = *s;
        *(char*)(s + iOffset) = c;
        s++;
    } while (c);
}

// Compares two byte buffers over n bytes, four at a time, returning -1, 1 or 0 based on the first differing byte.
// @fnv 0x00cb1290
int __cdecl FUN_00cb1290(const unsigned char* pLeft, const unsigned char* pRight, unsigned int uiLength)
{
    int d = 0;
    while (uiLength >= 4)
    {
        if (*(const unsigned int*)pLeft != *(const unsigned int*)pRight)
        {
            goto bytes;
        }
        uiLength -= 4;
        pRight += 4;
        pLeft += 4;
    }
    if (uiLength != 0)
    {
    bytes:
        d = (int)pLeft[0] - (int)pRight[0];
        if (d == 0 && uiLength > 1)
        {
            d = (int)pLeft[1] - (int)pRight[1];
            if (d == 0 && uiLength > 2)
            {
                d = (int)pLeft[2] - (int)pRight[2];
                if (d == 0 && uiLength > 3)
                {
                    d = (int)pLeft[3] - (int)pRight[3];
                    return (d >> 31) | 1;
                }
            }
        }
        if (d != 0)
        {
            return (d >> 31) | 1;
        }
    }
    return 0;
}

const char* __cdecl FUN_00cb1150(const char* str, int c);

// @fnv 0x00cb1390
int __cdecl FUN_00cb1390(const char* str, char acChar)
{
    const char* p = FUN_00cb1150(str, acChar);
    return p ? (int)(p - str) : -1;
}

int __cdecl FUN_00cb1160(int a, int b);

// Constructs a local hkMemoryRouter, reads pListener from FUN_00c85750()'s result, and passes it with a to FUN_00cb1160.
// @fnv 0x00cb1410
void __cdecl FUN_00cb1410(int aiValue)
{
    hkMemoryRouter buf;
    int r = (int)FUN_00c85750()->pListener;
    FUN_00cb1160(aiValue, r);
}

struct Sink
{
    void FUN_00cb0c50(const char* p, int n);
};

const char* __cdecl FUN_00cb1130(const char* a, const char* b);
int __cdecl FUN_00cb10d0(const char* text);
char* __cdecl FUN_00cb1140(const char* s, int c);

static __declspec(noinline) char* skip(char* p)
{
    while (*p == ' ')
        ++p;
    return p;
}

// Finds needle in hay, skips spaces to an '=', then a quoted string, and passes the quoted text to sink; returns 1 on success, 0 otherwise.
// @fnv 0x00d48440
static __declspec(noinline) int ParseQuotedValue(const char* pText, const char* pKey, Sink* sink)
{
    const char* p = FUN_00cb1130(pText, pKey);
    if (!p)
        return 0;
    p += FUN_00cb10d0(pKey);
    p = skip((char*)p);
    if (*p != '=')
        return 0;
    p = skip((char*)p + 1);
    if (*p != '"')
        return 0;
    ++p;
    char* pQuoteEnd = FUN_00cb1140(p, '"');
    if (!pQuoteEnd)
        return 0;
    sink->FUN_00cb0c50(p, (int)(pQuoteEnd - p));
    return 1;
}

int __cdecl call_it(const char* a, const char* b, Sink* s)
{
    return ParseQuotedValue(a, b, s);
}

void __cdecl FUN_00ecddf1(int a, int b, int c, int d);

// @fnv 0x00cb0f50
void __cdecl FUN_00cb0f50(int a, int b, int c, int d)
{
    FUN_00ecddf1(a, b, c, d);
}

namespace fnv_00cb1140 {
extern "C" char* __cdecl _strchr(const char* s, int c);

// @fnv 0x00cb1140
char* __cdecl FUN_00cb1140(const char* s, int c)
{
    return _strchr(s, c);
}
}  // namespace fnv_00cb1140

namespace fnv_00cb1150 {
extern "C" const char* __cdecl FUN_00ec6e30(const char* str, int c);

// @fnv 0x00cb1150
const char* __cdecl FUN_00cb1150(const char* str, int c)
{
    return FUN_00ec6e30(str, c);
}
}  // namespace fnv_00cb1150

void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

// @fnv 0x00cb1260
void* __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int count)
{
    return _memmove(dst, src, count);
}

void* __cdecl FUN_00ec7230(char* a, const char* b, int c);
// @fnv 0x00cb1270
void* __cdecl FUN_00cb1270(char* a, const char* b, int c)
{
    return FUN_00ec7230(a, b, c);
}

extern void __cdecl FUN_00ec61c0(void* dest, int value, unsigned int count);

// @fnv 0x00cb1280
void __cdecl FUN_00cb1280(void* dest, int value, unsigned int count)
{
    FUN_00ec61c0(dest, value, count);
}

#include <stdarg.h>
extern "C" int __cdecl FUN_00ecddf1(char* buf, unsigned int n, const char* fmt, va_list args);

// @fnv 0x00cb0f60
int __cdecl Vsnprintf(char* buf, int n, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int ret = FUN_00ecddf1(buf, n, fmt, args);
    va_end(args);
    return ret;
}

#include <string.h>
namespace fnv_00cb10d0 {
// @fnv 0x00cb10d0
int __cdecl FUN_00cb10d0(const char* apString)
{
    return (int)strlen(apString);
}
}  // namespace fnv_00cb10d0

namespace fnv_00cb1130 {
// @fnv 0x00cb1130
const char* __cdecl FUN_00cb1130(const char* a, const char* b)
{
    return strstr(a, b);
}
}  // namespace fnv_00cb1130
