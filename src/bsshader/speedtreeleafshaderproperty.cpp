
// src/bsshader/speedtreeleafshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/speedtreeleafshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiRefObject.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

struct FUN_00bb33c0 : NiRefObject
{
    int m_kPointB;
    unsigned short m_iThirdValue;

    FUN_00bb33c0();
    virtual ~FUN_00bb33c0();
};

NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement(reinterpret_cast<volatile long*>(&ms_lObjectCount));
}

// @fnv 0x00bb33c0
FUN_00bb33c0::FUN_00bb33c0()
{
    m_kPointB = 0;
    m_iThirdValue = 0;
}
