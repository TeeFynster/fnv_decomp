
// src/fallout/interface/forenderedmenu_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/forenderedmenu.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "forenderedmenu_decls.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/NP.h"
const char kRenderedMenuBurstSound[] = "UIPipBoyStatic";
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);

struct SpawnedRef
{
    virtual void vfn00();
    virtual void Free();
    long m_iObjectReferenceCount;
};

struct SpawnedSubBase
{
    virtual void vfnBase();
    SpawnedSubBase(unsigned int a, unsigned int b);
};

struct SpawnedSub : SpawnedSubBase
{
    unsigned int unk04;
    unsigned int unk08;
    volatile unsigned int unk0c;
    unsigned int unk10;

    SpawnedSub(unsigned int a, unsigned int b) : SpawnedSubBase(a, b)
    {
        unk10 = 0;
    }
};

class FUN_00e98f20
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    volatile unsigned int unk0c;
    volatile unsigned char unk10;
    volatile unsigned char unk11;
    SpawnedRef* m_pReference;
    SpawnedSub m_sub;
    unsigned int unk2c;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;

    FUN_00e98f20(unsigned int a, unsigned int b);
};

// @fnv 0x00e98f20
FUN_00e98f20::FUN_00e98f20(unsigned int a, unsigned int b) : m_pReference(0), m_sub(a, b)
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 1;
    unk0c = 1;
    unk10 = 1;
    unk11 = 0;
    SpawnedRef* p = *(SpawnedRef* volatile*)&m_pReference;
    if (p != 0)
    {
        if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
        {
            p->Free();
        }
        m_pReference = 0;
    }
    unk30 = 0;
    unk31 = 0;
    unk32 = 0;
    unk33 = 0;
    unk2c = 0;
}
