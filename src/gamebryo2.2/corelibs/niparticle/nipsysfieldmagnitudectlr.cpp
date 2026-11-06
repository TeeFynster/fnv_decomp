// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmagnitudectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmagnitudectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

struct NiPSysFieldMagnitudeCtlr : NiPSysModifierFloatCtlr
{
    void __thiscall FUN_00c29ea0(float& fValue);
};

// @fnv 0x00c29ea0
void __thiscall NiPSysFieldMagnitudeCtlr::FUN_00c29ea0(float& fValue)
{
    fValue = *(float*)((char*)m_pkTargetModifier + 0x1C);
}

extern "C" void* g_01202718;

// @fnv 0x00c2b140
void* __cdecl FUN_00c2b140()
{
    return &g_01202718;
}

struct NiPSysFieldMagnitudeCtlr_shell : NiPSysFieldMagnitudeCtlr
{
    void __thiscall FUN_00c2b150(float value);
};

// @fnv 0x00c2b150
void __thiscall NiPSysFieldMagnitudeCtlr_shell::FUN_00c2b150(float value)
{
    ((float*)m_pkTargetModifier)[7] = value;
}

void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl FUN_00a7d330(const char*);
// @fnv 0x00c2b1b0
void __stdcall FUN_00c2b1b0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pcStr = FUN_00a7d330((const char*)g_01202718);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiCap = pkStrings->m_usMaxSize;
    if (uiSize >= uiCap)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiSize);
    pkStrings->SetAt(uiSize, pcStr);
}

struct Base
{
    int unk04;
    Base() throw();
    virtual void vf();
};

struct Node : Base
{
    int unk08[14];
    static void* operator new(unsigned int size) throw();
    Node() throw()
    {}
    virtual void vf();
};

struct Owner
{
    void FUN_00c32de0(Node* node, int arg);
    Node* FUN_00c2b160(int arg);
};

// @fnv 0x00c2b160
Node* Owner::FUN_00c2b160(int arg)
{
    Node* node = new Node();
    FUN_00c32de0(node, arg);
    return node;
}
