#include "../../../../include/NiSCMExtraData.h"
#include "../../../../include/NiObjectNET.h"

// src/gamebryo2.2/corelibs/nimain/niscmextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niscmextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int g_01270908;

// @fnv 0x00ee89a0
// src: COMMUNITY 0x00ee89a0
int* __cdecl NiSCMExtraData_GetRTTI()
{
    return &g_01270908;
}

extern int DAT_0110129c;
void __cdecl NiFreeAlias(void*);
void __cdecl operator delete(void*, unsigned int);
// @fnv 0x00ee89b0
void* NiSCMExtraData::Destroy(unsigned int auiFlags)
{
    void* tmp = m_24;
    *(int*)this = (int)&DAT_0110129c;
    NiFreeAlias(tmp);
    NiFreeAlias(m_2c);
    NiExtraData::DestroyFields_00a7b300();
    if (auiFlags & 1)
        ::operator delete(this, 0x30);
    return this;
}

void* __cdecl _NiMalloc_00aa1070(int);

// The shared header has no initialization method or named fields for these counts.
// @fnv 0x00ee8910
// src: GUESS 0x00ee8910 (confidence: low)
NiSCMExtraData* __fastcall NiSCMExtraData_UpdateState_00ee8910(NiSCMExtraData* self, void*, int a, int aiCountA, int aiCountB)
{
    self->NiExtraData::FUN_00a7b2e0();
    *reinterpret_cast<void**>(self) = &DAT_0110129c;
    reinterpret_cast<NiObjectNET*>(self)->SetName(*reinterpret_cast<const NiFixedString*>(a));
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x0c) = aiCountA;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x18) = 0;
    if (aiCountA != 0)
    {
        self->m_24 = _NiMalloc_00aa1070(aiCountA * 8);
    }
    else
    {
        self->m_24 = 0;
    }
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14) = aiCountB;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x20) = 0;
    if (aiCountB != 0)
    {
        self->m_2c = _NiMalloc_00aa1070(aiCountB * 8);
    }
    else
    {
        self->m_2c = 0;
    }
    return self;
}
