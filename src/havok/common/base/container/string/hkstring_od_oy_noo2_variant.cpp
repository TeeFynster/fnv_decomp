
// src/havok/common/base/container/string/hkstring_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/havok/common/base/container/string/hkstring.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/container/string/hkstring.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstring.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkBool.h"

extern "C" void __cdecl FUN_00ecc7b0(char* dest, const char* src, int count);
void __cdecl CopyIfNonEmpty(char* dest, const char* src, int count);
void __cdecl FUN_00ec8d33(int a, int b, int c);
void __cdecl CallWithZeroMiddleArg(int a, int b);
struct UnkRet
{
    void* p;
};
struct UnkHolder
{
    UnkRet* hkMemoryRouter_getInstance();
};
extern "C" BSAudio* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl CallSwappedArgs(BSAudio*, int);
void __cdecl hkString_strFree(int a);
double __cdecl FUN_00ecdf2d(unsigned int value, int mode);
float __cdecl ConvertToFloat(unsigned int value);
hkBool StartsWith(const char* str, const char* prefix);
int __cdecl hkString_strLen(const char* text);
bool* __cdecl EndsWith(bool* result, const char* text, const char* suffix);
BSAudio* hkMemoryRouter_getInstance();
void __cdecl hkString_strNdup(int a, int b, int c);
void __cdecl hkString_strNdup_00cb13e0(int a, int b);
void __cdecl hkString_strCpy(char* dest, const char* src);
int __cdecl hkString_memCmp(const unsigned char* a, const unsigned char* b, unsigned int n);
const char* __cdecl hkString_strRchr(const char* str, int c);
int __cdecl hkString_lastIndexOf(const char* str, char c);
int __cdecl hkString_strDup(int a, int b);
void __cdecl hkString_strDup_00cb1410(int a);

struct Cls;

struct BoolGuard
{
    bool flag;
    int __thiscall Get(Cls* owner, int value);
};

struct Cls
{
    void __thiscall Other(int value);
    void UpdateFields_00626420(int value);
};

// @fnv 0x00626420
// src: GUESS 0x00626420 (confidence: low)
void Cls::UpdateFields_00626420(int value)
{
    BoolGuard g = {};
    Other(g.Get(this, value));
}
