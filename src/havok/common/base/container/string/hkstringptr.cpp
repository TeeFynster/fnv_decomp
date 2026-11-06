
// src/havok/common/base/container/string/hkstringptr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstringptr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkOstream.h"
#include "../../../../../../include/hkStreamWriter.h"
#include "../../../../../../include/hkStringPtr.h"

int __cdecl FUN_00cb10d0(const char* s);
char* __cdecl AllocateWithHeader(void* alloc, int size);
void __cdecl FUN_00cb1090(char* dst, const char* src);

// @fnv 0x00cb1160
char* __cdecl FUN_00cb1160(const char* aString, void* apAllocator)
{
    char* p = AllocateWithHeader(apAllocator, FUN_00cb10d0(aString) + 1);
    FUN_00cb1090(p, aString);
    return p;
}

extern void* g_01268358;

// @fnv 0x00cb0a60
hkStringPtr::hkStringPtr() throw()
{
    m_pcText = static_cast<const char*>(g_01268358);
}

int __cdecl FUN_00c856c0(int, int);
// @fnv 0x00cb1190
int __cdecl CallSwappedArgs(unsigned int arg0, unsigned int arg1)
{
    unsigned int callResult0 = (unsigned int)FUN_00c856c0((int)arg1, (int)arg0);
    return (int)callResult0;
}

int __cdecl FUN_00cb10d0(const char* s);

// Writes the string s to w, or the literal "(null)" when s is null.
// @fnv 0x00cc0080
static __declspec(noinline) void FUN_00cc0080(hkStreamWriter* apWriter, const char* apString)
{
    if (apString)
        apWriter->write(apString, FUN_00cb10d0(apString));
    else
        apWriter->write("(null)", 6);
}

volatile int g_wcc0;
volatile int g_scc0;
void CallTarget_cc0080()
{
    hkStreamWriter* w = (hkStreamWriter*)g_wcc0;
    const char* s = (const char*)g_scc0;
    FUN_00cc0080(w, s);
    FUN_00cc0080(w, s);
}

// @fnv 0x00cc01c0
__declspec(nothrow) hkOstream& hkOstream::FUN_00cc01c0(const char* text) throw()
{
    FUN_00cc0080(m_pStreamWriter, text);
    return *this;
}

namespace fnv_00cb11b0 {
// unit_ff4bdaca3856.cpp

extern "C"
{
    void* __cdecl FUN_00cb10d0(void* p);
    void* __cdecl AllocateWithHeader(void* p, int n);
    void* __cdecl CopyIfNonEmpty(void* p, void* q, int n);
}

// Copies up to n2 characters from p1 into a new null-terminated buffer allocated from p3 and returns it.
// @fnv 0x00cb11b0
void* __cdecl FUN_00cb11b0(void* apSrc, int anMaxLen, void* p3)
{
    int len = (int)FUN_00cb10d0(apSrc);
    if (len > anMaxLen)
        len = anMaxLen;

    void* buf = AllocateWithHeader(p3, len + 1);
    CopyIfNonEmpty(buf, apSrc, len);
    ((char*)buf)[len] = 0;
    return buf;
}
}  // namespace fnv_00cb11b0
