
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
    UnkRet* FUN_00c85750();
};
extern "C" BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl CallSwappedArgs(BSAudio*, int);
void __cdecl FUN_00cb13c0(int a);
double __cdecl FUN_00ecdf2d(unsigned int value, int mode);
float __cdecl ConvertToFloat(unsigned int value);
hkBool StartsWith(const char* str, const char* prefix);
int __cdecl FUN_00cb10d0(const char* text);
bool* __cdecl EndsWith(bool* result, const char* text, const char* suffix);
BSAudio* FUN_00c85750();
void __cdecl FUN_00cb11b0(int a, int b, int c);
void __cdecl FUN_00cb13e0(int a, int b);
void __cdecl FUN_00cb1090(char* dest, const char* src);
int __cdecl FUN_00cb1290(const unsigned char* a, const unsigned char* b, unsigned int n);
const char* __cdecl FUN_00cb1150(const char* str, int c);
int __cdecl FUN_00cb1390(const char* str, char c);
int __cdecl FUN_00cb1160(int a, int b);
void __cdecl FUN_00cb1410(int a);

struct Cls;

struct BoolGuard
{
    bool flag;
    int __thiscall Get(Cls* owner, int value);
};

struct Cls
{
    void __thiscall Other(int value);
    void FUN_00626420(int value);
};

// @fnv 0x00626420
void Cls::FUN_00626420(int value)
{
    BoolGuard g = {};
    Other(g.Get(this, value));
}
